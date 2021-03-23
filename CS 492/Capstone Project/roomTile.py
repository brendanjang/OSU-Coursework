from functools import partial
from musicBox import MusicBox
from poker import Poker
from duster import Duster
from book import Book
from note import Note
from recorder import Recorder
from tape import Tape
from watch import Watch
from arm import Arm
from flashlight import Flashlight
from coat import Coat
from scarf import Scarf
from shovel import Shovel
from bucket import Bucket
from batteries import Batteries
from batteries2 import Batteries2
from key import Key
from ribs import Ribs
from waterbottle import WaterBottle
from mirror import Mirror
from shrine import Shrine
from picture import FirstPicture
from picture import SecondPicture
from picture import ThirdPicture
from pills import Pills
from oldKey import OldKey
from window import Window
from rug import Rug
from key import SmallKey
from desk import Desk
from wardrobe import Wardrobe
from picture import Picture
from box import Box
from rope import Rope
from matches import Matches
from button import Button
from candle import Candle
import pickle
import room


# Room superclass
class RoomTile:

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.items = []
        self.arm = Arm()
        self.music_box = MusicBox()
        self.poker = Poker()
        self.duster = Duster()
        self.book = Book()
        self.recorder = Recorder()
        self.note = Note()
        self.tape = Tape()
        self.watch = Watch()
        self.shovel = Shovel()
        self.bucket = Bucket()
        self.batteries = Batteries()
        self.batteries2 = Batteries2()
        self.key = Key()
        self.ribs = Ribs()
        self.water_bottle = WaterBottle()
        self.coat = Coat()
        self.scarf = Scarf()
        self.flashlight = Flashlight()
        self.mirror = Mirror()
        self.shrine = Shrine()
        self.first_pic = FirstPicture()
        self.second_pic = SecondPicture()
        self.third_pic = ThirdPicture()
        self.old_key = OldKey()
        self.pills = Pills()
        self.window = Window()
        self.rug = Rug()
        self.desk = Desk()
        self.small_key = SmallKey()
        self.wardrobe = Wardrobe()
        self.picture = Picture()
        self.matches = Matches()
        self.box = Box()
        self.rope = Rope()
        self.button = Button()
        self.candle = Candle()

    # this method removes item from inventory and places it in the room
    def add_item(self, item, player):
        item_added = False
        for n in player.inventory_list:
            if n.name == item.name and n not in self.items:
                player.inventory_list.remove(n)
                self.items.append(n)
                item_added = True
                print(f"\n{item} was removed from your inventory\n")
        if not item_added:
            print(f"\nYou do not have a {item}.\n")

    # public method
    # the only way to remove item from room is add it to player's inventory
    # this method removes item from room and adds it to the player's inventory
    def remove_item(self, item, player):
        item_removed = False
        for n in self.items:
            if n.name == item.name and n not in player.inventory_list:
                player.inventory_list.append(n)
                self.check_if_inventory_is_full(item, player)
                self.items.remove(n)
                item_removed = True
                print(f"\n{item} was added to your inventory\n")
        if not item_removed:
            print(f"\nThere is no {item} here.\n")

    # private method to check inventory length. If inventory is full, then item is removed from inventory and placed
    # in the room.
    def check_if_inventory_is_full(self, item, player):
        if len(player.inventory_list) > 10:
            print("\nYour bag is full! You will need to drop something.\n")
            self.add_item(item, player)
            return

    def room_description(self, player):
        pass

    # Function to change the flashlight batteries.
    @staticmethod
    def change_batteries(flashlight, batteries, player):
        # Check if the player has a flashlight
        hasFlashlight = False
        hasBatteries = False
        for item_1 in player.inventory_list:
            if item_1.name == flashlight.name:
                hasFlashlight = True
                # Check if the player has batteries.
                for item_2 in player.inventory_list:
                    if item_2.name == batteries.name:
                        hasBatteries = True
                        # Change batteries.
                        item_1.change_batteries(item_2)

        if not hasFlashlight:
            print(f"\nYou do not have a {flashlight}.\n")
        elif not hasBatteries:
            print(f"\nYou do not have {batteries}.\n")


    # Function to turn ON the flashlight.
    @staticmethod
    def turn_on_flashlight(item, player):
        for n in player.inventory_list:
            if n.name == item.name:
                n.turn_on()
                break
        else:
            print(f"\nYou do not have a {item}.\n")

    # Function to turn OFF the flashlight.
    @staticmethod
    def turn_off_flashlight(item, player):
        for n in player.inventory_list:
            if n.name == item.name:
                n.turn_off()
                break
        else:
            print(f"\nYou do not have a {item}.\n")

    def open_music_box(self, player):
        # check inventory for music box
        found = False
        for i in player.inventory_list:
            if i.name == "music box":
                found = True
        if found:
            self.music_box.open_music_box()
        elif not found:
            print("What music box?")

    def close_music_box(self, player):
        # check inventory for music box
        found = False
        for i in player.inventory_list:
            if i.name == "music box":
                found = True
        if found:
            self.music_box.close_music_box()
        elif not found:
            print("What music box?")

    # author: Jason Watson
    # dumps player and room data into text files.
    # I got help from: https://stackoverflow.com/questions/18606097/python-text-game-how-to-make-a-save-feature
    def save_game(self, player, room):
        while True:
            # Confirm that the player wants to save the game
            player_input = input("Would you like to save this game? yes/no\n").lower()
            if player_input == "no" or player_input == "n":
                # Return the player to the game loop
                print("returning...")
                return
            elif player_input == "yes" or player_input == "y":
                # Save the game and exit
                pickle.dump(player, open('data.txt', 'wb'))
                if player.current_floor == 'floor1':
                    pickle.dump(room.floor1_map, open('room_data.txt', 'wb'))
                elif player.current_floor == 'floor2':
                    pickle.dump(room.floor2_map, open('room_data.txt', 'wb'))
                elif player.current_floor == 'floor3':
                    pickle.dump(room.floor3_map, open('room_data.txt', 'wb'))
                print("game saved!")
                return
            else:
                print("\nInvalid entry, please try again.\n")

    # author: Jason Watson
    # this loads player data, location and room data for saved level. It uses pickle.load to parse and store map
    # and player data in player and room objects.
    # I got help from: https://stackoverflow.com/questions/18606097/python-text-game-how-to-make-a-save-feature
    def load_game(self, player, room):
        # open file, load player and room stats and continue
        print("loading game...")
        if player.current_floor == 'floor1':
            with open('room_data.txt', 'rb') as f:
                room.floor1_map = pickle.load(f)
        elif player.current_floor == 'floor2':
            with open('room_data.txt', 'rb') as f:
                room.floor2_map = pickle.load(f)
        elif player.current_floor == 'floor3':
            with open('room_data.txt', 'rb') as f:
                room.floor3_map = pickle.load(f)

        data = pickle.load(open('data.txt', 'rb'))

        rooms_visited = data.rooms_visited
        current_floor = data.current_floor
        inventory_list = data.inventory_list
        won = data.won
        loaded_room = rooms_visited[-1]
        x = loaded_room.x
        y = loaded_room.y
        # load the data into current player object
        player.rooms_visited = rooms_visited
        player.current_floor = current_floor
        player.inventory_list = inventory_list
        player.won = won
        player.x = x
        player.y = y

        return

    def look_item(self, item, player):
        item_found = False
        for n in player.inventory_list:
            if n.name == item.name:
                item_found = True
                n.description()
        if not item_found:
            for x in player.rooms_visited[-1].items:
                if x.name == item.name:
                    item_found = True
                    x.description()
        if not item_found:
            print(f"\nThere is no {item} to look at.\n")

    @staticmethod
    def help():
        print("\nHere is a list of the available commands for the game:\n"
              "There is a lot of things you can do in this game, and sometimes you will\n"
              "Have to explore with commands. Some commands listed here are keys to puzzles.\n"
              "Some of these commands are only available in certain rooms.\n")
        print("\ngo <north> <south> <east> west>,\n"
              "savegame, loadgame, exit,\n"
              "inventory, map\n"
              "turn flashlight on, turn on flashlight, turn flashlight off, turn off flashlight, change batteries\n"
              "look, look at <item>\n"
              "take <item>, drop <item>\n"
              "take off coat, take off scarf\n"
              "open door, close door, open <item>, close <item>, (some items can open and close)\n"
              "open <feature> (some features in rooms can be opened. You will have to try and see!\n"
              "look at <feature>, get in <feature, walk in <feature, enter <feature>,\n"
              "put <item> in chest, take <item> from chest,\n"
              "take music box from table, put music box on table\n"
              "take book from desk, open desk, look in desk,\n"
              "eat <item>, drink <item>, wear <item>, take <item> off,\n"
              "push <feature>, pull <feature>, move <feature>, leave room, flip switches,\n"
              "dig, retrieve key, lift floor mat, remove floor mat, use shovel to dig, dig with shovel,\n"
              "drink water bottle, open tap, light candles, light the candles,\n"
              "put mirror on shrine, put painting on shrine, press button,\n"
              "turn on lights, turn off lights, put book in bookcase, take book from bookcase,\n"
              "put tape in recorder, take tape from recorder, play <item>,\n"
              "sit in chair, get up from chair, sit on couch, lie on couch, get up from couch,\n"
              "stir ash with poker, play piano, play cello,\n"
              "move desk, open left drawer, open right drawer, open center drawer, look under desk,\n"
              "tie rope to desk, climb rope, climb down rope,\n"
              "punch mannequin, kick mannequin, hit mannequin with poker, peek behind blanket,\n"
              "get up from bed, lie on bed, jump on bed, sit on bed, hit window with fist, hit window with poker,\n"
              "pour water in fireplace, unlock <feature> with key, flush toilet\n")

    def available_actions(self, player, command):

        main_actions_dict = {
            'help': partial(self.help),
            'map': partial(player.show_map),
            'inventory': partial(player.print_inventory),
            'look': partial(self.room_description, player),
            'savegame': partial(self.save_game, player, room),
            'loadgame': partial(self.load_game, player, room),
            'go east': partial(player.move_east),
            'go west': partial(player.move_west),
            'go north': partial(player.move_north),
            'go south': partial(player.move_south),
            'open music box': partial(self.open_music_box, player),
            'close music box': partial(self.close_music_box, player),
            'turn flashlight on': partial(self.turn_on_flashlight, self.flashlight, player),
            'turn on flashlight': partial(self.turn_on_flashlight, self.flashlight, player),
            'turn flashlight off': partial(self.turn_off_flashlight, self.flashlight, player),
            'turn off flashlight': partial(self.turn_off_flashlight, self.flashlight, player),
            'change batteries': partial(self.change_batteries, self.flashlight, self.batteries, player),
            'change batteries2': partial(self.change_batteries, self.flashlight, self.batteries2, player),
            'take arm': partial(self.remove_item, self.arm, player),
            'take book': partial(self.remove_item, self.book, player),
            'take note': partial(self.remove_item, self.note, player),
            'take cassette tape': partial(self.remove_item, self.tape, player),
            'take duster': partial(self.remove_item, self.duster, player),
            'take poker': partial(self.remove_item, self.poker, player),
            'take watch': partial(self.remove_item, self.watch, player),
            'take music box': partial(self.remove_item, self.music_box, player),
            'take key': partial(self.remove_item, self.key, player),
            'take coat': partial(self.remove_item, self.coat, player),
            'take ribs': partial(self.remove_item, self.ribs, player),
            'take scarf': partial(self.remove_item, self.scarf, player),
            'take bucket': partial(self.remove_item, self.bucket, player),
            'take shovel': partial(self.remove_item, self.shovel, player),
            'take batteries': partial(self.remove_item, self.batteries, player),
            'take batteries2': partial(self.remove_item, self.batteries2, player),
            'take flashlight': partial(self.remove_item, self.flashlight, player),
            'take water bottle': partial(self.remove_item, self.water_bottle, player),
            'drop arm': partial(self.add_item, self.arm, player),
            'drop book': partial(self.add_item, self.book, player),
            'drop note': partial(self.add_item, self.note, player),
            'drop cassette tape': partial(self.add_item, self.tape, player),
            'drop duster': partial(self.add_item, self.duster, player),
            'drop poker': partial(self.add_item, self.poker, player),
            'drop watch': partial(self.add_item, self.watch, player),
            'drop music box': partial(self.add_item, self.music_box, player),
            'drop key': partial(self.add_item, self.key, player),
            'drop ribs': partial(self.add_item, self.ribs, player),
            'drop coat': partial(self.add_item, self.coat, player),
            'drop scarf': partial(self.add_item, self.scarf, player),
            'drop shovel': partial(self.add_item, self.shovel, player),
            'drop bucket': partial(self.add_item, self.bucket, player),
            'drop batteries': partial(self.add_item, self.batteries, player),
            'drop batteries2': partial(self.add_item, self.batteries2, player),
            'drop flashlight': partial(self.add_item, self.flashlight, player),
            'drop water bottle': partial(self.add_item, self.water_bottle,
                                         player),
            'look at arm': partial(self.look_item, self.arm, player),
            'look at book': partial(self.look_item, self.book, player),
            'look at note': partial(self.look_item, self.note, player),
            'look at cassette tape': partial(self.look_item, self.tape, player),
            'look at duster': partial(self.look_item, self.duster,
                                      player),
            'look at poker': partial(self.look_item, self.poker,
                                     player),
            'look at watch': partial(self.look_item, self.watch,
                                     player),
            'look at recorder': partial(self.look_item, self.recorder,
                                        player),
            'look at music box': partial(self.look_item, self.music_box,
                                         player),
            'look at key': partial(self.look_item, self.key, player),
            'look at ribs': partial(self.look_item, self.ribs, player),
            'look at coat': partial(self.look_item, self.coat, player),
            'look at scarf': partial(self.look_item, self.scarf,
                                     player),
            'look at shovel': partial(self.look_item, self.shovel,
                                      player),
            'look at bucket': partial(self.look_item, self.bucket,
                                      player),
            'look at batteries': partial(self.look_item, self.batteries,
                                         player),
            'look at batteries2': partial(self.look_item, self.batteries2,
                                          player),
            'look at flashlight': partial(self.look_item,
                                          self.flashlight, player),
            'look at water bottle': partial(self.look_item,
                                            self.water_bottle, player),
            'look at picture': partial(self.look_item, self.picture,
                                       player),
            'take picture': partial(self.remove_item, self.picture, player),
            'drop picture': partial(self.add_item, self.picture, player),
            'look at box': partial(self.look_item, self.box, player),
            'take box': partial(self.remove_item, self.box, player),
            'drop box': partial(self.add_item, self.box, player),
            'look at rope': partial(self.look_item, self.rope, player),
            'take rope': partial(self.remove_item, self.rope, player),
            'drop rope': partial(self.add_item, self.rope, player),
            'take small key': partial(self.remove_item, self.small_key,
                                      player),
            'drop small key': partial(self.add_item, self.small_key, player),
            'look at small key': partial(self.look_item, self.small_key,
                                         player),
            'look at first painting': partial(self.look_item,
                                              self.first_pic, player),
            'look at second painting': partial(self.look_item,
                                               self.second_pic, player),
            'look at third painting': partial(self.look_item,
                                              self.third_pic, player),
            'take first painting': partial(self.remove_item, self.first_pic,
                                           player),
            'drop first painting': partial(self.add_item, self.first_pic,
                                           player),
            'take second painting': partial(self.remove_item,
                                            self.second_pic, player),
            'drop second painting': partial(self.add_item,
                                            self.second_pic, player),
            'take third painting': partial(self.remove_item, self.third_pic,
                                           player),
            'drop third painting': partial(self.add_item, self.third_pic,
                                           player),
            'take pills': partial(self.remove_item, self.pills, player),
            'drop pills': partial(self.add_item, self.pills, player),
            'look at pills': partial(self.look_item, self.pills, player),
            'take old key': partial(self.remove_item, self.old_key, player),
            'drop old key': partial(self.add_item, self.old_key, player),
            'look at old key': partial(self.look_item, self.old_key,
                                       player),
            'look at rug': partial(self.look_item, self.rug, player),
            'look at item': partial(self.look_item, self.matches,
                                    player),
            'look at matches': partial(self.look_item, self.matches,
                                       player),
            'pick up matches': partial(self.remove_item, self.matches, player),
            'take matches': partial(self.remove_item, self.matches, player),
            'drop matches': partial(self.add_item, self.matches, player),
            'take mirror': partial(self.remove_item, self.mirror, player),
            'drop mirror': partial(self.add_item, self.mirror, player),
            'look at mirror': partial(self.look_item, self.mirror, player),
            'look at shrine': partial(self.look_item, self.shrine, player),
            'look at button': partial(self.look_item, self.button, player),
            'look at candles': partial(self.look_item, self.candle, player)
        }

        if command in main_actions_dict.keys():
            main_actions_dict[command]()

        elif command == "exit":
            if command == "exit" or command == "e":
                # save_game() here
                print("\nExiting game...Thanks for playing!\n")
                exit(0)

        else:
            print('\nCommand not found...\n')
