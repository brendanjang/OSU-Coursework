from roomTile import RoomTile

# author: Brendan Jang

# unique player actions in this room:
#   * look at/move/push shelf
#   * look at/open/close fusebox
#   * flip switches/fuses

# Features in this room:
#   * Rope that player will need later on.
#   * Box that is a trivial items.
#   * Fusebox that the players can look at to see that there is a final secret
#   room.


class FuseRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.name = 'FuseRoom'
        self.long_desc = \
            'You enter into an dark and dusty room that appears to have ' \
            'been used as a storage or janitorial room.\n' \
            'To the left wall, you see an old faded picture but can\'t ' \
            'quite make out what it is.\n' \
            'You see an old and rotting wooden shelf against the north ' \
            'wall of the room.\n' \
            'It seems to have been abandoned here for a long time.\n' \
            'The southern wall is decrepit and breaking down. It might ' \
            'be dangerous to get too close.\n' \
            'There are empty boxes and used cleaning supplies littered ' \
            'throughout the room.\n' \
            'You see a long piece of rope on the ground. It is dusty but ' \
            'but relatively undamaged.\n' \
            'The only way in and out of this room is the door you ' \
            'entered through from the east.\n'
        self.short_desc = \
            '\nYou are in the rundown storage or janitorial room. There is ' \
            'a shelf on the wall and some boxes scattered on the floor. There' \
            'is a door to the east.\n'

        # list to hold the items in the room
        self.items = [self.picture, self.rope, self.box]
        self.fuse_found = False
        self.fuse_flipped = False
        self.fusebox_opened = False
        self.visited = False

    @staticmethod
    def look_fusebox():
        fusebox_desc = '\nIt\'s a fusebox with 3 switches. They are ' \
                       'labelled Art Gallery, Office, and the third is ' \
                       'not labelled.\n'
        print(fusebox_desc)

    @staticmethod
    def look_shelf():
        shelf_desc = '\nAn unused shelf that seems like its out of place.\n'
        print(shelf_desc)

    def push_shelf(self):
        if self.fuse_found is False:
            self.fuse_found = True
            push_shelf_desc = '\nYou move the shelf revealing a fusebox.\n'
            print(push_shelf_desc)
        else:
            print('\nThe shelf won\'t move any farther.\n')

    def flip_fuses(self):
        if self.fuse_found is True:
            self.fuse_flipped = True
            print('\nYou flip all the switches bringing power to '
                  'this floor.\n')
        else:
            print('\nThere are no fuse switches to flip...\n')

    def open_fusebox(self):
        if self.fuse_found is True and self.fusebox_opened is False:
            print('\nYou opened the fusebox revealing some switches.\n')
            self.fusebox_opened = True
        elif self.fuse_found is True and self.fusebox_opened is True:
            print('\nThe fusebox is already opn!\n')
        else:
            print('\nThere is no fusebox to open.\n')

    def close_fusebox(self):
        if self.fuse_found is True and self.fusebox_opened is True:
            self.fusebox_opened = False
            print('\nYou close the fusebox.\n')
        elif self.fuse_found is False:
            print('\nThere is no fusebox to close.\n')
        else:
            print('\nThe fusebox is already closed!\n')

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
        print('\nYou cannot go that way.\n')

    # the available actions in a room.
    # you will need to call the action from the player class,
    # or maybe action class
    def available_actions(self, player, command):
        actions_dict = {
            'look at shelf': self.look_shelf,
            'push shelf': self.push_shelf,
            'move shelf': self.push_shelf,
            'leave room': player.move_south,
            'flip switches': self.flip_fuses,
            'flip fuses': self.flip_fuses,
            'look at fusebox': self.look_fusebox,
            'open fusebox': self.open_fusebox,
            'close fusebox': self.close_fusebox,
            'go south': self.no_message
        }

        # check in room actions dict for command
        # then check roomTile actions for command
        # if command doesnt exist in either then notify
        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player, command)
