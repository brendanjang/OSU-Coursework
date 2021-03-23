from item import Item


# This is the watch object. It is useless. The watch face will show midnight, or noon, if the player looks at it.
# A hidden clue.
class Watch(Item):
    def __init__(self):
        self.name = "watch"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a golden watch on a chain. It's time is frozen at either noon or midnight.\n")


if __name__ == "__main__":
    watch = Watch()
    watch.description()
    print(watch)