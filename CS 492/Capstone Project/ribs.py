from item import Item


# This is the coat object
class Ribs(Item):
    def __init__(self):
        self.name = "ribs"
        self.eaten = False
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis are baby back ribs.\n"
              "They can be eaten in any of the rooms in the first floor only.\n"
              "To eat them, enter the command 'eat ribs'.\n")


if __name__ == "__main__":
    ribs = Ribs()
    ribs.description()
    print(ribs)