from item import Item


# This is the duster object.  It is a useless object
class Duster(Item):
    def __init__(self):
        self.name = "duster"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is an ordinary looking feather duster.\n")


if __name__ == "__main__":
    duster = Duster()
    duster.description()
    print(duster)