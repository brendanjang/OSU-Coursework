from item import Item


# This is the key object
class OldKey(Item):
    def __init__(self):
        self.name = "old key"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is an old key. You wonder what it opens...\n")


if __name__ == "__main__":
    key = OldKey()
    key.description()
    print(key)