import 'dart:math';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:project3/models/resume.dart';
import 'package:project3/resources/strings.dart';
import 'package:project3/theme/style.dart';

class ResumeDetails extends StatelessWidget {
  final Resume resume = Resume(
      "Software Developer Intern",
      "E Corp",
      "2016",
      "",
      "Springfield, OR",
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");

  List<Resume> resumeList;

  ResumeDetails() {
    resumeList = List.filled(20, resume);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.blueGrey,
      body: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Expanded(
              child: ListView.separated(
            padding: const EdgeInsets.all(5.5),
            itemCount: resumeList.length,
            itemBuilder: (context, index) {
              return index == 0
                  ? UserDetails(name: AppStrings.name)
                  : ResumeTileDetails(
                      resume: resumeList[index],
                    );
            },
            separatorBuilder: (context, index) => SizedBox(
              height: 20,
            ),
          ))
        ],
      ),
    );
  }
}

class UserDetails extends StatelessWidget {
  final String name;

  const UserDetails({Key key, this.name}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        SizedBox(height: 20),
        Text(name, style: AppStyles.big),
        Text(AppStrings.github_link, style: AppStyles.small),
        Text(AppStrings.email_edu, style: AppStyles.small),
      ],
    );
  }
}

class ResumeTileDetails extends StatelessWidget {
  final Resume resume;

  const ResumeTileDetails({Key key, this.resume}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(resume.title, style: AppStyles.bold),
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: [
            Text(resume.company, style: AppStyles.small),
            Text(
                '${resume.startYear} - ${resume.endYear.isEmpty ? "Present" : resume.endYear}',
                style: AppStyles.small),
            Text(resume.place, style: AppStyles.small),
          ],
        ),
        Text(resume.description, style: AppStyles.small),
      ],
    );
  }
}
