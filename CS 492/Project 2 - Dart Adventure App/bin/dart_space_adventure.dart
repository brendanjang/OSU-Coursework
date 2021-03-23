import 'dart:io';
import 'dart:convert';
import 'package:dart_space_adventure/dart_space_adventure.dart';
import 'package:dart_space_adventure/src/planetary_system.dart';

void main(List<String> arguments) {
  var filename = arguments[0];
  File(filename).readAsString().then((String json) {
    SpaceAdventure(planetarySystem: PlanetarySystem.fromJson(jsonDecode(json)))
        .start();
  });
}
