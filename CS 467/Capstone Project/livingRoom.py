from roomTile import RoomTile
from functools import partial

# author: Jason Watson

# unique player actions in this room:
#   * sit on couch
#   * lie on couch
#   * sit on rocking chair
#   * put cassette in tape recorder: check inventory for cassette tape
#   * play recorder: check whether cassette tape is in recorder
#   * remove cassette from tape recorder: add cassette tape to inventory
#   * open/close door
#   * flip on/off light switch

# Features in this room:
#   * flashlight required to see any features in this room.  Still need to figure out how to make this work.
#   * light switch that doesn't work
#   * couch and coffee table.  A tape recorder lies on the coffee table.


class LivingRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "Living Room"
        self.light_on = False
        self.door_is_open = True
        self.recorder_with_tape = False
        self.sitting_in_rocking_chair = False
        self.sitting_on_couch = False
        self.lying_on_couch = False
        self.items = [self.recorder]

    # actions available in living room

    def turn_on_light(self):
        if not self.lying_on_couch and not self.sitting_on_couch and not self.sitting_in_rocking_chair:
            self.light_on = True
            print("\nYou flip the light switch. Disappointed, it doesn't do anything!\n")
        else:
            print("\nYou will need to get up if you want to do that!\n")

    def turn_off_light(self):
        if not self.lying_on_couch and not self.sitting_on_couch and not self.sitting_in_rocking_chair:
            self.light_on = False
            print("\nDoesn't do anything.\n")
        else:
            print("\nYou will need to get up if you want to do that!\n")

    @staticmethod
    def look_at_rocking_chair():
        print("\nIt is a rocking chair.  Thankfully, it is not moving now.\n")

    def sit_in_rocking_chair(self):
        self.sitting_in_rocking_chair = True
        print("\nYou sit down. It is as comfortable as you would expect a wooden rocking chair to be.\n")

    def look_at_door(self):
        if self.door_is_open:
            print("\nThe door is open.\n")
        elif not self.door_is_open:
            print("\nThe door is closed. It is a normal looking door. It is unlocked.\n")

    @staticmethod
    def look_at_couch():
        print("\nIt is an old and worn couch.\n")

    def sit_on_couch(self):
        self.sitting_on_couch = True
        print("\nYou sit down.  It is not comfortable at all.  Still, it feels good to be off your feet!\n")

    def lie_on_couch(self):
        self.lying_on_couch = True
        print("\nYou lie down.  It is not comfortable at all.  You begin to doze.\n")

    def get_up_from_chair(self):
        self.sitting_in_rocking_chair = False
        print("\nYou stand up.\n")

    def get_up_from_couch(self):
        self.sitting_on_couch = False
        print("\nYou stand up.\n")

    @staticmethod
    def look_at_table():
        print("\nIt is a table.  There is a tape recorder on top of it.\n")

    @staticmethod
    def look_at_tv():
        print("\nIt is an old TV from the 1950s.  It looks like it hasn't been in use for decades.\n")

    @staticmethod
    def turn_on_tv():
        print("\nYou turn the TV on.  It doesn't do anything.\n")

    @staticmethod
    def look_at_tv_stand():
        print("\nIt's just a small table. There is nothing else on or around it of interest.\n")

    def play_recorder(self):
        if self.recorder.tape_in_recorder:
            self.recorder.play_recorder()
        else:
            print("You will need to find a cassette tape.")

    def look_at_recorder(self):
        self.recorder.description()

    # remove cassette from inventory. Put cassette into tape recorder.
    # check inventory for cassette tape
    def put_cassette_in_recorder(self, item, player1):
        self.recorder.add_tape(item, player1)

    # add cassette to inventory. Remove cassette from tape recorder.
    def take_cassette_from_recorder(self, item, player1):
        self.recorder.remove_tape(item, player1)

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

    def is_door_open(self):
        if self.door_is_open:
            print("\nThe door to the east is open.\n")
        elif not self.door_is_open:
            print("\nThe door to the east is closed.\n")

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    @staticmethod
    def exits_from_room():
        print("\nThere is a door to the east and an open entrance to the south.\n")

    # public method
    # call method when room is loaded. i.e. darkHall.room_description() when room is loaded.
    def room_description(self, player1):
        # first you will need to determine if the player already visited this room.
        # if visited, then print short description.
        # if not visited, then call long_room_description
        # both long and short description must check to see if there are items in the room.
        # print out the items in the room
        # first check to see if there are items in the room
        # you will need to eventually implement flashlight on method here.
        if self.visited:
            if len(self.items) == 0:
                print("\n**********Living Room**********\n"
                      "\nIt looks like a living room. There is a rocking chair in the corner, facing a boarded up\n"
                      "window. There is an old couch in the center of the room, and a coffee table in front of the\n"
                      "couch. There is what looks like a recorder on the table. Under the couch and coffee table is\n"
                      "a large woolen rug that has seen better days.\n"
                      "There is a light switch to the right of the doorway. There is an old TV leaning against\n"
                      "the wall on a TV stand.\n")
                self.is_door_open()
                self.exits_from_room()
            else:
                print("\n**********Living Room**********\n"
                      "\nIt looks like a living room. There is a rocking chair in the corner, facing a boarded up\n"
                      "window. There is an old couch in the center of the room, and a coffee table in front of the\n"
                      "couch. Under the couch and coffee table is a large woolen rug that has seen better days.\n"
                      "There is a light switch to the right of the doorway. There is an old TV leaning against\n"
                      "the wall on a TV stand.\n")
                self.is_door_open()
                self.print_items_in_room()
                self.exits_from_room()

        else:
            self.visited = True
            if len(self.items) == 0:
                self.long_room_description()
                self.is_door_open()
                self.exits_from_room()
            else:
                self.long_room_description()
                self.is_door_open()
                self.print_items_in_room()
                self.exits_from_room()

    def long_room_description(self):
        print("\n**********Living Room**********\n"
              "\nYou are in a living room. It is a dark room.  You can see a rocking chair creaking \n"
              "and rocking back and forth in the corner of the room, facing a boarded \n"
              "up window.  The creaking quickly stops when the player notices it. There \n"
              "is an old couch in the center of the room, and a coffee table in \n"
              "front of the couch.  Under the couch and coffee table is a large woolen rug that has seen better\n"
              "days. There is a light switch to the right of the doorway. The rocking chair is\n"
              "in the corner of the room. There is also an old TV set that looks like it's from the 1950s.\n"
              "It leans against the wall on a TV stand.\n")

    def available_actions(self, player1, command):

        # Brendan's actions_dict idea.
        actions_dict = {
            'turn on light': self.turn_on_light,
            'turn off light': self.turn_off_light,
            'open door': self.open_door,
            'close door': self.close_door,
            'look at recorder': self.look_at_recorder,
            'look at table': self.look_at_table,
            'look at chair': self.look_at_rocking_chair,
            'sit in chair': self.sit_in_rocking_chair,
            'look at couch': self.look_at_couch,
            'sit on couch': self.sit_on_couch,
            'lie on couch': self.lie_on_couch,
            'get up from chair': self.get_up_from_chair,
            'get up from couch': self.get_up_from_couch,
            'look at tv': self.look_at_tv,
            'turn on tv': self.turn_on_tv,
            'look at tv stand': self.look_at_tv_stand,
            'look at door': self.look_at_door,
            'put cassette tape in recorder': partial(self.put_cassette_in_recorder, self.tape, player1),
            'take cassette tape from recorder': partial(self.take_cassette_from_recorder, self.tape, player1),
            'play recorder': self.play_recorder,
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        elif command == "go east":
            if self.door_is_open:
                player1.move_east()
            elif not self.door_is_open:
                print("\nYou will need to open the door!\n")
                self.room_description(player1)
        else:
            super().available_actions(player1, command)
