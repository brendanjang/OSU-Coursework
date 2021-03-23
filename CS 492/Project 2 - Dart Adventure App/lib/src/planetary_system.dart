import 'dart:math';
import 'planet.dart';

class PlanetarySystem {
  final Random _random = Random();
  String name;
  List<Planet> planets;

  PlanetarySystem({this.name, this.planets});

  int get numberOfPlanets => planets.length;
  bool get hasPlanets => planets.isNotEmpty;

  PlanetarySystem.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    if (json['planets'] != null) {
      planets = List<Planet>();
      json['planets'].forEach((v) {
        planets.add(Planet.fromJson(v));
      });
    }
  }

  Planet randomPlanet() {
    if (!hasPlanets) return Planet.nullPlanet();
    return planets[_random.nextInt(planets.length)];
  }

  Planet planetWithName(String name) {
    return planets.firstWhere((planet) => planet.name == name,
        orElse: () => Planet.nullPlanet());
  }
}
