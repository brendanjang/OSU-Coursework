import 'dart:math';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:project3/resources/strings.dart';
import 'package:project3/theme/style.dart';

class Predictor extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    return PredictorState();
  }
}

class PredictorState extends State {
  String randomAnswer = AppStrings.predictor_options[0];

  void updateRandomAnswer() {
    print("change");
    setState(() {
      randomAnswer = AppStrings.getRandomPredictor();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: SingleChildScrollView(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Text(AppStrings.predictor_title, style: AppStyles.h1),
              SizedBox(height: 40),
              InkWell(
                onTap: updateRandomAnswer,
                child: Text(
                  AppStrings.predictor_question__tap_text,
                  style: AppStyles.big_dark,
                ),
              ),
              SizedBox(height: 40),
              InkWell(
                onTap: () {},
                child: Text(
                  randomAnswer,
                  style: AppStyles.h1,
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
