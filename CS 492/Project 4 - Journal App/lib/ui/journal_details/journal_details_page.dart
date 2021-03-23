import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/models/journal.dart';
import 'package:journal_app/ui/widgets/widgets.dart';
import 'package:journal_app/utils/helper.dart';

class JournalDetailPage extends StatelessWidget {
  const JournalDetailPage({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final Journal journal = ModalRoute.of(context).settings.arguments;
    return JournalToolbarScaffold(
        title: formattedMonthDate(journal.date),
        body: Padding(
          padding: const EdgeInsets.all(8.0),
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
        ));
  }
}
