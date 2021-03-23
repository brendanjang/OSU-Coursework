from item import Item


# This is the coat object
class Arm(Item):
    def __init__(self):
        self.name = "arm"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a mannequin arm. There is a key welded to where it's pinkie should be.\n")

if __name__ == "__main__":
    arm = Arm()
    arm.description()
    print(arm)