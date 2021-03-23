import 'package:journal_app/ui/home/home_master.dart';
import 'package:journal_app/ui/journal_details/journal_details_page.dart';
import 'package:journal_app/ui/journal_entries/journal_input.dart';

class AppRoute {
  AppRoute._();

  static const String app_home = '/AppHome';

  static const String journal_details = '/JournalDetails';
  static const String journal_input = '/journal_input';

  static String initialRoute() {
    return app_home;
  }

  static getRouteMap() {
    return {
      AppRoute.app_home: (context) => MasterHome(),
      AppRoute.journal_input: (context) => JournalFrom(),
      AppRoute.journal_details: (context) => JournalDetailPage(),
    };
  }
}
