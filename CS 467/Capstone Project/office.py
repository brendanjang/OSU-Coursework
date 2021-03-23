from roomTile import RoomTile
from functools import partial

# author: Brendan Jang

# unique player actions in this room:
#   * open left, right, center drawers
#   * open wardrobe
#   * walk in wardrobe
#   * take small key
#   * look at/under desk
#   * look at wardrobe, rug, window
#   * move wardrobe, rug, desk

# Features in this room:
#   * Drawers on the desk the player needs to open in a certain order.
#   * Small key that the player needs to find.
#   * Rug that is a trivial item.
#   * Wardrobe the player must open and walk in to.
#   * Window the player can look out of. It is locked.


class Office(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.light_on = False
        self.name = 'Office'
        self.long_desc = \
            '\nYou walk in to an eerie room that is dimly lit by the ' \
            'moonlight shining through the western window.\n' \
            'In the center of the room is a dusty old rug. It seems ' \
            'like it has been stepped on too many times.\n' \
            'There is an old wooden desk in the room on your right. You ' \
            'notice some faded documents on top of the desk.\n' \
            'As you look to your left, you notice a shadowy figure ' \
            'standing in front of a wardrobe.\n' \
            'You try to get a better look but the figure suddenly ' \
            'disappears right in front of your eyes.\n' \
            'You stand there in disbelief but you must continue trying ' \
            'to escape from this wretched place.\n' \
            'You look around the room to see if the figure has moved, ' \
            'but its really gone...\n' \
            'The only way in and out of the room is through the door ' \
            'you first walked in through to the west.\n'
        self.short_desc = \
            '\nYou are in the office. There is an old desk, rug, and ' \
            'wardrobe in this room. There is a window on the wall to ' \
            'the east. There is a door to the west.\n'

        # list to hold the items in the room
        self.items = [self.rug, self.desk, self.wardrobe]
        self.visited = False

    # public method
    # call method when room is loaded
    # available actions + resulting descriptions
    def turn_light(self):
        self.light_on = True
        light_on_desc = '\nThe lights turn on allowing you to navigate the ' \
                        'room.\n'
        print(light_on_desc)

    def look_desk_desc(self):
        print(self.desk.description())

    # public method
    # the only way to remove item from room is add it to player's inventory
    # this method removes item from room and adds it to the player's inventory
    def remove_item(self, item, player1):
        found = False
        for i in self.items:
            if i.name == item.name:
                found = True
                if i.name == 'small key' or i.name == 'key':
                    if self.desk.hidden_found is False:
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

    def look_under_desk(self):
        if self.desk.hidden_found:
            self.desk.hidden_found_desc()
            self.items.append(self.small_key)
        else:
            self.desk.hidden_not_found()

    @staticmethod
    def no_message():
        print('\nYou cannot go that way.\n')

    @staticmethod
    def no_move():
        print('\nYou cannot do that!\n')

    # the available actions in a room.
    # you will need to call the action from the player class,
    # or maybe action class
    def available_actions(self, player1, command):
        # actions dictionary for room
        # use func tools to pass arguments into dictionary value functions
        actions_dict = {
            'turn on light': self.turn_light,
            'turn on lights': self.turn_light,
            'look at desk': self.look_desk_desc,
            'take desk': self.desk.no_take,
            'move desk': self.desk.no_move,
            'open left drawer': partial(self.desk.open_drawer, 'left drawer'),
            'open right drawer': partial(self.desk.open_drawer,
                                         'right drawer'),
            'open center drawer': partial(self.desk.open_drawer,
                                          'center drawer'),
            'look under desk': partial(self.look_under_desk),
            'look at rug': self.rug.description,
            'move rug': self.rug.move_rug,
            'take rug': self.rug.no_take,
            'look out window': self.window.description,
            'look at window': self.window.description,
            'open window': self.window.locked,
            'look at hidden compartment': self.desk.look_compartment,
            'look at compartment': self.desk.look_compartment,
            'open hidden compartment': self.desk.open_compartment,
            'open compartment': self.desk.open_compartment,
            'look at key': partial(self.look_item, self.small_key, player1),
            'take key': partial(self.remove_item, self.small_key, player1),
            'drop key': partial(self.add_item, self.small_key, player1),
            'look at wardrobe': self.wardrobe.description,
            'open wardrobe': partial(self.wardrobe.open, self.small_key,
                                     player1),
            'get in wardrobe': partial(self.wardrobe.get_in, player1),
            'walk in wardrobe': partial(self.wardrobe.get_in, player1),
            'enter wardrobe': partial(self.wardrobe.get_in, player1),
            'take wardrobe': self.no_move,
            'move wardrobe': self.no_move,
            'go north': self.no_message,
            'move north': self.no_message
        }

        # loop to make sure light is on in room before player gets navigate
        # if command is in dictionary, return appropriate value
        # else return invalid command and prompt again.
        if command == 'turn on light':
            actions_dict[command]()
        elif command in actions_dict.keys() and self.light_on is False:
            print('\nIt is too dark to do anything...\n')
        elif command in actions_dict.keys() and self.light_on is True:
            actions_dict[command]()
        else:
            super().available_actions(player1, command)
