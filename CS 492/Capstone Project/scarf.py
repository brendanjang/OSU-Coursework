from item import Item


# This is the scarf object
class Scarf(Item):
    def __init__(self):
        self.name = "scarf"
        self.isWearing = False
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a warm wool scarf\n"
              "You can wear this scarf in the first floor.\n"
              "To wear it, enter the command 'wear scarf'.\n"
              "To take it off, enter the command 'take scarf off'.\n")


if __name__ == "__main__":
    scarf = Scarf()
    scarf.description()
    print(scarf)