import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_crashlytics/firebase_crashlytics.dart';
import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:wastagram_app/main.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/resources/strings.dart';
import 'package:wastagram_app/ui/home/home_page.dart';
import 'package:wastagram_app/ui/post_details/post_details_page.dart';
import 'package:wastagram_app/ui/widgets/Widgets.dart';
import 'package:wastagram_app/utils/helper.dart';

void main() {
  testWidgets('Home page loading dialog', (WidgetTester tester) async {
    final date = DateTime.now();
    final post = Post(date, null, 10, 12.232423, 11.223233);

    await tester.pumpWidget(MaterialApp(
      home: Navigator(
        onGenerateRoute: (settings) {
          return MaterialPageRoute(
              builder: (context) => PostDetailPage(),
              settings: RouteSettings(arguments: post));
        },
      ),
    ));

    expect(find.byWidgetPredicate((widget) {
      if (widget is Text) {
        final Text textWidget = widget;
        if (textWidget.data != null)
          return textWidget.data.contains(AppStrings.app_name);
        return textWidget.textSpan.toPlainText().contains(AppStrings.app_name);
      }
      return false;
    }), findsOneWidget);

    expect(find.text(formattedDayMonthDate(post.date)), findsOneWidget);
    expect(find.text("${post.quantity} Items"), findsOneWidget);
    final locStr = "Location: (${post.latitude}, ${post.longitude})";
    expect(find.text(locStr), findsOneWidget);
  });
}

Widget makeTestableWidget(Widget child) {
  return MaterialApp(home: child);
}
