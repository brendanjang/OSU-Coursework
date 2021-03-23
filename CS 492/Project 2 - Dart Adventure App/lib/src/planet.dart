class Planet {
  String name;
  String description;

  Planet({this.name, this.description});

  Planet.nullPlanet()
      : name = 'Null',
        description = 'Null Planet';

  Planet.fromJson(Map<String, dynamic> json) {
    name = json['name'];
    description = json['description'];
  }
}
