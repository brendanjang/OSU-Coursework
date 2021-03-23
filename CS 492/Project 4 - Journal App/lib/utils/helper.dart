import 'package:intl/intl.dart';

bool isNumeric(String s) {
  if (s == null) {
    return false;
  }
  return double.parse(s, (e) => null) != null;
}

final DateFormat dmFormatter = DateFormat('MMMM dd, yyyy');
final DateFormat mFormatter = DateFormat('EEEE, MMMM dd, yyyy');

String formattedMonthDate(DateTime dateTime) {
  return dmFormatter.format(dateTime);
}

String formattedDayMonthDate(DateTime dateTime) {
  return mFormatter.format(dateTime);
}
