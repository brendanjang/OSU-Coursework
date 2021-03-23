from item import Item


# This is the rope object
class Rope(Item):
    def __init__(self):
        self.name = "rope"
        self.tied = False
        super().__init__(self.name)

    @staticmethod
    def description():
        return "\nThis is a very long piece of sturdy rope.\n"


if __name__ == "__main__":
    rope = Rope()
    rope.description()
    print(rope)