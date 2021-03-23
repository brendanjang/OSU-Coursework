import 'dart:async';
import 'package:flutter/material.dart';
import 'package:journal_app/_nav/appRoutes.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:journal_app/storage/preference.dart';
import 'package:journal_app/theme/style.dart';

StreamController<bool> isDarkTheme = StreamController();

void main() async {
  runApp(
    MyApp(),
  );
  await PreferenceManager.init();
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return StreamBuilder<bool>(
        stream: isDarkTheme.stream,
        initialData: false,
        builder: (context, snapshot) {
          return MaterialApp(
            title: AppStrings.app_name,
            theme: snapshot.data ? AppStyles.darkTheme : AppStyles.lightTheme,
            initialRoute: AppRoute.initialRoute(),
            routes: AppRoute.getRouteMap(),
          );
        });
  }
}
