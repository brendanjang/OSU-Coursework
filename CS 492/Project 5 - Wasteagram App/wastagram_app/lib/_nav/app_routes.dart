import 'package:wastagram_app/ui/home/home_page.dart';
import 'package:wastagram_app/ui/new_post/new_post_page.dart';
import 'package:wastagram_app/ui/post_details/post_details_page.dart';

class AppRoute {
  AppRoute._();

  static const String app_home = '/AppHome';

  static const String new_post = '/new_post';

  static const String new_post_details = '/post_details';

  static String initialRoute() {
    return app_home;
  }

  static getRouteMap() {
    return {
      AppRoute.app_home: (context) => MyHomePage(),
      AppRoute.new_post: (context) => AddPost(),
      AppRoute.new_post_details: (context) => PostDetailPage(),
    };
  }
}
