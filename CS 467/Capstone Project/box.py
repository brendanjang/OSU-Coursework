from item import Item


# box object
class Box(Item):
    def __init__(self):
        self.name = "box"
        super().__init__(self.name)

    @staticmethod
    def description():
        return 'It\'s an empty box.'


if __name__ == "__main__":
    box = Box()
    box.description()
    print(box)