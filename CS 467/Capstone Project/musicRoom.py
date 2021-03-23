from roomTile import RoomTile
from functools import partial

# author: Jason Watson

# unique player actions in this room:
#   * play piano
#   * look at piano
#   * open and play music box
#   * look at cello
#   * look at chairs
#   * look at window
#   * look at fireplace
# Features in this room:
#   * grand piano
#   * fireplace
#   * chairs
#   * cello
#   * giant window (boarded up)


class MusicRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "Music Room"
        self.door_is_open = False
        self.is_sitting = False
        self.light_on = False
        self.fireplace_disturbed = False
        self.items = [self.poker]

    # actions available in music room

    @staticmethod
    def look_at_piano():
        print("\nIt is an old-fashioned Steinway grand piano that looks expensive if it was cared for.\n"
              "It looks like it hasn't been dusted or maintained for years.\n")

    @staticmethod
    def look_at_cello():
        print("\nIt is an old cello, standing upright on it's stand.\n")

    def turn_on_light(self):
        self.light_on = True
        print("\nYou flip the light switch. Disappointed, it doesn't do anything!\n")

    def turn_off_light(self):
        self.light_on = False
        print("\nDoesn't do anything.\n")

    def look_at_fireplace(self):
        if not self.fireplace_disturbed:
            print("\nIt is a grand fireplace. There is a pile of ashes in the center of the grate. At one time\n"
                  "it would have warmed up the entire room. Now it just sits, cold and useless in this room.\n")
        elif self.fireplace_disturbed:
            print("\nIt is a grand fireplace. The ash pile has been spread out, old embers scattered on the grate.\n")

    def look_in_fireplace(self):
        if not self.is_sitting:
            if not self.fireplace_disturbed:
                print("\nThe ash pile looks imposing. If only you had something to use to stir it. Maybe there will"
                      " be something there to see.\n")
            elif self.fireplace_disturbed:
                print("\nThe ash pile has been spread out, old embers scattered on the grate.\n")
        elif self.is_sitting:
            print("\nYou will need to get up to do that!\n")

    def look_at_door(self):
        if self.door_is_open:
            print("\nThe door is open.\n")
        elif not self.door_is_open:
            print("\nIt is a large, ornate looking door. There appears to be no doorknob or keyhole.\n"
                  "You wonder how to open this door. Maybe the clue lies in the room somewhere.\n")

    # method stirs the ash. Checks for poker in inventory, and checks whether ash was already stirred.
    def stir_ash_with_poker(self, item, player1):
        # check inventory for poker
        found = False
        if self.poker in player1.inventory_list:
            found = True
        # if poker is in inventory, then:
        if found and not self.fireplace_disturbed:
            # if poker is in inventory, then:
            self.fireplace_disturbed = True
            print("\nYou take the poker out of inventory and poke and stir the ash in the fireplace. You\n"
                  "notice something! It looks like a partially burnt note. You pick it up and put it into your"
                  " inventory.\n")
            player1.add_inventory(self.note)
            self.check_if_inventory_is_full(item, player1)
        elif not self.fireplace_disturbed and not found:
            print("\nYou will need something to stir the ash with.\n")
        elif self.fireplace_disturbed:
            print("\nThe ash is already spread out. You can see embers but nothing else.\n")

    @staticmethod
    def look_at_window():
        print("\nIt is a large, boarded up window. The boards seem to be nailed in place, and there is no\n"
              "way to pry them loose.\n")

    def sit_in_chair(self):
        if not self.is_sitting:
            print("\nYou sit down in front of the piano. It feels good to be off your feet. Now, maybe if you knew\n"
                  "something you can play on the piano.\n")
        elif self.is_sitting:
            print("\nYou are already sitting!\n")

    def sit_on_couch(self):
        if not self.is_sitting:
            print("\nYou sit on the couch. It feels comfortable.\n")
        elif self.is_sitting:
            print("\nYou are already sitting!\n")

    def play_piano(self):
        if self.music_box.music_box_open:
            print("\nYou try to mimic the music you heard on the music box. It took a few times but you managed\n"
                  "to copy the simple tune. You hear a click and the door slowly opens with a creak.\n")
            self.door_is_open = True
        elif not self.music_box.music_box_open:
            print("\nYou play some chords.  You don't know any music to try and play. Maybe search around for something"
                  " to play.\n")

    @staticmethod
    def play_cello():
        print("\nThere is nothing to play the cello with.\n")

    def open_door(self):
        if self.door_is_open:
            print("\nThe door is already open.\n")
        elif not self.door_is_open:
            print("\nYou try to push the door open. It doesn't do anything. There is no doorknob. How do you open"
                  " it?\n")

    def close_door(self):
        if self.door_is_open:
            print("\nThe door doesn't budge. It won't close.\n")
        elif not self.door_is_open:
            print("\nThe door is already closed!\n")

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    # private method
    def is_door_open(self):
        if self.door_is_open:
            print("\nThe door to the east is open.\n")
        elif not self.door_is_open:
            print("\nThe door to the east is closed.\n")

    @staticmethod
    def exits_from_room():
        print("\nThere is a door to the east and an open entrance to the north.\n")

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
                print("\n**********Music Room**********\n"
                      "\nA music room. The piano is in the corner of the room.\n"
                      "There is a large, boarded up window on the south wall.\n"
                      "There is a fireplace on the west wall and a couch in the\n"
                      "center of the room. There is a chair in front of the piano.\n")
                self.exits_from_room()
                self.is_door_open()
            else:
                print("\n**********Music Room**********\n"
                      "\nA music room. The piano is in the corner of the room.\n"
                      "There is a large, boarded up window on the south wall.\n"
                      "There is a fireplace on the west wall and a couch in the\n"
                      "center of the room. There is a chair in front of the piano.\n")
                self.print_items_in_room()
                self.exits_from_room()
                self.is_door_open()

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
        print("\n**********Music Room**********\n"
              "\nAs soon as you enter the room, you hear the sound of\n"
              "a piano playing a melancholic tune.  Panicked, you look\n"
              "around and see a piano in the corner of a large dark room.\n"
              "You can see the key's being pressed, and the tune is an old\n"
              "classical Mozart sonata. It quickly stops playing itself,\n"
              "and the eerie silence that follows has the faint echo of\n"
              "the melancholy tune still floating in the air.\n"
              "There is a large, boarded up window to the south.\n"
              "Moonlight filters into the room through cracks in the boards,\n"
              "On the west wall, you can see\n"
              "a fireplace.  There is a couch in the center of the room and a\n"
              "chair in front of the piano.\n")

    # the available actions in a room.
    # you will need to call the action from the player class, or maybe action class
    def available_actions(self, player1, command):

        # Brendan's actions_dict idea.
        actions_dict = {
            'turn on light': self.turn_on_light,
            'turn on lights': self.turn_on_light,
            'turn off light': self.turn_off_light,
            'turn off lights': self.turn_off_light,
            'look at piano': self.look_at_piano,
            'look at cello': self.look_at_cello,
            'look at fireplace': self.look_at_fireplace,
            'look in fireplace': self.look_in_fireplace,
            'look at door': self.look_at_door,
            'look at window': self.look_at_window,
            'sit in chair': self.sit_in_chair,
            'sit on couch': self.sit_on_couch,
            'play piano': self.play_piano,
            'play cello': self.play_cello,
            'open door': self.open_door,
            'close door': self.close_door,
            'stir ash with poker': partial(self.stir_ash_with_poker, self.note, player1),
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        elif command == "go east":
            if self.door_is_open:
                player1.move_east()
            elif not self.door_is_open:
                print("\nYou will need to open the door!")
                self.room_description(player1)
        else:
            super().available_actions(player1, command)
