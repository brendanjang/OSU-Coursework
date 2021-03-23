import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/models/journal.dart';

class JournalDetailsWidget extends StatelessWidget {
  final Journal journal;

  const JournalDetailsWidget({Key key, @required this.journal})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(
            journal.title,
            style: Theme.of(context).textTheme.headline4,
          ),
          SizedBox(
            height: 6,
          ),
          Text(journal.body),
          SizedBox(
            height: 6,
          ),
          Text("${journal.rating}"),
        ],
      ),
    );
  }
}
