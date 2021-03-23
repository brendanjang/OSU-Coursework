from item import Item


# rug object
class Rug(Item):
    def __init__(self):
        self.name = "rug"
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nAn old and dusty rug. It looks faded and trampled on.\n')

    @staticmethod
    def move_rug():
        print('\nYou move the rug aside to see what is underneath. '
              'You find nothing.\n')

    @staticmethod
    def no_take():
        print('\nYou can\'t take this. Why would you want to take a dirty old '
              'rug?\n')


if __name__ == "__main__":
    rug = Rug()
    rug.description()
    print(rug)
