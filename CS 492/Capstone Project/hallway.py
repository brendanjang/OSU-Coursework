from roomTile import RoomTile

# author: Brendan Jang

# Features in this room:
#   * no special features in this room.
#   * acts as a connector to the different main rooms on the floor


class Hallway(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.name = 'Hallway'
        self.items = []
        self.long_desc = \
            '\nYou reach the third floor. You find yourself standing at '\
            'the southern end of a dark hallway. You notice three ' \
            'closed doors: \n' \
            'Door on the west to your left.\n' \
            'Door on the east to your right.\n' \
            'Door to the north down and the end of the hallway ' \
            'in front of you.\n'
        self.short_desc = '\nYou are in the main hallway of the ' \
                          'third floor. There are doors to the north, east, ' \
                          'and west.\n'
        self.visited = False

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

    def available_actions(self, player, command):
        super().available_actions(player, command)

