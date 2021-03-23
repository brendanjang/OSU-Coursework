import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:journal_app/storage/preference.dart';

import '../../main.dart';

class ThemeSwitch extends StatefulWidget {
  final String title;

  ThemeSwitch({this.title});

  @override
  State<StatefulWidget> createState() {
    return ThemeSwitchState();
  }
}

class ThemeSwitchState extends State<ThemeSwitch> {
  bool isDark = false;

  @override
  void initState() {
    super.initState();
    isDark = PreferenceManager.isDark;
    _loadCounter();
  }

  _loadCounter() async {
    dynamic value = await PreferenceManager.readData(AppStrings.pref_theme_key);
    isDark = value ?? false;
    setState(() {
      isDarkTheme.add(isDark);
    });
  }

  @override
  Widget build(BuildContext context) {
    return SwitchListTile(
        title: Text(widget.title), value: isDark, onChanged: toggleTheme);
  }

  toggleTheme(bool value) async {
    await PreferenceManager.saveData(AppStrings.pref_theme_key, value);
    isDarkTheme.add(value);
    setState(() {
      isDark = value;
    });
  }
}

class JournalDrawer extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Drawer(
      elevation: 10.0,
      child: ListView(
        children: [
          ListTile(
            title: Text("Settings"),
          ),
          Divider(
            thickness: 2,
            color: Colors.grey.withAlpha(200),
            height: 16,
          ),
          ThemeSwitch(
            title: AppStrings.home_switch,
          )
        ],
      ),
    );
  }
}

class JournalAppBar extends StatelessWidget with PreferredSizeWidget {
  final String title;

  JournalAppBar({Key key, this.title}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return AppBar(
      title: Text(title),
      centerTitle: true,
      actions: [
        Builder(
          builder: (context) => IconButton(
            icon: Icon(Icons.settings),
            onPressed: () => Scaffold.of(context).openEndDrawer(),
            tooltip: MaterialLocalizations.of(context).openAppDrawerTooltip,
          ),
        )
      ],
    );
  }

  @override
  Size get preferredSize => Size.fromHeight(50.0);
}

class JournalToolbarScaffold extends StatelessWidget {
  final String title;
  final Widget body;
  final FloatingActionButton floatingActionButton;

  const JournalToolbarScaffold(
      {Key key, this.title, this.body, this.floatingActionButton})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: body,
      endDrawer: JournalDrawer(),
      appBar: JournalAppBar(title: title),
      floatingActionButton: floatingActionButton,
    );
  }
}
