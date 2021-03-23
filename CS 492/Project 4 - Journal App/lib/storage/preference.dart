import 'package:flutter/services.dart' show rootBundle;
import 'package:journal_app/main.dart';
import 'package:journal_app/models/journal.dart';
import 'package:journal_app/resources/strings.dart';
import 'package:path/path.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:sqflite/sqflite.dart';

class PreferenceManager {
  PreferenceManager._();

  static init() async {
    isDark = await SharedPreferences.getInstance()
        .then((value) => value.getBool(AppStrings.pref_theme_key));
    isDark = isDark ?? false;
    isDarkTheme.add(isDark);
  }

  static var isDark = false;

  static void saveData(String key, dynamic value) async {
    if (key == AppStrings.pref_theme_key) {
      isDark = value;
    }
    final prefs = await SharedPreferences.getInstance();
    if (value is int) {
      prefs.setInt(key, value);
    } else if (value is String) {
      prefs.setString(key, value);
    } else if (value is bool) {
      prefs.setBool(key, value);
    } else {
      print("Invalid Type");
    }
  }

  static Future<dynamic> readData(String key) async {
    final prefs = await SharedPreferences.getInstance();
    dynamic obj = prefs.get(key);
    return obj;
  }

  static Future<bool> deleteData(String key) async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.remove(key);
  }
}

class DBManager {
  static final _databaseVersion = 1;
  static final _databaseName = "journal.sqlite3.db";

  DBManager._privateConstructor();

  static final DBManager instance = DBManager._privateConstructor();

  static Database _database;

  Future<Database> get database async {
    if (_database != null) return _database;
    _database = await _initDatabase();
    return _database;
  }

  // open the database
  _initDatabase() async {
    String path = join(await getDatabasesPath(), _databaseName);
    return await openDatabase(path,
        version: _databaseVersion, onCreate: _onCreate);
  }

  Future _onCreate(Database db, int version) async {
    String data = await getFileData("assets/db/schema_1.sql");
    await db.execute(data);
  }

  Future<String> getFileData(String path) async {
    return await rootBundle.loadString(path);
  }

  Future<int> insert(Journal journal) async {
    Database db = await database;
    int id = await db.insert(table, journal.toMap());
    return id;
  }

  Future<Journal> queryJournal(int id) async {
    Database db = await database;
    List<Map> maps = await db.query(table,
        columns: [columnId, columnTitle, columnBody, columnRating, columnDate],
        where: '$columnId = ?',
        whereArgs: [id]);
    if (maps.length > 0) {
      return Journal.fromMap(maps.first);
    }
    return null;
  }

  Future<List<Journal>> queryJournalALL() async {
    Database db = await database;
    List<Map> maps = await db.query(table,
        columns: [columnId, columnTitle, columnBody, columnRating, columnDate]);
    if (maps.length > 0) {
      return maps.map((e) => Journal.fromMap(e)).toList(growable: true);
    }
    return null;
  }
}
