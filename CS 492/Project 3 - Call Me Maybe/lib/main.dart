import 'package:flutter/material.dart';
import 'package:project3/resources/colors.dart';
import 'package:project3/resources/strings.dart';
import 'package:project3/theme/style.dart';
import 'package:project3/ui/home/home_page.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: AppStrings.app_name,
      theme: AppStyles.theme,
      home: MyHomePage(
        title: AppStrings.app_name,
      ),
    );
  }
}
