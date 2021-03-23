import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:journal_app/resources/colors.dart';

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

  static final darkTheme = ThemeData(
    primarySwatch: Colors.grey,
    primaryColor: AppColors.primary,
    brightness: Brightness.dark,
    backgroundColor: const Color(0xFF212121),
    accentColor: Colors.white,
    floatingActionButtonTheme: FloatingActionButtonThemeData(
      foregroundColor: Colors.black,
    ),
    dividerColor: Colors.black12,
    primaryTextTheme: TextTheme(headline6: TextStyle(color: Colors.white)),
    textTheme: TextTheme(
        headline1: TextStyle(fontSize: 72.0, fontWeight: FontWeight.bold),
        headline6: TextStyle(fontSize: 16.0, fontWeight: FontWeight.bold),
        subtitle2:
            TextStyle(fontSize: 12.0, fontFamily: 'Hind', color: Colors.grey)),
  );

  static final lightTheme = ThemeData(
    primarySwatch: Colors.grey,
    primaryColor: AppColors.primary,
    brightness: Brightness.light,
    backgroundColor: const Color(0xFFE5E5E5),
    accentColor: Colors.black,
    floatingActionButtonTheme: FloatingActionButtonThemeData(
      foregroundColor: Colors.white,
    ),
    dividerColor: Colors.white54,
    primaryTextTheme: TextTheme(headline6: TextStyle(color: Colors.white)),
    iconTheme: IconThemeData(color: Colors.white),
    accentIconTheme: IconThemeData(color: Colors.white),
    appBarTheme: AppBarTheme(
      iconTheme: IconThemeData(color: Colors.white),
    ),
    textTheme: TextTheme(
        headline1: TextStyle(fontSize: 72.0, fontWeight: FontWeight.bold),
        headline6: TextStyle(fontSize: 16.0, fontWeight: FontWeight.bold),
        subtitle2:
            TextStyle(fontSize: 12.0, fontFamily: 'Hind', color: Colors.grey)),
  );

  AppStyles._();
}
