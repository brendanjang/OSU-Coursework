from item import Item


# wardrobe object
class Wardrobe(Item):
    def __init__(self):
        self.name = "wardrobe"
        self.unlocked = False
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nThis is a large antique wardrobe that scales the height ' \
              'of the wall.\n')

    def open(self, command, player):
        if command in player.inventory_list:
            self.unlocked = True
            print('\nYou unlock the wardrobe revealing a hidden entrance.\n')
        else:
            print('\nYou have no means to unlock it.\n')

    def get_in(self, player):
        if self.unlocked is True:
            print('\nYou walk into the wardrobe....\n')
            player.move(0, 2)
        else:
            print('\nIt\'s locked...\n')


if __name__ == "__main__":
    wardrobe = Wardrobe()
    wardrobe.description()
    print(wardrobe)
