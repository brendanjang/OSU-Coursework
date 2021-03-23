from item import Item


# This is the poker object
# It can be used to stir the fireplace ash to find the partially burned note. Otherwise, it can be used as a weapon
# in certain cases.
class Poker(Item):
    def __init__(self):
        self.name = "poker"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a fireplace poker\n")


if __name__ == "__main__":
    poker = Poker()
    poker.description()
    print(poker)