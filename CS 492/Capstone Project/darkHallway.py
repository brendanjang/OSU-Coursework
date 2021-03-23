from roomTile import RoomTile
from functools import partial
import time

# author: Jason Watson

# unique player actions in this room:
#   * open/close door
#   * flip on/off light switch
#   * look at table. Put item on table.
#   * look at fern.  Take fern. Useless item.
#   * look at clock. Open clock.

# Features in this room:
#   * light switches that don't do anything
#   * open/close door
#   * side table with fake fern and music box
#   * grandfather clock at end of hallway. You can change the time? Open it up for secret corridor to next level.


class DarkHallway(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "Dark Hallway"
        self.items = []
        self.table = [self.music_box]
        self.light_on = False
        self.door_is_open = False
        self.clock_is_open = False
        self.num_items_on_table = 1
        self.time_on_clock = 3

    # actions available in living room
    def open_door(self):
        if self.door_is_open:
            print("\nThe door is already open!\n")
        elif not self.door_is_open:
            self.door_is_open = True
            print("\nYou open the door.\n")

    def close_door(self):
        if self.door_is_open:
            self.door_is_open = False
            print("\nYou close the door.\n")
        elif not self.door_is_open:
            print("\nThe door is already closed!\n")

    # this method adds item to table while removing said item from inventory
    def add_item_to_table(self, item, player1):
        print(f"\nAttempting to add {item} to table")
        item_added = False
        for n in player1.inventory_list:
            if n.name == item.name and n not in self.table:
                player1.inventory_list.remove(n)
                self.table.append(n)
                item_added = True
                print(f"\n{item} was removed from your inventory\n")
        if not item_added:
            print(f"\nYou do not have a {item}.\n")

    # method to remove item from table and add item to player inventory
    def remove_item_from_table(self, item, player1):
        print(f"\nAttempting to remove {item} from table.\n")
        item_removed = False
        for n in self.table:
            if n.name == item.name and n not in player1.inventory_list:
                player1.inventory_list.append(n)
                self.table.remove(n)
                item_removed = True
                print(f"\n{item} was added to your inventory\n")
        if not item_removed:
            print(f"\nThere is no {item} here.\n")

    # this is not working correctly! Prints 0 items on table.
    def look_at_table(self):
        print("\nA side table.\n")
        if not self.table:
            print("\nThere is nothing on the table.\n")
        else:
            num_items = len(self.table)
            print(f"\nThere are {num_items} items on the table: \n")
            for x in range(len(self.table)):
                print(self.table[x])

    @staticmethod
    def look_at_rug():
        print("\nAn old, faded rug. Nothing special about it.\n")
        pass

    def look_at_clock(self):
        if not self.clock_is_open:
            print("\nA giant clock stands against the end of the hallway. It is very ornate and old. It doesn't\n"
                  f"appear to be working with the time stuck at {self.time_on_clock} o'clock. It looks like it might\n"
                  "open up, but you cannot see any means to open it. Perhaps you should explore some more.\n")
        elif self.clock_is_open:
            print("\nA giant clock stands against the end of the hallway. It is very ornate and old. It doesn't\n"
                  f"appear to be working with the time stuck at {self.time_on_clock} o'clock. It lies open, the doors\n"
                  "swung wide open. You can see stairs leading up.\n")

    def look_at_door(self):
        if self.door_is_open:
            print("\nThe door is open.\n")
        elif not self.door_is_open:
            print("\nThe door is closed. It is a normal looking door. It is unlocked.\n")


    @staticmethod
    def look_at_chandelier():
        print("\nIt is a crystal chandelier, swinging from the ceiling. It is too high up to make out any more"
              " details, or to reach.")

    def open_clock(self):
        if not self.clock_is_open:
            print("\nYou cannot see any means to open the clock. It doesn't matter what you do, it remains closed.\n")
        elif self.clock_is_open:
            print("\nThe clock is already open. It looks like you can head up to the next level.\n")

    def close_clock(self):
        if not self.clock_is_open:
            print("\nThe clock is not open.\n")
        elif self.clock_is_open:
            print("\nThe clock is open. You cannot seem to close it.\n")

    # final puzzle of the level. This will change the time on the clock.
    # boundary check is made on time. Cannot enter a time less than 1 and greater than 12.
    def change_time_on_clock(self, player1):
        print(f"\nThe current time is {self.time_on_clock} o'clock.\n")
        print("\nYou change the time. (Please enter an integer between 1 and 12.)\n")
        self.time_on_clock = input("\nWhat time would you like to enter?\n")
        while int(self.time_on_clock) > 12 or int(self.time_on_clock) < 1:
            print("\nPlease enter a valid time.\n")
            self.time_on_clock = input("\nWhat time would you like to enter?\n")
        print(f"\nYou change the time to {self.time_on_clock} o'clock\n")
        if int(self.time_on_clock) == 12:
            print("\nYou hear a click and a rumbling. The clock opens wide, showing stairs up!\n")

            print("\nCongratulations, you have cleared the second floor!\n")
            print("\nYou are moving up to the third floor, good luck!\n")

            player1.update_current_floor("floor3")
            time.sleep(5)
            # change location to first room on third floor
            player1.x = 1
            player1.y = 1
        elif int(self.time_on_clock) != 12:
            print("\nIt doesn't do anything.\n")

    # private method
    def is_door_open(self):
        if self.door_is_open:
            print("\nThe door to the west is open.\n")
        elif not self.door_is_open:
            print("\nThe door to the west is closed.\n")

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    @staticmethod
    def exits_from_room():
        print("\nThere is a door to the west and an open entrance to the south.\n")

    # public method
    # call method when room is loaded, or look command typed.
    def room_description(self, player1):
        # first you will need to determine if the player already visited this room.
        # if visited, then print short description.
        # if not visited, then call long_room_description
        # both long and short description must check to see if there are items in the room.
        # print out the items in the room
        # first check to see if there are items in the room
        if self.visited:
            if len(self.items) == 0:
                print("\n**********Dark Hallway**********\n"
                      "It is still dark and eerie.  A giant rug covers the floor\n"
                      "and a dust covered chandelier sways above. A tall grandfather clock lies directly ahead\n"
                      "at the end of the hallway.  There is a side table along the right side of the hallway.\n")
                self.exits_from_room()
                self.is_door_open()
            else:
                print("\n**********Dark Hallway**********\n"
                      "It is still dark and eerie.  A giant rug covers the floor\n"
                      "and a dust covered chandelier sways above. A tall grandfather clock lies directly ahead\n"
                      "at the end of the hallway.  There is a side table along the right side of the hallway.\n")
                self.exits_from_room()
                self.is_door_open()
                self.print_items_in_room()

        else:
            self.visited = True
            if len(self.items) == 0:
                self.long_room_description()
                self.exits_from_room()
                self.is_door_open()
            else:
                self.long_room_description()
                self.exits_from_room()
                self.is_door_open()
                self.print_items_in_room()

    @staticmethod
    def long_room_description():
        print("\n**********Dark Hallway**********\n"
              "It is quite dark and eerie, with no light source. You\n"
              "briefly hear the sound of footsteps upstairs.  A giant rug covers the floor\n"
              "and hanging overhead is a chandelier that sways briefly, making a clattering\n"
              "sound. A tall clock lies directly ahead, at the end of the hallway,\n"
              "making a faint click clock sound.  There is a side table along the right side of\n"
              "the hallway.\n")

    def available_actions(self, player1, command):

        # Brendan's actions_dict idea.
        actions_dict = {
            'open door': self.open_door,
            'close door': self.close_door,
            'look at table': self.look_at_table,
            'look at rug': self.look_at_rug,
            'look at clock': self.look_at_clock,
            'look at door': self.look_at_door,
            'look at chandelier': self.look_at_chandelier,
            'open clock': self.open_clock,
            'close clock': self.close_clock,
            'take music box from table': partial(self.remove_item_from_table, self.music_box, player1),
            'put music box on table': partial(self.add_item_to_table, self.music_box, player1),
            'change time on clock': partial(self.change_time_on_clock, player1),
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        elif command == "go west":
            if self.door_is_open:
                player1.move_west()
            elif not self.door_is_open:
                print("\nYou will need to open the door!\n")
                player1.move_east()
        else:
            super().available_actions(player1, command)


if __name__ == "__main__":
    print(RoomTile)