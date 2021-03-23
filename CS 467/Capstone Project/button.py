from item import Item


# This is the button object
class Button(Item):
    def __init__(self):
        self.name = "button"
        super().__init__(self.name)
        self.pressed = False

    @staticmethod
    def description():
        return '\nA small wooden button.\n'


if __name__ == "__main__":
    button = Button()
    button.description()
    print(button)