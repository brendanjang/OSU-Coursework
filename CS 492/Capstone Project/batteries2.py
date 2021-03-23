from item import Item


# This is the batteries object
class Batteries2(Item):
    def __init__(self):
        self.charged = True
        self.name = "batteries2"
        super().__init__(self.name)

    def description(self):
        print("\nThis are flashlight batteries.\n"
              "This batteries can be used to recharge the flashlight.\n"
              "Once used, they can no longer be used again.\n"
              "To use them, enter the command 'change batteries'.")
        if self.charged:
            print("This batteries are currently: Charged\n")
        else:
            print("This batteries are currently: Uncharged\n")
