from item import Item


# window object
class Window(Item):
    def __init__(self):
        self.name = "window"
        self.opened = False
        super().__init__(self.name)

    def description(self):
        if self.opened is False:
            print("\nYou look out the window and see the endless dark night.\n")
        if self.opened is True:
            print('\nThe window is open and a gentle breeze blows in.\n')

    @staticmethod
    def locked():
        print('\nTry as you might, you can\'t open the window. '
              'It is locked.\n')


if __name__ == "__main__":
    window = Window()
    window.description()
    print(window)
