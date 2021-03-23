from roomTile import RoomTile
from functools import partial

# author: Jason Watson

# unique player actions in this room:
#   * flip on/off light switch
#   * look at desk
#   * look at bookcase

# Features in this room:
#   * light switches that don't do anything
#   * main feature is the bookcase.  There will be books on here, and the ability to add a book.
#   * desk is the secondary feature.  It is locked.  Ability to add things to desk. If wanted.  Has key to clock.
#   * You will eventually need to implement flashlight for the bookcase.  It is too dark to see anything on the
#       bookcase.



class Library(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "Library"
        self.light_on = False
        self.sitting_on_chair = False
        self.has_book = False
        self.bookcase_open = False
        self.flashlight_on = False
        self.desk_open = False
        self.items = [self.duster]
        self.desk = [self.book]

    # actions available in library

    def turn_on_light(self):
        if not self.sitting_on_chair:
            self.light_on = True
            print("\nYou flip the light switch. Disappointed, it doesn't do anything!\n")
        else:
            print("\nYou will need to get up if you want to do that!")

    def turn_off_light(self):
        if not self.sitting_on_chair:
            self.light_on = False
            print("\nDoesn't do anything.\n")
        else:
            print("\nYou will need to get up if you want to do that!\n")

    def sit_on_chair(self):
        self.sitting_on_chair = True
        print("\nYou sit down. It feels good to be off your feet.\n")

    def get_up_from_chair(self):
        self.sitting_on_chair = False
        print("\nYou get up and stretch your legs. You feel better.\n")

    def look_at_bookcase(self, player1):
        found = False
        for n in player1.inventory_list:
            if n.name == "flashlight":
                if n.isON:
                    found = True

        if found and not self.bookcase_open:
            print("\nIt is a large, bulky bookcase crammed full of books. You scan the titles with your flashlight,\n"
                  "and see that they are all in a strange language you cannot understand. You have never seen\n"
                  "anything remotely like it. As you scan the rows, you notice an empty slot in the center of one\n"
                  "shelves. It looks like it once held a book, and you can see what looks like a lever under this\n"
                  "slot. Perhaps if you the book that goes here, something could happen?\n")
        elif found and self.bookcase_open:
            print("\nIt is a large, bulky bookcase crammed full of books. The small hidden compartment is wide open\n"
                  "right now.\n")
        elif not found:
            print("\nIt is a large, bulky bookcase crammed full of books. It is too dark to make out any other "
                  "details.\n")

    def look_at_desk(self):
        if not self.desk_open:
            print("\nIt is a heavy, wooden desk covered in dust. There is one giant drawer underneath.\n "
                  "The drawer is locked.\n")
        elif self.desk_open:
            print("\nIt is a heavy, wooden desk covered in dust. There is one giant drawer underneath.\n"
                  "The drawer is unlocked.\n")

    def look_in_desk(self):
        if self.desk_open:
            num_items = len(self.desk)
            print(f"\nThere are {num_items} items in the desk: \n")
            for x in range(len(self.desk)):
                print(self.desk[x])
            print("\n")
        elif not self.desk_open:
            print("\nThe desk is locked. You will need to unlock desk.\n")

    @staticmethod
    def look_at_chair():
        print("\nIt is an office chair behind the desk. There is nothing special about it.\n")

    # player will need to check inventory for book. If has book, then can place book in slot on bookcase.
    def add_book_to_bookcase(self, item, player1):
        print(f"\nAttempting to add {item} to desk.\n")
        item_added = False
        for n in player1.inventory_list:
            if n.name == item.name:
                player1.inventory_list.remove(n)
                item_added = True
                print(f"\n{item} was removed from your inventory\n")
        if item_added:
            self.bookcase_open = True
            print("\nYou place the heavy book into the slot and then hear a click. A compartment opens up above the\n"
                  "book. Shining your flashlight, you can see a note taped to the back wall of the compartment.\n"
                  "It says: \"When the clock strikes midnight, only then can you proceed.\" What could that mean?\n")

        elif not item_added:
            print("You will need to find a book to put here!")

    def open_desk(self, player1):
        # check inventory for poker
        found = False
        for i in player1.inventory_list:
            if i.name == "arm":
                found = True
        if found:
            print("\nYou take the arm out of your inventory and try the key. It turns and you hear a click!")
            print("You open the desk.\n")
            self.desk_open = True
        elif not found:
            print("\nYou need to find a key to unlock the desk.\n")

    def add_to_desk(self, item, player1):
        if self.desk_open:
            print(f"\nAttempting to add {item} to desk.\n")
            item_added = False
            for n in player1.inventory_list:
                if n.name == item.name and n not in self.desk:
                    player1.inventory_list.remove(n)
                    self.desk.append(n)
                    item_added = True
                    print(f"\n{item} was removed from your inventory\n")
            if not item_added:
                print(f"\nYou do not have a {item}.\n")

        elif not self.desk_open:
            print("\nThe desk is locked. Find a key!\n")

    def remove_from_desk(self, item, player1):
        if self.desk_open:
            # Check to see if item is in the desk
            found = False
            for i in self.desk:
                if i == item:
                    found = True
                    self.desk.remove(item)
                    print(f"\n{item} was removed from the desk.\n")
                    player1.add_inventory(item)
                    self.check_if_inventory_is_full(item, player1)
            # If not in desk, then:
            if not found:
                print(f"\n{item} not in the desk.\n")
        elif not self.desk_open:
            print("\nThe desk is locked. Find a key!\n")

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    @staticmethod
    def exits_from_room():
        print("\nThere is an exit to the west.\n")

    # public method
    # call method when room is loaded. i.e. darkHall.room_description() when room is loaded.
    def room_description(self, player1):
        # first you will need to determine if the player already visited this room.
        # if visited, then print short description.
        # if not visited, then call long_room_description
        # both long and short description must check to see if there are items in the room.
        # print out the items in the room
        # first check to see if there are items in the room
        if self.visited:
            if len(self.items) == 0:
                print("\n**********Library**********\n"
                      "\nIt's what looks like a library. It is very dark and moonlight streams in from the boarded\n"
                      "up windows along the western wall. You see a bookcase and a tattered couch and chair. You\n"
                      "can see a desk in front of the window. There is a lightswitch to the right of the doorway.\n")

                self.exits_from_room()
            else:
                print("\n**********Library**********\n"
                      "\nIt's what looks like a library. It is very dark and moonlight streams in from the boarded\n"
                      "up windows along the western wall. You see a bookcase and a tattered couch and chair. You\n"
                      "can see a desk in front of the window. There is a lightswitch to the right of the doorway.\n")
                self.print_items_in_room()
                self.exits_from_room()

        else:
            self.visited = True
            if len(self.items) == 0:
                self.long_room_description()
                self.exits_from_room()
            else:
                self.long_room_description()
                self.print_items_in_room()
                self.exits_from_room()

    @staticmethod
    def long_room_description():
        print("\n**********Library**********\n"
              "\nYou enter what looks like a library. The air hangs heavy in this dark room.  It is very dark,\n"
              "but some moonlight streams in from the boarded up windows along the \n"
              "western wall.  There is enough light to make out a bookcase and a tattered\n"
              "couch and chair.  In front of the window, you can make out a desk in \n"
              "the moonlight.  There is a light switch to the right of the doorway.\n")


    def available_actions(self, player1, command):
        # Brendan's actions_dict idea.
        actions_dict = {
            'turn on light': self.turn_on_light,
            'turn on lights': self.turn_on_light,
            'turn off light': self.turn_off_light,
            'turn off lights': self.turn_off_light,
            'sit on chair': self.sit_on_chair,
            'get up from chair': self.get_up_from_chair,
            'look at bookcase': partial(self.look_at_bookcase, player1),
            'look at chair': self.look_at_chair,
            'put book in bookcase': partial(self.add_book_to_bookcase, self.book, player1),
            'look at desk': self.look_at_desk,
            'take book from desk': partial(self.remove_from_desk, self.book, player1),
            'put book in desk': partial(self.add_to_desk, self.book, player1),
            'take batteries from desk': partial(self.remove_from_desk, self.batteries, player1),
            'put batteries in desk': partial(self.add_to_desk, self.batteries, player1),
            'open desk': partial(self.open_desk, player1),
            'look in desk': self.look_in_desk,
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player1, command)
