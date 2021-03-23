from item import Item


class WaterBottle(Item):
    def __init__(self):
        self.name = "water bottle"
        self.isFull = True
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is bottle full fo potable water.\n"
              "It can be drank in any of the rooms in the first floor only.\n"
              "After it's drank, it can be filled in the guest bathroom.\n"
              "To drink it, enter the command 'drink water'.\n"
              "To fill it up, enter the command 'fill water bottle'.\n")


if __name__ == "__main__":
    wb = WaterBottle()
    wb.description()
    print(wb)