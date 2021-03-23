final String table = 'journal_entries';
final String columnId = 'id';
final String columnTitle = 'title';
final String columnBody = 'body';
final String columnRating = 'rating';
final String columnDate = 'date';

class Journal {
  int id;
  String title;
  String body;
  int rating;
  DateTime date;

  Journal();

  Journal.withValues(this.id, this.title, this.body, this.rating, this.date);

  Journal.fromMap(Map<String, dynamic> map) {
    id = map[columnId];
    title = map[columnTitle];
    body = map[columnBody];
    rating = map[columnRating];
    date = DateTime.parse(map[columnDate]);
  }

  Map<String, dynamic> toMap() {
    var map = <String, dynamic>{
      columnTitle: title,
      columnBody: body,
      columnRating: rating,
      columnDate: date.toIso8601String(),
    };
    if (id != null) {
      map[columnId] = id;
    }
    return map;
  }

  Journal.empty() : this.withValues(0, "", "", 0, null);

  @override
  String toString() {
    return 'Journal{id: $id, title: $title, body: $body, rating: $rating, date: $date}';
  }

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is Journal &&
          runtimeType == other.runtimeType &&
          id == other.id &&
          title == other.title &&
          body == other.body &&
          rating == other.rating &&
          date == other.date;

  @override
  int get hashCode =>
      id.hashCode ^
      title.hashCode ^
      body.hashCode ^
      rating.hashCode ^
      date.hashCode;
}
