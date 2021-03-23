import 'package:flutter_test/flutter_test.dart';
import 'package:wastagram_app/main.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/models/post.dart';
import 'package:wastagram_app/models/post.dart';

void main() {
  test('Post Model Test', () {
    final date = DateTime.now();
    final post = Post(date, "http://google.com", 10, 12.232423, 11.223233);
    expect(date, post.date);
    expect("http://google.com", post.imageURL);
    expect(10, post.quantity);
    expect(12.232423, post.latitude);
    expect(11.223233, post.longitude);
  });

  test('Post Model from Map', () {
    final date = DateTime.now();
    final map = {
      columnDate: date.toIso8601String(),
      columnQty: 10,
      columnLatitude: 12.232423,
      columnLongitude: 11.223233,
      columnImageURL: "http://google.com"
    };
    final post = Post.fromMap(map);
    expect(date, post.date);
    expect("http://google.com", post.imageURL);
    expect(10, post.quantity);
    expect(12.232423, post.latitude);
    expect(11.223233, post.longitude);
  });

  test('Post Model to Map', () {
    final date = DateTime.now();
    final map = {
      columnDate: date.toIso8601String(),
      columnQty: 10,
      columnLatitude: 12.232423,
      columnLongitude: 11.223233,
      columnImageURL: "http://google.com"
    };
    final post = Post.fromMap(map);

    final postMap = post.toMap();
    expect(map, postMap);
  });

  test('Post Model equals', () {
    final date = DateTime.now();
    final map = {
      columnDate: date.toIso8601String(),
      columnQty: 10,
      columnLatitude: 12.232423,
      columnLongitude: 11.223233,
      columnImageURL: "http://google.com"
    };
    final post = Post.fromMap(map);
    final post2 = Post(date, "http://google.com", 10, 12.232423, 11.223233);

    expect(true, post == post2);
  });

  test('Post toString', () {
    final date = DateTime.now();
    final post2 = Post(date, "http://google.com", 10, 12.232423, 11.223233);

    expect(
        'Post{date: $date, imageURL: http://google.com, quantity: 10, latitude: 12.232423, longitude: 11.223233}',
        post2.toString());
  });
}
