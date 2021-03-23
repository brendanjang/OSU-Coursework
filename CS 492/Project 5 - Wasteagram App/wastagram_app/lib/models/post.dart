final String columnImageURL = 'imgageURL';
final String columnQty = 'quantity';
final String columnLatitude = 'latitude';
final String columnLongitude = 'longitude';
final String columnDate = 'date';

class Post {
  DateTime date;
  String imageURL;
  int quantity;
  double latitude;
  double longitude;

  Post(this.date, this.imageURL, this.quantity, this.latitude, this.longitude);

  Post.fromMap(Map<String, dynamic> map) {
    imageURL = map[columnImageURL];
    quantity = map[columnQty];
    latitude = map[columnLatitude];
    longitude = map[columnLongitude];
    date = DateTime.parse(map[columnDate]);
  }

  Map<String, dynamic> toMap() {
    var map = <String, dynamic>{
      columnImageURL: imageURL,
      columnQty: quantity,
      columnLatitude: latitude,
      columnLongitude: longitude,
      columnDate: date.toIso8601String(),
    };
    return map;
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Post &&
          runtimeType == other.runtimeType &&
          date == other.date &&
          imageURL == other.imageURL &&
          quantity == other.quantity &&
          latitude == other.latitude &&
          longitude == other.longitude;

  @override
  int get hashCode =>
      date.hashCode ^
      imageURL.hashCode ^
      quantity.hashCode ^
      latitude.hashCode ^
      longitude.hashCode;

  @override
  String toString() {
    return 'Post{date: $date, imageURL: $imageURL, quantity: $quantity, latitude: $latitude, longitude: $longitude}';
  }
}
