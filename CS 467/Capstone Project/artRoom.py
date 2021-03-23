from roomTile import RoomTile
from functools import partial

# author: Brendan Jang

# unique player actions in this room:
#   * take, look at, drop first, second, third paintings, matches

# Features in this room:
#   * three unique paintings to look at with different descriptions that are
#   clues
#   * matches that the player will need to keep in inventory for final puzzle


class ArtRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.trigger = False
        self.name = 'ArtRoom'
        self.long_desc = \
            'You walk into an extravagant art gallery. Moonlight shines ' \
            'into the room from a large skylight, revealing many ' \
            'priceless works of art on the walls.\n' \
            'These pieces of art are fancy and all of them catch your ' \
            'eye. However, there are three that particularly stand out ' \
            'because they seem out of place.\n' \
            'You can\'t quite make out what they are from where you ' \
            'stand.\n' \
            'The first painting in front of you on the western wall ' \
            'is in a cheap beat up frame. It must not have been of ' \
            'great importance.\n' \
            'The second painting to your left on the southern wall ' \
            'is held in a beautiful golden frame. It appears as if it ' \
            'must have been of great importance.\n' \
            'The final painting is to your right on the northern wall ' \
            'of the room. This painting does not have a frame.\n' \
            'It appears nobody cared for this piece at all.\n' \
            'Each of these paintings are placed in the center of ' \
            'their respective walls. It appears someone has ' \
            'deliberately placed them there.\n' \
            'The only entrance in and out of this room is through the ' \
            'door you walked in to on the east side of the room.\n'
        self.short_desc = \
            '\nYou are in the extravagant art gallery that holds all ' \
            'the paintings. There is a door to the east.\n'
        self.visited = False

        # list to hold the items in the room
        self.items = [self.first_pic, self.second_pic, self.third_pic]

    @staticmethod
    def trigger_desc():
        print('\nYou see a small bundle of matches fall to the floor. You '
              'hear a click somewhere on this floor. It sounds like '
              'something being unlocked...\n')

    def look_at_pic(self, item, player):
        item_found = False
        for n in player.inventory_list:
            if n.name == item.name:
                item_found = True
                print(n.description())
        for x in self.items:
            if x.name == item.name:
                item_found = True
                print(x.description())
        if not item_found:
            print(f"\nYou do not have a {item}.\n")

    # public method
    # the only way to remove item from room is add it to player's inventory
    # this method removes item from room and adds it to the player's inventory
    def remove_item(self, item, player):
        item_removed = False
        for n in self.items:
            if n.name == item.name and n not in player.inventory_list:
                if n.name == 'third painting':
                    self.items.append(self.matches)
                    self.trigger_desc()
                    self.trigger = True
                player.inventory_list.append(n)
                self.items.remove(n)
                item_removed = True
                print(f"\n{item} was added to your inventory\n")
        if not item_removed:
            print(f"\nThere is no {item} here.\n")

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
    def available_actions(self, player1, command):
        # actions dictionary for room
        # use func tools to pass arguments into dictionary value functions
        actions_dict = {
            'look at first painting': partial(self.look_at_pic,
                                              self.first_pic, player1),
            'look at second painting': partial(self.look_at_pic,
                                               self.second_pic, player1),
            'look at third painting': partial(self.look_at_pic,
                                              self.third_pic, player1),
            'take first painting': partial(self.remove_item, self.first_pic,
                                           player1),
            'drop first painting': partial(self.add_item, self.first_pic,
                                           player1),
            'take second painting': partial(self.remove_item,
                                            self.second_pic, player1),
            'drop second painting': partial(self.add_item,
                                            self.second_pic, player1),
            'take third painting': partial(self.remove_item, self.third_pic,
                                           player1),
            'drop third painting': partial(self.add_item, self.third_pic,
                                           player1),
            'go north': self.no_message,
            'move north': self.no_message
        }

        # if command is in dictionary, return appropriate value
        # else return invalid command and prompt again.
        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player1, command)
