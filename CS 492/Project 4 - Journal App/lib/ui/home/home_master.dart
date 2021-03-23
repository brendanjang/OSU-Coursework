import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/_nav/appRoutes.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:journal_app/ui/home/home_page.dart';
import 'package:journal_app/ui/journal_details/journal_details_widget.dart';
import 'package:journal_app/ui/widgets/widgets.dart';

class MasterHome extends StatefulWidget {
  @override
  _MasterHomeState createState() => _MasterHomeState();
}

class _MasterHomeState extends State<MasterHome> {
  var journal;
  var isLargeScreen = false;
  var title = AppStrings.app_welcome;

  @override
  Widget build(BuildContext context) {
    return JournalToolbarScaffold(
      title: title,
      body: OrientationBuilder(
        builder: (context, orientation) {
          if (MediaQuery.of(context).size.width > 600) {
            isLargeScreen = true;
          } else {
            isLargeScreen = false;
          }
          return Row(
            children: [
              Expanded(
                  child: MyHomePage(
                onItemSelected: (value) {
                  journal = value;
                  if (isLargeScreen) {
                    setState(() {});
                  } else {
                    Navigator.pushNamed(context, AppRoute.journal_details,
                        arguments: journal);
                  }
                },
                onNonEmptyListReceived: (isEmpty) {
                  print("value is $isEmpty");
                  title =
                      isEmpty ? AppStrings.app_welcome : AppStrings.app_name;
                  setState(() {});
                },
              )),
              isLargeScreen && journal != null
                  ? Expanded(child: JournalDetailsWidget(journal: journal))
                  : Container(),
            ],
          );
        },
      ),
    );
  }
}
