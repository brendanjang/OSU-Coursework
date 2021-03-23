from roomTile import RoomTile
from functools import partial

# author: Brendan Jang

# unique player actions in this room:
#   * take mirror
#   * put mirror on shrine
#   * put picture on shrine
#   * light candles
#   * look at shrine
#   * press button
#   * tie rope to shrine
#   * climb down rope
#   * go north

# Features in this room:
#   * Shrine that the player must place items on and tie a rope to.
#   * Candles that player must light
#   * Hidden doorway at the north


class HiddenRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.name = 'HiddenRoom'
        self.long_desc = \
            'You walk out of the wardrobe on the other side into a strange ' \
            'and confusing room.\n ' \
            'It seems as if all the little creaks that you heard before are ' \
            'gone, leaving you in complete and utter dead silence.\n' \
            'There are no visible lights for you to turn on in this room. ' \
            'However, there is a circular skylight in the center of the ' \
            'room.\n' \
            'A large beam of moonlight is gleaming in, bringing a faint ' \
            'glow to the whole room.\n' \
            'You walk around and notice that the walls are filled with ' \
            'strange images.\n' \
            'There is a strange shrine in the middle of the room. Maybe ' \
            'you should take a better look.\n' \
            'There is a cracked circular mirror in the corner of the room.\n' \
            'There are no other ways in and out of this room except through ' \
            'the door that you first came in through in the south.\n' \
            'You wonder what secrets this room holds...\n'
        self.short_desc = \
            '\nYou are in secret hidden room with a strange ' \
            'shrine in the middle. The moonlight is shining on it. There is ' \
            'a door to the south.\n'
        self.items = [self.mirror, self.candle, self.shrine]
        self.tied = False
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

    def light(self, item, player):
        lit = False
        for i in player.inventory_list:
            if i.name == item.name:
                lit = True
                self.candle.lit = True
                self.shrine.candles_lit = True
                print(self.shrine.candles_lit_desc())
        if not lit:
            print('\nYou have nothing to light it with.\n')

    def item_to_shrine(self, item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if i.name == 'mirror':
                    self.shrine.items.append(i)
                    player.inventory_list.remove(i)
                    print(self.shrine.mirror_placed_desc())
                    if self.shrine.button_revealed is True:
                        self.items.append(self.button)
                elif i.name == 'third painting':
                    self.shrine.items.append(i)
                    player.inventory_list.remove(i)
                    print(self.shrine.picture_placed_desc())
                    if self.shrine.button_revealed is True:
                        self.items.append(self.button)
                else:
                    self.shrine.items.append(i)
                    print(f'\nYou placed {i} on the shrine.\n')
                    print('\nThat item does not belong here...\n')

    def item_from_shrine(self, item, player):
        for i in self.shrine.items:
            if i.name == item.name and item.name != 'candle':
                player.inventory_list.append(i)
                self.shrine.items.remove(i)
                print(f'\n{i} was removed from the shrine and added to '
                      'your inventory.\n')
            else:
                print('\nYou can\'t do that.\n')

    def press_button(self, shrine):
        if shrine.button_revealed is True:
            shrine.button_pressed = True
            print('\nYou press the button and a hidden door suddenly appears '
                  'on the north side of this room.\n')
        else:
            print('\nThere is no button to press.\n')

    def go_north(self, player):
        if self.shrine.button_pressed is True:
            print('\nYou walk towards the hidden doorway. It looks like an '
                  'incomplete chute of some sort. It seems like you '
                  'will need to get down it somehow...\n')
        else:
            print('\nYou cannot do that!.\n')

    def tie_rope(self, rope, player):
        found = False
        for i in player.inventory_list:
            if i.name == rope.name and self.shrine.button_pressed is True:
                self.tied = True
                found = True
                print('\nYou tie one end of the rope to the shrine and throw '
                      'the other end down the chute.\n')
            elif i.name == rope.name and self.shrine.button_pressed is False:
                self.tied = True
                found = True
                print('\nYou tie one end of the rope to the shrine but you '
                      'have nowhere to put the other end.\n')
        if not found:
            print('\nYou cannot do that yet!\n')

    def climb(self, player):
        if self.tied is True:
            print('\nYou steadily climb down the chute with your rope and '
                  'it come out behind the house. You have finally escaped '
                  'from the wretched mansion.\n'
                  '\nYou have won the game! Thank you for completing our '
                  'haunted mansion escape adventure!\n'
                  '\nThe game will now exit.\n')
            player.won = True
            exit()
        else:
            print('\nYou might want to tie the rope to something before '
                  'climbing down.\n')

    @staticmethod
    def no_message():
        print('\nYou can not go that way.\n')

    @staticmethod
    def deny():
        print('\nYou can not do that!\n')
    # the available actions in a room.
    # you will need to call the action from the player class,
    # or maybe action class
    def available_actions(self, player, command):
        actions_dict = {
            'look at mirror': partial(self.look_item, self.mirror, player),
            'light candles': partial(self.light, self.matches, player),
            'light the candles': partial(self.light, self.matches, player),
            'take candle': self.deny,
            'take candles': self.deny,
            'take shrine' : self.deny,
            'put mirror on shrine': partial(self.item_to_shrine, self.mirror,
                                            player),
            'put first painting on shrine': partial(self.item_to_shrine,
                                                    self.first_pic, player),
            'put second painting on shrine': partial(self.item_to_shrine,
                                                     self.second_pic, player),
            'put third painting on shrine': partial(self.item_to_shrine,
                                                    self.third_pic, player),
            'look at candles': partial(self.look_item, self.candle, player),
            'press button': partial(self.press_button, self.shrine),
            'look at shrine': self.shrine.description,
            'take mirror from shrine': partial(self.item_from_shrine,
                                               self.mirror, player),
            'take mirror off shrine': partial(self.item_to_shrine, self.mirror,
                                              player),
            'take third painting from shrine': partial(self.item_from_shrine,
                                                       self.third_pic, player),
            'take second painting from shrine': partial(self.item_from_shrine,
                                                        self.second_pic,
                                                        player),
            'take first painting from shrine': partial(self.item_from_shrine,
                                                       self.first_pic, player),
            'go west': self.no_message,
            'move west': self.no_message,
            'go north': partial(self.go_north, player),
            'tie rope to shrine': partial(self.tie_rope, self.rope, player),
            'climb down rope': partial(self.climb, player),
            'climb rope': partial(self.climb, player)
        }

        # check in room actions dict for command
        # then check roomTile actions for command
        # if command doesnt exist in either then notify
        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player, command)
