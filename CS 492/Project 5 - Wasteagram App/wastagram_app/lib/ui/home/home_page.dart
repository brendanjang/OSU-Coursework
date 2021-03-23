import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:wastagram_app/_nav/app_routes.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/resources/colors.dart';
import 'package:wastagram_app/resources/strings.dart';
import 'package:wastagram_app/ui/widgets/Widgets.dart';
import 'package:wastagram_app/utils/helper.dart';
import 'package:firebase_crashlytics/firebase_crashlytics.dart';

class MyHomePage extends StatefulWidget {
  MyHomePage({Key key}) : super(key: key);

  @override
  State<StatefulWidget> createState() {
    return MyHomePageState();
  }
}

class MyHomePageState extends State<MyHomePage> {
  List<Post> posts;
  int totQty = 0;
  bool isNew = false;

  @override
  void initState() {
    super.initState();
    posts = [];
    fetchPosts();
  }

  fetchPosts() async {
    FirebaseFirestore.instance
        .collection(AppStrings.post_collection)
        .orderBy("date", descending: true)
        .snapshots()
        .listen(
      (event) {
        event.docChanges.forEach((element) {
          Post post = Post.fromMap(element.doc.data());
          print('new val ${post.toString()} : ${element.type}');
          if (element.type == DocumentChangeType.added) {
            totQty += post.quantity;
            isNew ? posts.insert(0, post) : posts.add(post);
          }
        });
        isNew = true;
        setState(() {});
      },
    );
    setState(() {});
  }

  @override
  Widget build(BuildContext context) {
    return AppToolbarScaffold(
        title: "${AppStrings.app_name}${totQty == 0 ? "" : " - $totQty"}",
        floatingActionButton: FloatingActionButton(
          onPressed: () {
            Navigator.of(context).pushNamed(AppRoute.new_post);
          },
          child: Icon(Icons.camera_alt),
          backgroundColor: AppColors.primary,
        ),
        body: Padding(
          padding: const EdgeInsets.all(8.0),
          child: (posts == null || posts.isEmpty)
              ? Center(
                  child: CircularProgressIndicator(),
                )
              : ListView.separated(
                  itemBuilder: (context, index) {
                    return InkWell(
                      child: PostTile(post: posts[index]),
                      onTap: () {
                        // FirebaseCrashlytics.instance.setCustomKey('source', 'ios');
                        // FirebaseCrashlytics.instance.log('Simulated ios crash');
                        // FirebaseCrashlytics.instance.crash();
                        // throw StateError('Uncaught error thrown by app.');
                        Navigator.pushNamed(context, AppRoute.new_post_details,
                            arguments: posts[index]);
                      },
                    );
                  },
                  separatorBuilder: (context, index) => SizedBox(
                        height: 12,
                      ),
                  itemCount: posts.length),
        ));
  }
}

class PostTile extends StatelessWidget {
  final Post post;

  const PostTile({Key key, this.post}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(4.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(
            "${formattedDayMonthDate(post.date)}",
            style: Theme.of(context).textTheme.headline6,
          ),
          Text(
            "${post.quantity}",
            style: Theme.of(context).textTheme.headline5,
          )
        ],
      ),
    );
  }
}
