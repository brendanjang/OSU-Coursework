from item import Item


# This is the flashlight object
class Flashlight(Item):
    def __init__(self):
        self.name = "flashlight"
        self.uses_left = 5
        self.isON = False
        super().__init__(self.name)

    def description(self):
        print(f"\nThis is a rusted metal flashlight.\n"
              f"This flashlight can be used to enter dark rooms. Furthermore, this flashlight\n"
              f"can only be turn on and off 5 times. After this, you need to change batteries.\n"
              f"To turn it ON, enter the command 'turn on flashlight'.\n"
              f"To turn it OFF, enter the command 'turn off flashlight'\n"
              f"You have {self.uses_left} uses left.\n")

    def turn_on(self):
        if not self.isON:
            if self.uses_left > 0:
                self.isON = True
                self.uses_left -= 1
                print("\nThe flashlight is ON.\n")
            else:
                print("\nThe batteries are dead.\n"
                      "You need to change batteries.\n")
        else:
            print("\nThe flashlight is already ON.\n")

    def turn_off(self):
        if self.isON:
            self.isON = False
            print("\nThe flashlight is OFF.\n")
        else:
            print("\nThe flashlight is already OFF.\n")

    def change_batteries(self, batteries):
        # Check if the batteries are charged.
        if batteries.charged:
            self.uses_left = 5
            batteries.charged = False
            print("\nThe batteries were changed.\n")
        else:
            print("\nThe batteries are dead\n")

