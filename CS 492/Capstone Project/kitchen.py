from roomTile import RoomTile
from functools import partial

"""
Author: Pedro Varo
...........
class Kitchen:
    A class to represent the kitchen room.
...........
Attributes
-----------
x : int
    x coordinate of the room.
y : int
    y coordinate of the room.
visited : boolean
    Records weather the room is visited or not.
name : string
    Name of the room.
oven_is_open : boolean
    Records weather or not the oven is open.
refrigerator_is_open : boolean
    Records weather or not the refrigerator is open.
items : list
    Store the items of the room.
ribs : object
    Object of class Ribs.
water_bottle : object
    Object of class WaterBottle.

--------
Methods
--------
def room_description(self, player):
    Method to print the room's description.

@staticmethod
def long_room_description(player):
    Method to print the long room description.

@staticmethod
def check_for_flashlight_to_go_west(item, player):
    Method to check if the player has a flashlight and if the flashlight is on to go west.
    
@staticmethod
def check_for_flashlight_to_go_east(item, player):
    Method to check if the player has a flashlight and if the flashlight is on to go east.

@staticmethod
def refrigerator_description():
    Method to print the refrigerator description.
    
@staticmethod
def oven_description():
    Method to print the oven description.
    
def open_oven(self):
    Method to open the oven.

def open_refrigerator(self):
    Method to open the refrigerator.

def take_water_bottle(self, player):
    Method to take the water bottle.

def take_ribs(self, player):
    Method to take the ribs.

@staticmethod
def move_description(command):
    Method to guide the player in the first floor.

@staticmethod
def eat_ribs(item, player):
    Method for the player to eat the ribs item.

@staticmethod
def drink_water(item, player):
    Method for the player to drink water from the water bottle item.

@staticmethod
def wear_coat(item, player):
    Method for the player to wear the coat.

@staticmethod
def wear_scarf(item, player):
    Method for the player to wear the scarf.

@staticmethod
def take_coat_off(item, player):
    Method to take the coat off.

@staticmethod
def take_scarf_off(item, player):
    Method to take the scarf off.

def drop_coat(self, item, player):
    Method to drop the coat.

def drop_scarf(self, item, player):
    Method to drop the scarf.

def available_actions(self, player, command):
    Available actions of the room.

-------------
Room actions
-------------
'look': Prints the long form room description.
'open oven': Open the oven.
'open refrigerator': Opens the refrigerator.
'look at oven': Prints oven description.
'look at refrigerator': Prints refrigerator description.
'take ribs': Takes ribs if condition is met.
'take water bottle': Takes water bottle if condition is met.
'go west': Moves player west if flashlight is on.
'go east': Moves player east  if flashlight is on.
'go third floor': Prints floors instructions.
'go second floor': Prints floor instructions.
'eat ribs': To eat ribs.
'drink water': To drink water.
'drink water bottle': To drink water.
'wear coat': To wear coat.
'take coat off': To take coat off.
'wear scarf': To wear scarf.
'take scarf off': To take scarf off.
'drop coat': To drop coat.
'drop scarf': To drop scarf.

--------------
Room Features
--------------
Refrigerator:
    Broken refrigerator which the player can open and examine.
Oven:
    Still warm oven which shows signs that it was used recently.

--------------
Room Features
--------------
Water bottle: 
    Bottle full of potable water which can be drank.
Ribs:
    Warm baby back ribs that can be eaten.
"""

class Kitchen(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "kitchen"
        self.oven_is_open = False
        self.refrigerator_is_open = False
        # List to hold the items of the room.
        self.items = [self.ribs, self.water_bottle]

    # Function to print the room's description.
    def room_description(self, player):
        # If the player has visited this
        # room, print short room description.
        if self.visited:
            print("\n******* Kitchen *******\n"
                  "This room is very moldy and dirty. There is a refrigerator and an oven here.\n"
                  "In here, you can also find a bottle full of water and some ribs for a light meal.\n")
        # Else, print long room description.
        else:
            self.visited = True
            self.long_room_description(player)

    # Function to print long room description.
    @staticmethod
    def long_room_description(player):
        print("\n******* Kitchen *******\n"
              "This room is very moldy and dirty. There is a refrigerator next to the\n"
              "right wall and an oven next to it. The refrigerator is broken, but it contains\n"
              "a left behind bottle full of water. The oven seems to still work and inside it, there\n"
              "are some ribs that don't smell too bad. Some water and a light meal can help recuperate\n"
              "some energy.\n")

    # Function to check if the player has
    # a flashlight and if the flashlight is on.
    @staticmethod
    def check_for_flashlight_to_go_west(item, player):
        for n in player.inventory_list:
            if n.name == item.name:
                if n.isON:
                    # Once the flashlight is
                    # on, the player can go west.
                    player.move_west()
                    break
                else:
                    print("\nYou need to turn on the flashlight to enter this room.\n")
                    break
        else:
            print("\nYou need a flashlight to enter this room.\n")

    # Function to check if the player has
    # a flashlight and if the flashlight is on.
    @staticmethod
    def check_for_flashlight_to_go_east(item, player):
        for n in player.inventory_list:
            if n.name == item.name:
                if n.isON:
                    # Once the flashlight is
                    # on, the player can go east.
                    player.move_east()
                    break
                else:
                    print("\nYou need to turn on the flashlight to enter this room.\n")
                    break
        else:
            print("\nYou need a flashlight to enter this room\n")

    # Function to describe the refrigerator.
    @staticmethod
    def refrigerator_description():
        print("\nThe refrigerator is not working. Maybe there is something inside.\n")

    # Function to describe the oven
    @staticmethod
    def oven_description():
        print("\nThis oven is still warm, there must be something inside.\n")

    # Function to have the player eat the ribs item.
    @staticmethod
    def eat_ribs(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if not i.eaten:
                    i.eaten = True
                    print("\nNot sure if it was OK to eat them, but they tasted good.\n")
                    break
                else:
                    print("\nThey have no more meat and they are starting to stink.\n"
                          "Maybe you should drop them.\n")
                    break
        else:
            print(f"\nYou do not have {item}.\n"
                  f"Look inside the kitchen oven.\n")

    # Function to have the player drink water from the water bottle.
    @staticmethod
    def drink_water(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if i.isFull:
                    i.isFull = False
                    print("\nGLUG, GLUG, GLUG...\n"
                          "Not bad.\n")
                    break
                else:
                    print("\nThe water bottle is now empty.\n")
                    break
        else:
            print("\nYou do not have water.\n"
                  "Maybe there is some inside the kitchen refrigerator.\n")

    # Function to open the oven.
    def open_oven(self):
        self.oven_is_open = True
        print("\nThere are some ribs inside and they look eatable.\n")

    # Function to open the refrigerator.
    def open_refrigerator(self):
        self.refrigerator_is_open = True
        print("\nThere is a water bottle inside and is\n"
              "full of water, I wonder if is OK to drink it.\n")

    # Function to take the water bottle.
    def take_water_bottle(self, player):
        if self.refrigerator_is_open:
            self.remove_item(self.water_bottle, player)
        else:
            print("\nYou need to open the refrigerator to get the water bottle.\n")

    # Function to take the ribs.
    def take_ribs(self, player):
        if self.oven_is_open:
            self.remove_item(self.ribs, player)
        else:
            print("\nYou need to open the oven to get the ribs.\n")

    # Function to guide the player in the first floor.
    @staticmethod
    def move_description(command):
        if command == "go second floor":
            print("\nTo go to the second floor, you must use the elevator in the tea room.\n")
        else:
            print("\nTo go to the third floor, first you must use the elevator in the tea room\n"
                  "and go to the second floor.\n")

    # Function for the player to wear the coat.
    @staticmethod
    def wear_coat(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if not i.isWearing:
                    i.isWearing = True
                    print("\nThe coat is ON.\n")
                    break
                else:
                    print("\nYou area already wearing the coat.\n")
                    break
        else:
            print("\nYou do not have a coat.\n")

    # Function to take the coat off.
    @staticmethod
    def take_coat_off(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if i.isWearing:
                    i.isWearing = False
                    print("\nThe coat is OFF.\n")
                    break
                else:
                    print("\nYou are not wearing a coat.\n")
                    break
        else:
            print("\nYou do not have a coat.\n")

    # Function for the player to wear the scarf.
    @staticmethod
    def wear_scarf(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if not i.isWearing:
                    i.isWearing = True
                    print("\nThe scarf is ON.\n")
                    break
                else:
                    print("\nYou area already wearing the scarf.\n")
                    break
        else:
            print("\nYou do not have a scarf.\n")

    # Function to take the scarf off.
    @staticmethod
    def take_scarf_off(item, player):
        for i in player.inventory_list:
            if i.name == item.name:
                if i.isWearing:
                    i.isWearing = False
                    print("\nThe scarf is OFF.\n")
                    break
                else:
                    print("\nYou are not wearing a scarf.\n")
                    break
        else:
            print("\nYou do not have a scarf.\n")

    # Function to drop the coat
    def drop_coat(self, item, player):
        # Check if the player is wearing the coat
        for i in player.inventory_list:
            if i.name == item.name:
                if not i.isWearing:
                    self.add_item(self.coat, player)
                    break
                else:
                    print("\nYou need to take the coat off first.\n")
                    break
        else:
            print("\nYou do not have a coat.\n")

    # Function to drop the coat
    def drop_scarf(self, item, player):
        # Check if the player is wearing the scarf
        for i in player.inventory_list:
            if i.name == item.name:
                if not i.isWearing:
                    self.add_item(self.scarf, player)
                    break
                else:
                    print("\nYou need to take the scarf off first.\n")
                    break
        else:
            print("\nYou do not have a scarf.\n")

    def available_actions(self, player, command):

        actions_dict = {

            'open oven': partial(self.open_oven),
            'look at oven': partial(self.oven_description),
            'look': partial(self.long_room_description, player),
            'open refrigerator': partial(self.open_refrigerator),
            'eat ribs': partial(self.eat_ribs, self.ribs, player),
            'take ribs': partial(self.take_ribs, player),
            'look at refrigerator': partial(self.refrigerator_description),
            'drink water': partial(self.drink_water, self.water_bottle, player),
            'drink water bottle': partial(self.drink_water, self.water_bottle, player),
            'take water bottle': partial(self.take_water_bottle, player),
            'go west': partial(self.check_for_flashlight_to_go_west, self.flashlight, player),
            'go east': partial(self.check_for_flashlight_to_go_east, self.flashlight, player),
            'go third floor': partial(self.move_description, command),
            'go second floor': partial(self.move_description, command),
            'wear coat': partial(self.wear_coat, self.coat, player),
            'take coat off': partial(self.take_coat_off, self.coat, player),
            'wear scarf': partial(self.wear_scarf, self.scarf, player),
            'take scarf off': partial(self.take_scarf_off, self.scarf, player),
            'drop coat': partial(self.drop_coat, self.coat, player),
            'drop scarf': partial(self.drop_scarf, self.scarf, player)
        }

        if command in actions_dict.keys():
            actions_dict[command]()
        else:
            super().available_actions(player, command)
