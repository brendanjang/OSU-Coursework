import 'package:flutter/cupertino.dart';

double getScreenHeight(BuildContext context, int factor) {
  return ((MediaQuery.of(context).size.height / factor));
}
