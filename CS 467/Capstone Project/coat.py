from item import Item


# This is the coat object
class Coat(Item):
    def __init__(self):
        self.name = "coat"
        self.isWearing = False
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is an old red coat.\n"
              "You can wear this coat in the first floor.\n"
              "To wear it, enter the command 'wear coat'.\n"
              "To take it off, enter the command 'take coat off'.\n")


if __name__ == "__main__":
    coat = Coat()
    coat.description()
    print(coat)