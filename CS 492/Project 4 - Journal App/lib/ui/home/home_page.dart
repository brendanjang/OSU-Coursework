import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/_nav/appRoutes.dart';
import 'package:journal_app/models/journal.dart';
import 'package:journal_app/resources/colors.dart';
import 'package:journal_app/storage/preference.dart';
import 'package:journal_app/utils/helper.dart';

typedef Null ItemSelectedCallback(Journal value);
typedef Null JournalListCallback(bool isEmpty);

class MyHomePage extends StatefulWidget {
  final ItemSelectedCallback onItemSelected;
  final JournalListCallback onNonEmptyListReceived;

  MyHomePage({Key key, this.onItemSelected, this.onNonEmptyListReceived})
      : super(key: key);

  @override
  State<StatefulWidget> createState() {
    return MyHomePageState();
  }
}

class MyHomePageState extends State<MyHomePage> {
  List<Journal> journals;

  @override
  void initState() {
    super.initState();
    loadJournals();
  }

  void loadJournals() async {
    journals = await DBManager.instance.queryJournalALL();
    widget.onNonEmptyListReceived(journals == null || journals.length == 0);
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        floatingActionButton: FloatingActionButton(
          onPressed: () {
            addJournal(context);
          },
          child: Icon(Icons.add),
          backgroundColor: AppColors.primary,
        ),
        body: Padding(
          padding: const EdgeInsets.all(8.0),
          child: journals == null
              ? Center(
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                      Icon(
                        Icons.book,
                        color: Colors.black,
                        size: 64.0,
                      ),
                      Text(
                        "Journal",
                        style: Theme.of(context).textTheme.subtitle2,
                      )
                    ],
                  ),
                )
              : ListView.separated(
                  itemBuilder: (context, index) {
                    return InkWell(
                      child: JournalTile(journal: journals[index]),
                      onTap: () {
                        widget.onItemSelected(journals[index]);
                      },
                    );
                  },
                  separatorBuilder: (context, index) => SizedBox(
                        height: 10,
                      ),
                  itemCount: journals.length),
        ));
  }

  void addJournal(BuildContext context) async {
    final journal = await Navigator.pushNamed(context, AppRoute.journal_input);
    if (journal != null) {
      await loadJournals();
    }
  }
}

class JournalTile extends StatelessWidget {
  final Journal journal;

  const JournalTile({Key key, this.journal}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(
          journal.title,
          style: Theme.of(context).textTheme.headline6,
        ),
        Text(
          formattedDayMonthDate(journal.date),
          style: Theme.of(context).textTheme.subtitle2,
        ),
      ],
    );
  }
}
