import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class CustomAppBar extends StatelessWidget with PreferredSizeWidget {
  final String title;

  CustomAppBar({Key key, this.title}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return AppBar(
      title: Text(title),
      centerTitle: true,
    );
  }

  @override
  Size get preferredSize => Size.fromHeight(50.0);
}

class AppToolbarScaffold extends StatelessWidget {
  final String title;
  final Widget body;
  final FloatingActionButton floatingActionButton;
  final BottomAppBar bottomAppBar;

  const AppToolbarScaffold(
      {Key key,
      this.title,
      this.body,
      this.floatingActionButton,
      this.bottomAppBar})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: body,
      appBar: CustomAppBar(title: title),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerFloat,
      floatingActionButton: floatingActionButton,
      bottomNavigationBar: bottomAppBar,
    );
  }
}
