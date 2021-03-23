import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'package:project3/ui/card/card.dart';
import 'package:project3/ui/predictor/predictor.dart';
import 'package:project3/ui/resume/user_resume_details.dart';

class MyHomePage extends StatelessWidget {
  final String title;

  MyHomePage({Key key, this.title}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: new AppBar(
          centerTitle: true,
          title: Text(title),
        ),
        body: new DefaultTabController(
          length: 3,
          child: new Scaffold(
            appBar: new AppBar(
              actions: <Widget>[],
              title: new TabBar(
                labelColor: Colors.white,
                unselectedLabelColor: Colors.white54,
                tabs: [
                  new Tab(icon: new Icon(Icons.face)),
                  new Tab(icon: new Icon(Icons.text_snippet)),
                  new Tab(icon: new Icon(Icons.help_outline)),
                ],
                indicatorColor: Colors.white,
              ),
            ),
            body: TabBarView(
              children: [
                Profile(),
                ResumeDetails(),
                Predictor(),
              ],
            ),
          ),
        ));
  }
}
