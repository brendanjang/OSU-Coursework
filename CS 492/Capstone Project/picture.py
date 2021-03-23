from item import Item


# This is the picture object
class Picture(Item):
    def __init__(self):
        self.name = 'picture'
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a picture.\n")


class FirstPicture(Item):
    def __init__(self):
        self.name = 'first painting'
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nA family portrait. It shows parents with their '
              'two children, a son and daughter.\n')


class SecondPicture(Item):
    def __init__(self):
        self.name = 'second painting'
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nA family portrait. It shows parents and their son. '
              'They are all smiling.\n')


class ThirdPicture(Item):
    def __init__(self):
        self.name = 'third painting'
        super().__init__(self.name)

    @staticmethod
    def description():
        print('\nPainting of just the daughter who is smiling...\n')

if __name__ == "__main__":
    picture = Picture()
    picture.description()
    print(picture)