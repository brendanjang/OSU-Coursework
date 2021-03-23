from item import Item


# This is the key object
class Key(Item):
    def __init__(self):
        self.name = "key"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is silver key\n"
              "This key can be used to unlock the first floor elevator.\n"
              "To use it, enter the command 'unlock elevator with key'.\n")


class SmallKey(Item):
    def __init__(self):
        self.name = 'small key'
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nThis is a small key. It seems too small to use on a '
              'regular door...\n')


if __name__ == "__main__":
    key = Key()
    key.description()
    print(key)