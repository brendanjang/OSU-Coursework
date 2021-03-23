import 'dart:math';

class AppStrings {
  static const String app_name = 'Call Me Maybe';
  static const String name = 'Brendan Jang';
  static const String email = 'jangb@example.com';
  static const String github = 'github.com/jangb89';
  static const String github_link = 'https://github.com/jangb89';
  static const String email_edu = 'jangb@oregonstate.edu';
  static const String phone = '555 555 5555';
  static const String title = 'Developer Extraordinaire';

  static const String predictor_title = 'Call Me... Maybe?';
  static const String predictor_question__tap_text =
      'Ask a question...tap for the answer.';
  static const List<String> predictor_options = [
    'Yes, Definitely.',
    'Unlikely but possible.',
    'Maybe...',
    'The future is uncertain.',
    'Most likely. Very soon.',
    'Probably by next week.',
    'Will do.'
  ];

  static final Random random = Random();

  AppStrings._();

  static String getRandomPredictor() {
    return predictor_options[random.nextInt(predictor_options.length)];
  }
}
