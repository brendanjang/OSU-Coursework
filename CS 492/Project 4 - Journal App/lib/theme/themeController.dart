import 'package:flutter/material.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:journal_app/storage/preference.dart';
import 'package:journal_app/theme/style.dart';

class ThemeNotifier extends ChangeNotifier {
  ThemeData _themeData;

  ThemeData getTheme() => _themeData;

  ThemeNotifier() {
    PreferenceManager.readData(AppStrings.pref_theme_key).then((value) {
      if (value == true) {
        _themeData = AppStyles.darkTheme;
      } else {
        _themeData = AppStyles.lightTheme;
      }
      notifyListeners();
    });
  }

  void setDarkMode(bool isDark) async {
    _themeData = isDark ? AppStyles.darkTheme : AppStyles.lightTheme;
    PreferenceManager.saveData(AppStrings.pref_theme_key, isDark);
    notifyListeners();
  }
}
