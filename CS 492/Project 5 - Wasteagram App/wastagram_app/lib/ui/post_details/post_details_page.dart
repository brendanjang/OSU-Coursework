import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/resources/strings.dart';
import 'package:wastagram_app/ui/widgets/Widgets.dart';
import 'package:wastagram_app/utils/helper.dart';

class PostDetailPage extends StatelessWidget {
  const PostDetailPage({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final Post post = ModalRoute.of(context).settings.arguments;
    return AppToolbarScaffold(
        title: AppStrings.app_name,
        body: Padding(
          padding: const EdgeInsets.all(8.0),
          child: CustomScrollView(
            slivers: [
              SliverFillRemaining(
                hasScrollBody: false,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.spaceAround,
                  children: <Widget>[
                    Text(
                      formattedDayMonthDate(post.date),
                      style: Theme.of(context).textTheme.headline4,
                      textAlign: TextAlign.center,
                    ),
                    SizedBox(
                      height: 6,
                    ),
                    ConstrainedBox(
                      constraints: new BoxConstraints(
                        minHeight: 50,
                        minWidth: 400,
                        maxHeight: 300.0,
                        maxWidth: 500,
                      ),
                      child: post.imageURL == null
                          ? Image.asset(
                              "assets/images/pic.jpeg",
                            )
                          : Image.network(post.imageURL,
                              width: double.infinity, fit: BoxFit.fill),
                    ),
                    SizedBox(
                      height: 6,
                    ),
                    Text("${post.quantity} Items",
                        style: Theme.of(context).textTheme.headline4),
                    SizedBox(
                      height: 6,
                    ),
                    Text("Location: (${post.latitude}, ${post.longitude})"),
                  ],
                ),
              ),
            ],
          ),
        ));
  }
}
