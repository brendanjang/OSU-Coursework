from item import Item


# This is the shovel object
class Shovel(Item):
    def __init__(self):
        self.name = "shovel"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis a small shovel.\n"
              "This shovel can be used to dig and uncover other objects.\n"
              "To use it, enter the command 'dig with shovel' or 'use shovel to dig'.\n")


if __name__ == "__main__":
    shovel = Shovel()
    shovel.description()
    print(shovel)