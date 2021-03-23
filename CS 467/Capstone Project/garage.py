from roomTile import RoomTile
from functools import partial

"""
Author: Pedro Varo
...........
class Garage:
    A class to represent the garage room.
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
hole_uncovered : boolean
    Records weather or not the ground hole is uncovered.
floor_mat_removed : boolean
    Records weather or not the floor mat is removed.
tool_box_is_open : boolean
    Records weather or not the tool box is open.
items : list
    Store the items of the room.
batteries : object
    Object of class Batteries.
key : object
    Object of class Key.

--------
Methods
--------
def room_description(self, player):
    Method to print the room's description.

@staticmethod
def long_room_description(player):
    Method to print the long room description.

@staticmethod
def floor_mat_description():
    Method to print the mat descriptions.
    
def tool_box_description(self, command):
    Method to print the tool box description.
    
def floor_mat(self):
    Method to lift the floor mat.
    
def uncover_ground_hole(self, player):
    Method to uncover the ground hole.
    
def retrieve_key(self, player):
    Method to retrieve the key.

def take_batteries(self, player):
    Method to take the batteries.
    
@staticmethod
def dig_short():
    Method to provide the correct command format.
    
@staticmethod
def flashlight_is_off():
    Method to print message if flashlight is off.

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
'dig': Prompts for the correct action verbs.
'look': Prints the long form room description.
'take key': Takes key if conditions are met.
'retrieve key': Retrieves key if conditions are met.
'open tool box': Opens the took box if conditions are met.
'lift floor mat': Lifts floor mat if conditions are met.
'remove floor mat': Removes floor mat if conditions are met.
'take batteries': Take batteries if conditions are met.
'look at tool box': Prints tool box descriptions.
'look at floor mat': Prints floor mat description.
'use shovel to dig': Digs if conditions are met.
'dig with shovel': Digs if conditions are met.
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
Took box:
    Metal tool box that the player can open and examine.
Floor mat:
    Old floor mat which the player must lift to uncover the hole in the ground.

--------------
Room Features
--------------
Batteries: 
    Flashlight batteries need to recharge the flashlight.
Key:
    Silver key needed to unlock the elevator and continue to the second floor.    
"""


class Garage(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "garage"
        self.hole_uncovered = False
        self.floor_mat_removed = False
        self.tool_box_is_open = False
        # List to hold the items of the room.
        self.items = [self.batteries, self.key]

    # Function to print the room's description.
    def room_description(self, player):
        # If the player has visited this
        # room, print short room description.
        if self.visited:
            print("\n******* Garage *******\n"
                  "This room is pitch dark. If the flashlight is turned OFF, the only way out is west.\n"
                  "There is a rusted metal toolbox here and an oil stained floor mat. Inside the tool box,\n"
                  "there are some batteries, and under the floor mat and whole covered with dirt.\n")
        # Else, print long room description.
        else:
            self.visited = True
            self.long_room_description(player)

    # Function to print long room description.
    @staticmethod
    def long_room_description(player):
        print("\n******* Garage *******\n"
              "This room is pitch dark and it requires the flashlight to be turned ON in order to enter\n"
              "and pickup items. If the flashlight is turned OFF and while inside the room, the only way\n"
              "out is to go west.Next to the entrance, there is a rusted metal tool box and in the center\n"
              "of the room there is a large oil stained floor mat. Inside the tool box, there are some flashlight\n"
              "batteries and under the floor mat there is a whole covered with dirt.\n")

    # Function to describe the floor mat.
    @staticmethod
    def floor_mat_description():
        print("\nRed floor map, looks like is covering something.\n")

    # Function to describe the tool box.
    def tool_box_description(self, command):
        if command == "look at tool box":
            print("\nThis is an old metal box, maybe it can be open.\n")
        else:
            print("\nThere are some batteries inside.\n"
                  "These can be useful for the flashlight.\n")
            self.tool_box_is_open = True

    # Function to lift or remove the floor mat.
    def floor_mat(self):
        self.floor_mat_removed = True
        print("\nThere is a hole underneath and is covered with dirt.\n"
              "Maybe you should try digging, there can be something inside.\n")

    # Function to uncover the hole and retrieve the key.
    def uncover_ground_hole(self, player):
        for n in player.inventory_list:
            if n.name == "shovel":
                self.hole_uncovered = True
                print("\nGreat job!\n"
                      "There is key inside, this can be used to unlock the elevator!\n")
                break
        else:
            print("\nYou need a shovel to dig.\n")

    # Function to retrieve the key.
    def retrieve_key(self, player):
        if self.hole_uncovered:
            print("\nHooray, you got the key!\n"
                  "To escape the fist floor use the elevator in the tea room.\n")
            self.remove_item(self.key, player)
        elif not self.floor_mat_removed:
            print("\nFirst, you need to remove the floor mat.\n")
        else:
            print("\nYou need to dig to retrieve the key.\n")

    def take_batteries(self, player):
        if self.tool_box_is_open:
            self.remove_item(self.batteries, player)
        else:
            print("\nYou need to open the tool box to take the batteries.\n")

    # Function to guide player to use
    # the correct input format to dig.
    @staticmethod
    def dig_short():
        print("\nTry typing 'dig with shovel'\n")

    # Function to guide the player in the first floor.
    @staticmethod
    def move_description(command):
        if command == "go second floor":
            print("\nTo go to the second floor, you must use the elevator in the tea room.\n")
        else:
            print("\nTo go to the third floor, first you must use the elevator in the tea room\n"
                  "and go to the second floor.\n")

    # Function to let the player know that
    # he needs to turn the flashlight on to see.
    @staticmethod
    def flashlight_is_off():
        print("\nIt is too dark in here.\n"
              "You need to turn on the flashlight to see.\n"
              "Without light, the only way out is west.\n")

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
            'dig': partial(self.dig_short),
            'look': partial(self.long_room_description, player),
            'take key': partial(self.retrieve_key, player),
            'retrieve key': partial(self.retrieve_key, player),
            'open tool box': partial(self.tool_box_description, command),
            'lift floor mat': partial(self.floor_mat),
            'remove floor mat': partial(self.floor_mat),
            'take batteries': partial(self.take_batteries, player),
            'look at tool box': partial(self.tool_box_description, command),
            'look at floor mat': partial(self.floor_mat_description),
            'use shovel to dig': partial(self.uncover_ground_hole, player),
            'dig with shovel': partial(self.uncover_ground_hole, player),
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

        # Check if the flashlight is on.
        flashlight_is_on = True
        for n in player.inventory_list:
            if n.name == "flashlight":
                if n.isON:
                    break
                else:
                    flashlight_is_on = False
                    break

        if command == "turn flashlight on" or command == "turn on flashlight":
            super().available_actions(player, command)

        elif command == "go west":
            player.move_west()

        elif not flashlight_is_on:
            self.flashlight_is_off()

        elif command in actions_dict.keys():
            actions_dict[command]()

        else:
            super().available_actions(player, command)
