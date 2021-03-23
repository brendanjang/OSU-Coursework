from roomTile import RoomTile
from functools import partial

"""
Author: Pedro Varo
...........
class Entrance:
    A class to represent the entrance room.
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
items : list
    Stores the items of the room.
flashlight : object
    Object of class Flashlight.
coat : object
    Object of class Coat.
scarf : object
    Object of class Scarf.
    
--------
Methods
--------
def room_description(self, player):
    Method to print the room's description.

@staticmethod
def long_room_description(player):
    Method to print the long room description.

@staticmethod
def metal_door_description(command):
    Method to describe the metal door.
    
@staticmethod
def window_description(command):
    Method to describe the window.
    
@staticmethod
def check_for_flashlight(item, player):
    Method to check if the player has
    the flashlight and if the flashlight is on.

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
'open window': Opens the window.
'open door': Opens the door.
'look at window': Prints the window description.
'look at door': Prints the door description.
'go south': Moves player south.
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
Metal door:
    Thick metal door that is locked and cannot be opened.
Small window:
    Thick glass window that is locked and cannot be open nor broken.
    
--------------
Room Features
--------------
Flashlight:
    Rusted metal flashlight, which is required to enter and navigate through the dark rooms.
Coat:
    Old red coat, which the player can wear for warmth.
Scarf:
    Warm wool scarf, which the player can wear for warmth.
"""


class Entrance(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "entrance"
        # List to hold the items of the room.
        self.items = [self.flashlight, self.coat, self.scarf]

    # Function to print the room's description.
    def room_description(self, player):
        # If the player has visited this
        # room, print short room description.
        if self.visited:
            print("\n******* Entrance Room *******\n"
                  "This is a small narrow room with a thick metal door and a small window\n"
                  "located on top of the door. There is a flashlight, coat and scarf here.\n")
        # Else, print long room description.
        else:
            self.visited = True
            self.long_room_description(player)

    # Function to print long room description.
    @staticmethod
    def long_room_description(player):
        print("\n******* Entrance Room *******\n"
              "This is a small narrow room with a thick metal door and a small window\n"
              "located on top of the door. Both the door and window are locked and there\n"
              "is no way out. This room is also very cold and dark, however there is a dim\n"
              "light coming from the window which allows you to see. To your right there is\n"
              "a flashlight and to your left a coat stand with a coat and a scarf. The flashlight\n"
              "can be useful to enter dark rooms.\n")

    # Function to describe the metal door.
    @staticmethod
    def metal_door_description(command):
        if command == "open door":
            print("\nIts locked, you cannot open this door.\n")
        else:
            print("\nThick metal door that is locked and cannot be opened.\n")

    # Function to describe the window.
    @staticmethod
    def window_description(command):
        if command == "open window":
            print("\nIt is locked, you cannot open this window.\n")
        else:
            print("\nThick glass window that is locked and cannot be open nor broken.\n")

    # Function to check if the player has
    # the flashlight and if the flashlight is on.
    @staticmethod
    def check_for_flashlight(item, player):
        for n in player.inventory_list:
            if n.name == item.name:
                if n.isON:
                    # Once the flashlight is
                    # on, the player can go south.
                    player.move_south()
                    break
                else:
                    print("\nYou need to turn on the flashlight to enter this room.\n")
                    break
        else:
            print("\nYou need a flashlight to enter this room.\n")

    # Function to guide the player in the first floor.
    @staticmethod
    def move_description(command):
        if command == "go second floor":
            print("\nTo go to the second floor, you must use the elevator in the tea room.\n")
        else:
            print("\nTo go to the third floor, first you must use the elevator in the tea room\n"
                  "and go to the second floor.\n")

    # Function for the player to eat the ribs item.
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
            print("\nYou do not have ribs.\n")

    # Function for the player to drink water from the water bottle item.
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
            print("\nYou do not have a water bottle.\n")

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

    # Function to drop the coat.
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

    # Function to drop the scarf.
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
            'look': partial(self.long_room_description, player),
            'open window': partial(self.window_description, command),
            'open door': partial(self.metal_door_description, command),
            'look at window': partial(self.window_description, command),
            'look at door': partial(self.metal_door_description, command),
            'go south': partial(self.check_for_flashlight, self.flashlight, player),
            'go third floor': partial(self.move_description, command),
            'go second floor': partial(self.move_description, command),
            'eat ribs': partial(self.eat_ribs, self.ribs, player),
            'drink water': partial(self.drink_water, self.water_bottle, player),
            'drink water bottle': partial(self.drink_water, self.water_bottle, player),
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
