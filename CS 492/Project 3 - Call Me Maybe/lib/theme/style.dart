import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:project3/resources/colors.dart';

class AppStyles {
  static const TextStyle big = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 18.0,
    color: Colors.white,
  );
  static const TextStyle normal = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 14.0,
    color: Colors.white,
  );
  static const TextStyle bold = TextStyle(
      fontFamily: 'Open Sans',
      fontSize: 16.0,
      color: Colors.white,
      fontWeight: FontWeight.bold);
  static const TextStyle small = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 12.0,
    color: Colors.white,
  );

  static const TextStyle h1 = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 26.0,
    color: Colors.blueGrey,
  );

  static const TextStyle big_dark = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 18.0,
    color: Colors.black,
  );
  static const TextStyle normal_dark = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 14.0,
    color: Colors.black,
  );
  static const TextStyle Bold_dark = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 16.0,
    color: Colors.black,
  );
  static const TextStyle small_dark = TextStyle(
    fontFamily: 'Open Sans',
    fontSize: 12.0,
    color: Colors.black,
  );

  static const TextStyle normal_dark_bold = TextStyle(
      fontFamily: 'Open Sans',
      fontSize: 14.0,
      color: Colors.black,
      fontWeight: FontWeight.bold);

  static const primaryTextTheme =
      TextTheme(headline6: TextStyle(color: Colors.white));

  static final theme = ThemeData(
    primaryTextTheme: primaryTextTheme,
    primarySwatch: AppColors.primary,
    accentColor: AppColors.accent,
    visualDensity: VisualDensity.adaptivePlatformDensity,
  );
}
