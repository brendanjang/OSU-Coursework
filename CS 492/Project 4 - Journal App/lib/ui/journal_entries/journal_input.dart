import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/models/journal.dart';
import 'package:journal_app/resources/colors.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:journal_app/storage/preference.dart';
import 'package:journal_app/ui/widgets/widgets.dart';
import 'package:journal_app/utils/helper.dart';

class JournalFrom extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return JournalFromState();
  }
}

class JournalFromState extends State<JournalFrom> {
  final _formKey = GlobalKey<FormState>();

  TextEditingController title = TextEditingController();
  TextEditingController body = TextEditingController();
  TextEditingController rating = TextEditingController();

  @override
  Widget build(BuildContext context) {
    final node = FocusScope.of(context);
    return JournalToolbarScaffold(
        title: AppStrings.journal_title,
        body: Padding(
          padding: const EdgeInsets.all(8.0),
          child: Form(
            key: _formKey,
            child: SingleChildScrollView(
              child: Column(
                children: [
                  SizedBox(height: 10),
                  TextFormField(
                    textInputAction: TextInputAction.next,
                    onEditingComplete: () => node.nextFocus(),
                    controller: title,
                    validator: (value) {
                      if (value.isEmpty) {
                        return AppStrings.title_empty_error;
                      }
                      return null;
                    },
                    decoration: InputDecoration(
                        border: OutlineInputBorder(
                          borderSide:
                              BorderSide(color: Colors.grey, width: 32.0),
                          borderRadius: BorderRadius.circular(5.0),
                        ),
                        focusedBorder: OutlineInputBorder(
                            borderSide: BorderSide(
                                color: AppColors.primary, width: 1.0),
                            borderRadius: BorderRadius.circular(5.0)),
                        labelText: "Title"),
                    onChanged: (value) {},
                  ),
                  SizedBox(height: 10),
                  TextFormField(
                    textInputAction: TextInputAction.next,
                    onEditingComplete: () => node.nextFocus(),
                    controller: body,
                    validator: (value) {
                      if (value.isEmpty) {
                        return AppStrings.body_empty_error;
                      }
                      return null;
                    },
                    decoration: InputDecoration(
                      border: OutlineInputBorder(
                        borderSide: BorderSide(color: Colors.grey, width: 32.0),
                        borderRadius: BorderRadius.circular(5.0),
                      ),
                      focusedBorder: OutlineInputBorder(
                          borderSide:
                              BorderSide(color: AppColors.primary, width: 1.0),
                          borderRadius: BorderRadius.circular(5.0)),
                      labelText: "Body",
                    ),
                    onChanged: (value) {},
                  ),
                  SizedBox(height: 10),
                  TextFormField(
                    textInputAction: TextInputAction.done,
                    onEditingComplete: () => node.unfocus(),
                    controller: rating,
                    validator: (value) {
                      if (!isNumeric(value)) {
                        return AppStrings.rating_value_error;
                      } else {
                        var val = int.parse(value);
                        if (!(val >= 1 && val <= 4)) {
                          return AppStrings.rating_value_error;
                        }
                      }
                      return null;
                    },
                    decoration: InputDecoration(
                      border: OutlineInputBorder(
                        borderSide: BorderSide(color: Colors.grey, width: 32.0),
                        borderRadius: BorderRadius.circular(5.0),
                      ),
                      focusedBorder: OutlineInputBorder(
                          borderSide:
                              BorderSide(color: AppColors.primary, width: 1.0),
                          borderRadius: BorderRadius.circular(5.0)),
                      labelText: "Rating",
                    ),
                    onChanged: (value) {},
                  ),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                    children: [
                      ElevatedButton(
                        onPressed: () {
                          if (_formKey.currentState.validate()) {
                            var journal = Journal.withValues(
                                null,
                                title.text,
                                body.text,
                                int.parse(rating.text),
                                DateTime.now());
                            _insert(journal, context);
                          }
                        },
                        child: Text('Submit'),
                      ),
                      ElevatedButton(
                        onPressed: () {
                          Navigator.pop(
                            context,
                          );
                        },
                        child: Text('Cancel'),
                      )
                    ],
                  )
                ],
              ),
            ),
          ),
        ));
  }

  void _insert(Journal journal, BuildContext context) async {
    var id = await DBManager.instance.insert(journal);
    if (id >= 0) {
      Navigator.pop(context, journal);
    }
  }
}
