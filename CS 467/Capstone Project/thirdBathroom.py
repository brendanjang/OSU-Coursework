from roomTile import RoomTile
from functools import partial

# author: Brendan Jang

# unique player actions in this room:
#   * look at toilet/sink/shower/tank
#   * take old key
#   * take pills
#   * flush toilet
#   * turn on shower
#   * open mirror

# Features in this room:
#   * Hidden old key that the player must find.
#   * Different objects in bathroom can be interacted with but don't do
#   anything such the toilet/shower/sink.
#   * Door to the west that can only be used after key is found.


class ThirdBathroom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.light_on = False
        self.key_found = False
        self.door_open = False
        self.name = 'ThirdBathroom'
        self.long_desc = \
            'You walk in to a dirty old bathroom that reeks of mold.\n' \
            'There is a cricket chirping somewhere but as you stop ' \
            'walking to inspect the room, the chirping suddenly stops.\n' \
            'It seems as if this bathroom has not been used in ages.\n' \
            'It is dark and you can\'t see much but you can just barely ' \
            'make out some things here.\n' \
            'You can make out a shower with a curtain in front of you to ' \
            'the north.\n'\
            'You can\'t tell because it\'s dark and the curtain is dirty ' \
            'but you think you can see a silhouette of a figure.\n' \
            'There is a sink on the east side of the room. You wonder if ' \
            'it still works.\n'\
            'You can make out a broken mirror above the sink. Maybe ' \
            'there may be something behind it.\n' \
            'There is also a broken down toilet on the east side of the ' \
            'bathroom. Something about it seems off...\n' \
            'There is a door located on the west side of the room. The only ' \
            'way in and out of this bathroom is through that door or ' \
            'the one you walked in through from the south.\n'
        self.short_desc = '\nA dirty bathroom with a shower, toilet, ' \
                          'and sink. There are doors to the west and south.\n'
        self.visited = False

        # list to hold the items in the room
        self.items = [self.pills]

    # available actions + resulting descriptions
    def turn_light(self):
        self.light_on = True
        light_on_desc = '\nThe lights turn on allowing you to navigate the' \
                        ' room.\n'
        print(light_on_desc)

    @staticmethod
    def look_sink():
        look_sink_desc = '\nA dirty old sink of no importance.\n'
        print(look_sink_desc)

    @staticmethod
    def look_mirror():
        look_mirror_desc = '\nA mirror so dirty and broken that you can\'t ' \
                           'make out your reflection.\n'
        print(look_mirror_desc)

    @staticmethod
    def open_mirror():
        open_mirror_desc = '\nYou pull on the mirror revealing the medicine ' \
                           'cabinet behind it. There is nothing but an empty' \
                           ' pill bottle.\n'
        print(open_mirror_desc)

    @staticmethod
    def look_shower():
        look_shower_desc = '\nJust an old shower that does not seem to work.\n'
        print(look_shower_desc)

    @staticmethod
    def turn_shower():
        turn_shower_desc = '\nYou hear water gurgling but nothing happens.\n'
        print(turn_shower_desc)

    @staticmethod
    def turn_sink():
        turn_sink_desc = '\nNothing happens...what\'d you expect?\n'
        print(turn_sink_desc)

    @staticmethod
    def look_toilet():
        look_toilet_desc = '\nA dirty old toilet...something seems off ' \
                           'about it.\n'
        print(look_toilet_desc)

    @staticmethod
    def look_tank():
        look_tank_desc = '\nA dirty toilet water tank.\n'
        print(look_tank_desc)

    def open_tank(self):
        open_tank_desc = '\nYou open the water tank. It holds no water but ' \
                         'there is something taped on the inside. It looks ' \
                         'like an old key\n'
        self.key_found = True
        self.items.append(self.old_key)
        print(open_tank_desc)

    @staticmethod
    def flush():
        flush_desc = '\nFlushing the toilet does nothing...\n'
        print(flush_desc)

    # public method
    # the only way to remove item from room is add it to player's inventory
    # this method removes item from room and adds it to the player's inventory
    def remove_item(self, item, player1):
        found = False
        for i in self.items:
            if i.name == item.name:
                found = True
                if i.name == 'old key' or i.name == 'key':
                    if self.key_found is False:
                        print(f'\nWhat {item} are you talking about?\n')
                    else:
                        self.items.remove(i)
                        print(f"{item} was removed from room.")
                        player1.add_inventory(i)
                else:
                    self.items.remove(i)
                    print(f"{item} was removed from room.")
                    player1.add_inventory(i)
        # If not in room, then:
        if not found:
            print(f"{item} not in room")

    # public method
    # call method when room is loaded
    def room_description(self, player):
        if self.visited:
            print(self.short_desc)
            self.print_items_in_room()
        else:
            self.visited = True
            print(self.long_desc)
            self.print_items_in_room()

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    @staticmethod
    def no_message():
        print('\nYou can not go that way.\n')

    def move_west(self, player):
        if self.key_found is True and self.old_key in player.inventory_list:
            player.move_west()
            self.door_open = True
        elif self.door_open is True:
            player.move_west()
        else:
            print('\nThe door is locked.\n')

    # the available actions in a room.
    # you will need to call the action from the player class,
    # or maybe action class
    def available_actions(self, player1, command):
        # actions dictionary for room
        # use func tools to pass arguments into dictionary value functions
        actions_dict = {
            'look at sink': self.look_sink,
            'look at mirror': self.look_mirror,
            'open mirror': self.open_mirror,
            'look at shower': self.look_shower,
            'turn on shower': self.turn_shower,
            'turn on sink': self.turn_shower,
            'look at toilet': self.look_toilet,
            'look at tank': self.look_tank,
            'open tank': self.open_tank,
            'flush toilet': self.flush,
            'turn on light': self.turn_light,
            'turn on lights': self.turn_light,
            'take pills': partial(self.remove_item, self.pills, player1),
            'drop pills': partial(self.add_item, self.pills, player1),
            'look at pills': partial(self.look_item, self.pills, player1),
            'take key': partial(self.remove_item, self.old_key, player1),
            'drop key': partial(self.add_item, self.old_key, player1),
            'take old key': partial(self.remove_item, self.old_key, player1),
            'drop old key': partial(self.add_item, self.old_key, player1),
            'look at key': partial(self.look_item, self.old_key, player1),
            'look at old key': partial(self.look_item, self.old_key, player1),
            'go east': self.no_message,
            'move east': self.no_message,
            'move west': partial(self.move_west, player1),
            'go west': partial(self.move_west, player1)
        }
        # loop to make sure light is on in room before player gets navigate
        # if command is in dictionary, return appropriate value
        # else return invalid command and prompt again.
        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player1, command)