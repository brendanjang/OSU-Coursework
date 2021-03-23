from item import Item
from key import SmallKey


# desk object
class Desk(Item):
    def __init__(self):
        self.name = "desk"
        self.hidden_found = False
        self.left_open = False
        self.right_open = False
        self.center_open = False
        self.drawer_order = []
        self.correct_order = ['left drawer', 'right drawer', 'center drawer']
        super().__init__(self.name)

    @staticmethod
    def description():
        return "\nIts an old office desk with 3 drawers. One on the left, " \
              "right, and center of the desk.\n" \
              "There are some papers scattered on top of the desk.\n"

    @staticmethod
    def hidden_desc():
        print('\nWith the final click, you hear a small popping sound coming '
              'from under the desk.\n')

    @staticmethod
    def hidden_found_desc():
        print('\nYou look under the desk to see a small hidden compartment!\n')

    @staticmethod
    def hidden_not_found():
        print('\nYou look under the desk and there is nothing to see.\n')

    @staticmethod
    def no_move():
        print('\nThis desk is too heavy to move...\n')

    @staticmethod
    def no_take():
        print('\nYou can\'t take the desk. It is too big. Besides, why would '
              'you want to take it anyways??\n')

    @staticmethod
    def correct_drawer_desc():
        print('\nYou open the drawer and see that there is nothing inside.\n'
              'You hear a faint clicking sound somewhere in the desk.\n')

    @staticmethod
    def wrong_drawer_desc():
        print('\nThe drawers shut on their own and you hear a faint '
              'thudding sound somewhere in the desk.\n')

    def open_compartment(self):
        if self.hidden_found:
            print('\nYou open the hidden compartment....'
                  'revealing a small key.\n')
            self.hidden_found = True
        else:
            print('\nThere is nothing to open.\n')

    def look_compartment(self):
        if self.hidden_found:
            print('\nIt\'s hidden compartment. It looks like something is '
                  'inside.\n')
        else:
            print('\nThere is nothing to look at.\n')

    def open_drawer(self, command):
        if command == 'left drawer' and command not in self.drawer_order:
            if not self.drawer_order:
                self.drawer_order.append(command)
                self.left_open = True
                self.correct_drawer_desc()
        elif command == 'right drawer' and command not in self.drawer_order:
            if self.left_open:
                self.drawer_order.append(command)
                self.right_open = True
                self.correct_drawer_desc()
            else:
                self.wrong_drawer_desc()
                self.left_open = False
                self.right_open = False
                self.center_open = False
                self.drawer_order.clear()
        elif command == 'center drawer' and command not in self.drawer_order:
            if self.right_open and self.left_open:
                self.drawer_order.append(command)
                self.center_open = True
                self.hidden_found = True
                self.correct_drawer_desc()
                self.hidden_desc()
            else:
                self.wrong_drawer_desc()
                self.left_open = False
                self.right_open = False
                self.center_open = False
                self.drawer_order.clear()
        else:
            self.wrong_drawer_desc()
            self.left_open = False
            self.right_open = False
            self.center_open = False
            self.drawer_order.clear()


if __name__ == "__main__":
    desk = Desk()
    desk.description()
    print(desk)
