from item import Item


# This is the mirror object
class Mirror(Item):
    def __init__(self):
        self.name = "mirror"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nIt is a broken circular mirror. You see the reflection of "
              "your dirty face.\n")


if __name__ == "__main__":
    mirror = Mirror()
    mirror.description()
    print(mirror)