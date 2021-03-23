from roomTile import RoomTile
from functools import partial

# author: Jason Watson

# Player actions in this room:
#   * Punch mannequin - done
#   * hit mannequin with poker - done
#   * take mannequin arm -- it has a key! - done
#   * look at chest - done
#   * open chest - done
#   * look at mannequin - done
# Features in this room:
#   * Chest with cassette tape
#   * Mannequin that the player can punch or hit with poker
#   * Will need the mannequin's arm to unlock a desk drawer

class ServantQuarters(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "Servant Quarters"
        self.light_on = False
        self.mannequin_standing = True
        self.mannequin_armless = False
        self.blanket_up = True
        self.chest_open = False
        self.window_destroyed = False
        self.lying_on_bed = False
        self.sitting_on_bed = False
        self.bed_destroyed = False
        self.items = [self.watch, self.batteries2]
        self.chest = [self.tape]

    # actions available in specific room

    def turn_on_light(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.light_on = True
            print("You flip the light switch. The light bulb above briefly flickers on then explodes in a flash of"
                  "sparks. Oh well.  There is enough light to see by due to the eerie moonlight.\n")
        else:
            print("You will need to get up if you want to do that!")

    def turn_off_light(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.light_on = False
            print("Doesn't do anything.")
        else:
            print("You will need to get up if you want to do that!")

    # private method
    def add_mannequin_arm(self):
        self.items.append(self.arm)

    @staticmethod
    def look_at_chest():
        print("\nThe chest is of solid oak with copper bands around it. It appears to be unlocked.\n"
              "You can look in it by typing \"open chest\"\n")

    def look_mannequin(self):
        if self.mannequin_standing and not self.mannequin_armless:
            print("\nIt really did look like a human figure standing there in the moonlight. It is a pale male figure\n"
                  "dressed in a green and faded cloak, dress shirt and pale trousers.  It's right arm and up and\n"
                  "pointing directly at you, it's fingers missing as if someone snipped them off with scissors.\n"
                  "In the place of the pinky finger is what looks like a key, welded to the hand!\n"
                  "It's eye sockets are painted black as if it's a skull. You briefly get the sensation that it's\n "
                  "staring at you.\n")
        elif self.mannequin_standing and self.mannequin_armless:
            print("\nIt stands there, without an arm.\n")
        elif not self.mannequin_standing and self.mannequin_armless:
            print("\nThe mannequin lies crumbled in a pile.\n")

    def pull_arm_off_mannequin(self, player1):
        self.mannequin_armless = True
        print("\nYou step up to the mannequin, and carefully yank on the arm, pulling it off.\n")
        player1.add_inventory(self.arm)

    def punch_mannequin(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.mannequin_standing = False
            self.mannequin_armless = True
            # add mannequin arm to room
            self.add_mannequin_arm()
            print("\nYou ball up your fist and swing at the mannequin's body.  You feel it connect and it's arm\n"
                  "flies off and bounces against the wall as the body crumbles onto the ground. The arm\n"
                  "is in the room. You feel better not having it stare deep into your soul.\n")
        else:
            print("\nYou will need to get up if you want to do that!\n")

    def kick_mannequin(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.mannequin_armless = True
            self.mannequin_standing = False
            self.add_mannequin_arm()
            print("\nYou kick out desperately at the mannequin.  Your foot smacks the mannequin in the chest and it\n"
                  "flies backward, crumbling onto the ground in a cloud of dust. The arm falls off and is in the"
                  " room.\n")
        else:
            print("\nYou will need to get up if you want to do that!\n")

    def look_blanket(self):
        if self.blanket_up:
            print("\nIt is swaying softly in a slight breeze.  The breeze seems to be coming from behind the "
                  "blanket.\n")
        if not self.blanket_up:
            print("\nThe blanket is in a heap on the ground.\n")

    def pull_blanket(self):
        self.blanket_up = False
        print("\nThe blanket falls easily and slides onto the ground in front of the window.  The moonlight pours\n"
              "fully into the room, lighting everything up with it's pale glow.  The window pane is cracked and\n"
              "ancient glass. It is covered in frost and grime but you can see outside if you wanted to "
              "(type \"look out window\"\n")

    def take_blanket(self):
        self.blanket_up = False
        print("\nYou pull the blanket down and attempt to fold it up.  Moths and dust fly out, causing you to gasp\n"
              "for air. It smells of centuries of dust and mould. As you fold it up, it crumbles into many pieces and\n"
              "disappointed, you throw the remains onto the ground. The moonlight pours fully into the room, lighting\n"
              "everything up with it's pale glow.\n")

    def peek_behind_blanket(self):
        if self.blanket_up:
            print("\nYou can barely see through the frosty and grimy window pane.  You can see down below a tiny\n"
                  "courtyard which is covered in snow.  In the middle is what looks like a well.  As you peer\n"
                  "downward, some clouds cover the moon briefly, darkening the courtyard.  You can see what\n"
                  "looks like an outline of a hooded figure standing next to the well. The cloud cover quickly\n"
                  "moves away and the moonlight returns showing an empty courtyard.\n")
        elif not self.blanket_up:
            print("\nYou can just look out the window.\n")

    def look_window(self):
        if self.blanket_up:
            print("\nThere is a blanket covering the window.  You can try to peek behind, pull down or take the "
                  "blanket.\n")
        if not self.blanket_up:
            print("You peer out the window. You can barely see through the frosty and grimy window pane.  You can see\n"
                  "down below a tiny courtyard which is covered in snow. In the middle is what looks like a well.\n"
                  "As you peer downward, some clouds\n"
                  "cover the moon briefly, darkening the courtyard. You can see what looks like an outline of a\n"
                  "hooded figure standing next to the well. The cloud cover quickly moves away and the moonlight\n"
                  "returns showing an empty courtyard.\n")

    def look_at_bed(self):
        if not self.bed_destroyed:
            print("\nIt's a twin bed that looks recently slept in.\n")
        else:
            print("\nThe bed is destroyed.\n")

    @staticmethod
    def look_at_dresser():
        print("\nIt's seen better days.  It seems as if someone had smashed it to pieces.\n")

    # you cannot do anything else while lying in bed.
    def lay_in_bed(self):
        if not self.bed_destroyed:
            self.lying_on_bed = True
            print("\nThe first thing you notice is the awful smell of body odor and soiled linen. Otherwise,\n"
                  "\nit is fairly comfortable and you feel yourself lulled into a doze.\n")
        else:
            print("\nThe bed is destroyed and you cannot lie down on it.\n")

    def get_up_from_bed(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.sitting_on_bed = False
            self.lying_on_bed = False
            print("\nYou get up and stretch.  You feel so much more rested.\n")
        else:
            print("\nYou are already on the bed.\n")

    def sit_on_bed(self):
        self.sitting_on_bed = True
        print("\nYou sit down on the bed.  It squeaks and you feel the foundation giving away a little. It would be\n"
              "more comfortable to lie down on the bed. Type \"lie down\"\n")

    def jump_on_bed(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            self.bed_destroyed = True
            print("\nYou jump on the bed.  You feel like a kid again.  After a few jumps, the bed's foundation "
                  "crumbles under you\n")

    def hit_window_with_poker(self, player1):
        # check inventory for poker
        found = False
        for i in player1.inventory_list:
            if i.name == "poker":
                found = True
        if not self.lying_on_bed and not self.sitting_on_bed and not self.blanket_up and found:
            self.window_destroyed = True
            print("\bYou take the poker out and swing at the window.  After a few hits, the glass shatters and falls\n"
                  "outward into the courtyard down below. A cold gust of wind pushes you back. It would seem like\n"
                  "a good opportunity to escape, however, you are sure to not survive the fall.\n")
        elif not self.lying_on_bed and not self.sitting_on_bed and self.blanket_up and found:
            print("\nThere is a blanket covering the window.\n")
        elif self.lying_on_bed or self.sitting_on_bed:
            print("\nYou are in no position to reach the window. Perhaps you should get up.\n")
        else:
            print("\nYou don't have a poker in inventory.\n")

    def hit_window_with_fist(self):
        if not self.lying_on_bed or not self.sitting_on_bed:
            print("\nOuch that hurts.  The glass is too strong.  You only ended up bruising your fist.\n")

    # this method adds item to chest while removing said item from inventory
    def add_item_to_chest(self, item, player1):

        print(f"\nAttempting to add {item} to chest\n")
        item_added = False
        for n in player1.inventory_list:
            if n.name == item.name and n not in self.chest:
                player1.inventory_list.remove(n)
                self.chest.append(n)
                item_added = True
                print(f"\n{item} was removed from your inventory\n")
            if not item_added:
                print(f"\nYou do not have a {item}.\n")

    # method to remove item from chest and add item to player inventory
    def remove_item_from_chest(self, item, player1):
        print(f"\nAttempting to remove {item} from chest.\n")
        item_removed = False
        for n in self.chest:
            if n.name == item.name and n not in player1.inventory_list:
                player1.inventory_list.append(n)
                self.chest.remove(n)
                item_removed = True
                print(f"\n{item} was added to your inventory\n")
        if not item_removed:
            print(f"\nThere is no {item} here.\n")

    def open_chest(self):
        if len(self.chest) == 0:
            print("\nYou open the chest.  It swings open with a heavy clanging sound. It is full of mouldy\n"
                  "clothes from the 1800s, cobwebs and dust.\n")
        else:
            # unpack the list so I can use the individual items
            numitems = len(self.chest)
            print("\nYou open the chest.  It swings open with a heavy clanging sound. It is full of mouldy\n"
                  "clothes from the 1800s, cobwebs and dust. You notice something else in the chest.\n")
            print(f"\nThere are {numitems} items in this chest: \n")
            for x in range(len(self.chest)):
                print(self.chest[x])
            print("\n")

    def print_items_in_room(self):
        num_items = len(self.items)
        print(f"\nThere are {num_items} items in this room: \n")
        for x in range(len(self.items)):
            print(self.items[x])
        print("\n")

    @staticmethod
    def exits_from_room():
        print("\nThere is an exit to the north.\n")

    # public method
    # call method when room is loaded. i.e. darkHall.room_description() when room is loaded.
    def room_description(self, player1):
        # short description for when room has already been visited
        if self.visited:
            if len(self.items) == 0:
                if self.blanket_up and not self.mannequin_armless and self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. There is a blanket hanging before the window.\n")
                elif self.blanket_up and self.mannequin_armless and self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, minus an arm.\n"
                          "There is an old, heavy chest in the room.  There is a light-switch to the right\n"
                          "of the doorway.  There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground.  There is a blanket hanging before the window.\n")
                elif not self.blanket_up and not self.window_destroyed and not self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the window, lighting up the room.\n")
                elif not self.blanket_up and not self.window_destroyed and self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n"
                          "Glass shards lie before the open window.  A wind blows through the open window.\n")
                elif not self.blanket_up and not self.window_destroyed and self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, minus an arm.\n"
                          "There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n")
                elif not self.blanket_up and self.window_destroyed and self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, minus an arm.\n"
                          "There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the window, lighting up the room.\n"
                          "Glass shards lie before the open window.  A wind blows through the open window.\n")
                elif not self.blanket_up and not self.window_destroyed and not self.mannequin_armless and not \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n")
                elif not self.blanket_up and self.window_destroyed and not self.mannequin_armless and not \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n"
                          "Glass shards lie before the open window.  A wind blows through the open window.\n")
                self.exits_from_room()
            else:
                if self.blanket_up and not self.mannequin_armless and self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. There is a blanket hanging before the window.\n")
                elif self.blanket_up and self.mannequin_armless and self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, minus an arm.\n"
                          "There is an old, heavy chest in the room.  There is a light-switch to the right\n"
                          "of the doorway.  There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground.  There is a blanket hanging before the window.\n")
                elif not self.blanket_up and not self.window_destroyed and not self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the window, lighting up the room.\n")
                elif not self.blanket_up and not self.window_destroyed and self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n"
                          "Glass shards lie before the open window.  A wind blows through the open window.\n")
                elif not self.blanket_up and not self.window_destroyed and self.mannequin_armless and \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, minus an arm.\n"
                          "There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n")
                elif not self.blanket_up and not self.window_destroyed and not self.mannequin_armless and not \
                        self.mannequin_standing:
                    print("\n**********Servant Quarters**********\n"
                          "\nThe mannequin is still standing there, it's arm\n"
                          "upraised and pointing at you. There is also an old, heavy-set chest\n"
                          "in the room. There is a light-switch to the right of the doorway.\n"
                          "There is a battered dresser against the east wall, it's empty drawers\n"
                          "scattered on the ground. Moonlight shines through the open window, lighting up the room.\n")
                self.exits_from_room()
                self.print_items_in_room()

        else:
            self.visited = True
            if len(self.items) == 0:
                self.long_room_description()
                self.exits_from_room()
            else:
                self.long_room_description()
                self.print_items_in_room()
                self.exits_from_room()

    def long_room_description(self):

        print("\n**********Servant Quarters**********\n"
              "\nYou can instantly smell old linen and the atmosphere is heavy with dust.\n"
              "You can almost hear the sound of creaking and scurrying. Suddenly\n"
              "you get the sense of being watched.  You start and almost scream as\n"
              "as you see a figure in the moonlight, staring at you! You calm down\n"
              "almost instantly as you realize it is a mannequin, standing against\n"
              "the wall.  It's right arm is raised, a finger pointing right at you!\n"
              "Something seems a little off about the finger, which in the shadows\n"
              "you cannot quite see from where you are standing.\n"
              "You can make out a chest in the corner of the room, and a\n"
              "ruffled bed against the south wall.  You also notice a light switch\n"
              "to the right of the doorway. There is a battered dresser against the\n"
              "east wall of the room, it's empty drawers scattered along the ground\n"
              "in front. There is a blanket hanging in front of the window.\n")

    def available_actions(self, player1, command):

        # Brendan's actions_dict idea.
        actions_dict = {
            'turn on light': self.turn_on_light,
            'turn on lights': self.turn_on_light,
            'turn off light': self.turn_off_light,
            'turn off lights': self.turn_off_light,
            'open chest': self.open_chest,
            'look at chest': self.look_at_chest,
            'look at mannequin': self.look_mannequin,
            'punch mannequin': self.punch_mannequin,
            'kick mannequin': self.kick_mannequin,
            'look at blanket': self.look_blanket,
            'pull blanket': self.pull_blanket,
            'take blanket': self.take_blanket,
            'peek behind blanket': self.peek_behind_blanket,
            'look out window': self.look_window,
            'look at bed': self.look_at_bed,
            'look at dresser': self.look_at_dresser,
            'get up from bed': self.get_up_from_bed,
            'sit on bed': self.sit_on_bed,
            'jump on bed': self.jump_on_bed,
            'pull arm off mannequin': partial(self.pull_arm_off_mannequin, player1),
            'hit window with poker': partial(self.hit_window_with_poker, player1),
            'hit window with fist': self.hit_window_with_fist,
            'put arm in chest': partial(self.add_item_to_chest, self.arm, player1),
            'take arm from chest': partial(self.remove_item_from_chest, self.arm, player1),
            'put flashlight in chest': partial(self.add_item_to_chest, self.flashlight, player1),
            'take flashlight from chest': partial(self.remove_item_from_chest, self.flashlight, player1),
            'put cassette tape in chest': partial(self.add_item_to_chest, self.tape, player1),
            'take cassette tape from chest': partial(self.remove_item_from_chest, self.tape, player1),
            'put note in chest': partial(self.add_item_to_chest, self.note, player1),
            'take note from chest': partial(self.remove_item_from_chest, self.note, player1),
            'put book in chest': partial(self.add_item_to_chest, self.book, player1),
            'take book from chest': partial(self.remove_item_from_chest, self.book, player1),
            'put duster in chest': partial(self.add_item_to_chest, self.duster, player1),
            'take duster from chest': partial(self.remove_item_from_chest, self.duster, player1),
            'put batteries2 in chest': partial(self.add_item_to_chest, self.batteries, player1),
            'take batteries2 from chest': partial(self.remove_item_from_chest, self.batteries, player1),
            'put music box in chest': partial(self.add_item_to_chest, self.music_box, player1),
            'take music box from chest': partial(self.remove_item_from_chest, self.music_box, player1),
            'put watch in chest': partial(self.add_item_to_chest, self.watch, player1),
            'take watch from chest': partial(self.remove_item_from_chest, self.watch, player1),
            'put shovel in chest': partial(self.add_item_to_chest, self.shovel, player1),
            'take shovel from chest': partial(self.remove_item_from_chest, self.shovel, player1),
            'put bucket in chest': partial(self.add_item_to_chest, self.bucket, player1),
            'take bucket from chest': partial(self.remove_item_from_chest, self.bucket, player1),
            'put key in chest': partial(self.add_item_to_chest, self.key, player1),
            'take key from chest': partial(self.remove_item_from_chest, self.key, player1),
            'put ribs in chest': partial(self.add_item_to_chest, self.ribs, player1),
            'take ribs from chest': partial(self.remove_item_from_chest, self.ribs, player1),
            'put water bottle in chest': partial(self.add_item_to_chest, self.water_bottle, player1),
            'take water bottle from chest': partial(self.remove_item_from_chest, self.water_bottle, player1),
            'put coat in chest': partial(self.add_item_to_chest, self.coat, player1),
            'take coat from chest': partial(self.remove_item_from_chest, self.coat, player1),
            'put scarf in chest': partial(self.add_item_to_chest, self.scarf, player1),
            'take scarf from chest': partial(self.remove_item_from_chest, self.scarf, player1),
            'put poker in chest': partial(self.add_item_to_chest, self.poker, player1),
            'take poker from chest': partial(self.remove_item_from_chest, self.poker, player1),
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player1, command)
