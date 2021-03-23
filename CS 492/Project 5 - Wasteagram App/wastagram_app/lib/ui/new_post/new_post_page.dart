import 'dart:io';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_crashlytics/firebase_crashlytics.dart';
import 'package:firebase_storage/firebase_storage.dart';
import 'package:flutter/material.dart';
import 'package:image_picker/image_picker.dart';
import 'package:location/location.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/resources/strings.dart';
import 'package:wastagram_app/ui/widgets/Widgets.dart';

class AddPost extends StatefulWidget {
  @override
  _AddPostState createState() => _AddPostState();
}

class _AddPostState extends State<AddPost> {
  final TextEditingController itemWasted = TextEditingController();

  final Location location = Location();
  var _isValid = true;

  bool _serviceEnabled;
  PermissionStatus _permissionGranted;

  File _image;
  final picker = ImagePicker();

  Future<LocationData> getLocation() async {
    _serviceEnabled = await location.serviceEnabled();
    if (!_serviceEnabled) {
      _serviceEnabled = await location.requestService();
      if (!_serviceEnabled) {
        return Future.error("Location service is not enabled");
      }
    }

    _permissionGranted = await location.hasPermission();
    if (_permissionGranted == PermissionStatus.denied) {
      _permissionGranted = await location.requestPermission();
      if (_permissionGranted != PermissionStatus.granted) {
        return Future.error("Location permissions are not allowed");
      }
    }

    return await location.getLocation();
  }

  Future getImage({src = ImageSource.gallery}) async {
    itemWasted.clear();
    final pickedFile = await picker.getImage(source: src);

    if (pickedFile != null) {
      _image = File(pickedFile.path);
      setState(() {});
      print('${_image.path} ${_image.absolute.path}');
    } else {
      FirebaseCrashlytics.instance.log('Image picker is null');
    }
  }

  @override
  void initState() {
    super.initState();
    Future.delayed(Duration.zero, () {
      showPictureOption(context);
    });
  }

  showPictureOption(context) {
    showModalBottomSheet(
      context: context,
      builder: (context) {
        return SafeArea(
            child: Column(
          children: [
            ListTile(
                leading: new Icon(Icons.photo_library),
                title: new Text('Image from Gallery'),
                onTap: () {
                  getImage();
                }),
            ListTile(
                leading: new Icon(Icons.camera_alt),
                title: new Text('Image from Camera'),
                onTap: () {
                  getImage(src: ImageSource.camera);
                })
          ],
        ));
      },
    );
  }

  uploadImage() async {
    var locationData = await getLocation();

    var firebaseStorage = FirebaseStorage.instance;
    var ref = firebaseStorage
        .ref(AppStrings.img_post_collection)
        .child(_image.path.split("/").last);
    final metadata = SettableMetadata(
        contentType: 'image/jpg',
        customMetadata: {'picked-file-path': _image.path});
    TaskSnapshot task = await ref.putFile(_image, metadata);
    var url = await task.ref.getDownloadURL();
    print("url is $url");

    var post = Post(DateTime.now(), url, int.parse(itemWasted.text),
        locationData.latitude, locationData.longitude);
    var result = await FirebaseFirestore.instance
        .collection(AppStrings.post_collection)
        .add(post.toMap());
    Navigator.pop(context);
    print("id is ${post.toString()}");
  }

  @override
  Widget build(BuildContext context) {
    return AppToolbarScaffold(
      bottomAppBar: BottomAppBar(
        color: Colors.blue,
        child: InkWell(
          child: Icon(
            Icons.cloud_upload,
            size: 84,
          ),
          onTap: () {
            if (itemWasted.text.isEmpty) {
              _isValid = false;
            } else {
              _isValid = true;
              uploadImage();
            }
            setState(() {});
          },
        ),
        elevation: 0,
      ),
      title: AppStrings.new_post,
      body: SingleChildScrollView(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.start,
          children: [
            ConstrainedBox(
              constraints: new BoxConstraints(
                minHeight: 250,
                minWidth: double.infinity,
                maxHeight: 300.0,
                maxWidth: double.infinity,
              ),
              child: _image == null
                  ? Image.asset(
                      "assets/images/pic.jpeg",
                    )
                  : Image.file(File(_image.path)),
            ),
            Padding(
              padding: const EdgeInsets.all(12.0),
              child: TextField(
                autofocus: true,
                controller: itemWasted,
                keyboardType: TextInputType.number,
                textAlign: TextAlign.center,
                decoration: InputDecoration(
                  errorText: _isValid ? null : "Items cannot be empty",
                  hintText: "Number of Wasted Items",
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}
