import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:project3/resources/strings.dart';
import 'package:project3/theme/style.dart';
import 'package:project3/utils/ui.dart';
import 'package:url_launcher/url_launcher.dart';

class Profile extends StatelessWidget {
  final CallsAndMessagesService _service = CallsAndMessagesService();

  @override
  Widget build(BuildContext context) {
    final Orientation orientation = MediaQuery.of(context).orientation;
    final bool isLandscape = orientation == Orientation.landscape;
    final double space = isLandscape ? 2 : 20;
    return Scaffold(
      body: Container(
        padding: const EdgeInsets.all(10),
        decoration: BoxDecoration(
            gradient: LinearGradient(
                begin: Alignment.topCenter,
                end: Alignment.bottomCenter,
                colors: [Colors.lime, Colors.teal]),
            color: Colors.lightBlue),
        child: Center(
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.center,
            mainAxisAlignment: MainAxisAlignment.start,
            children: [
              CircleAvatar(
                backgroundImage: AssetImage('lib/assets/images/profile.jpg'),
                radius: 40,
              ),
              SizedBox(
                height: space,
              ),
              // SizedBox(height: 20),
              Text(AppStrings.name, style: AppStyles.big),
              SizedBox(
                height: space,
              ),
              // SizedBox(height: 20),
              Text(AppStrings.title, style: AppStyles.normal),
              SizedBox(
                height: space,
              ),
              // SizedBox(height: 20),
              InkWell(
                onTap: () {
                  _service.sendSms(AppStrings.phone);
                },
                child: Text(AppStrings.phone, style: AppStyles.normal),
              ),
              SizedBox(
                height: space,
              ),
              // SizedBox(height: 20),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  InkWell(
                    onTap: () {
                      _service.openLink(AppStrings.github);
                    },
                    child: Text(AppStrings.github, style: AppStyles.small),
                  ),
                  Text(AppStrings.email, style: AppStyles.small),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}

class CallsAndMessagesService {
  void sendSms(String number) => launch("sms:$number");
  void openLink(String link) => launch("https:$link");
}
