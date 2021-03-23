from roomTile import RoomTile
from functools import partial
import time

"""
Author: Pedro Varo
...........
class TeaRoom:
    A class to represent the tea room.
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
elevator_is_locked : boolean
    Records weather or not the elevator is locked.
fireplace_is_our : boolean
    Records weather or not the fireplace is out.
items : list
    Store the items of the room.
shovel : object
    Object of class Shovel.

--------
Methods
--------
def room_description(self, player):
    Method to print the room's description.

@staticmethod
def long_room_description(player):
    Method to print the long room description.

def fireplace_description(self):
    Method to print the fireplace description.

def elevator_description(self):
    Method to print the elevator description.
    
def put_out_fireplace(self, player):
    Method to put out the fireplace.
    
def unlock_elevator(self, player):
    Method to unlock the elevator.
    
def unlock_elevator_with_key(self, player):
    Method to unlock the elevator with the key.
    
def take_shovel(self, player):
    Method to take the shovel from the fireplace.

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

@staticmethod
def turn_off_flashlight_room():
    Method to promp the player to turn off the flashlight.

-------------
Room actions
-------------
'look': Prints the long form room description.
'take shovel': Takes the shovel if conditions are met.
'look at elevator': Prints elevator description.
'look at fireplace': Prints fireplace description.
'put out fireplace': Puts our fireplace if conditions are met.
'pour water in fireplace': Pours water in fireplace if conditions are met.
'use elevator': Notifies the player that a key is needed to unlock the elevator.
'take elevator': Notifies the player that a key is needed to unlock the elevator.
'open elevator': Notifies the player that a key is needed to unlock the elevator.
'unlock elevator': Notifies the player that a key is needed to unlock the elevator.
'unlock elevator with key': Unlocks the elevator if conditions are met.
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
Fireplace:
    Burning fireplace which is too hot for the player to reach into.
Elevator:
    Locked elevator which the player must unlock in order to move to the second floor.

--------------
Room Features
--------------
Shovel: 
    Burned shovel that is needed to retrieve the key.
"""


class TeaRoom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "tea room"
        self.elevator_is_locked = True
        self.fireplace_is_out = False
        # List to hold the items of the room.
        self.items = [self.shovel]

    # Function to print the room's description.
    def room_description(self, player):
        if self.visited:
            print("\n******* Tea Room ******* \n"
                  "This a dusty and very bright room with a burning fireplace and a locked\n"
                  "elevator. There might be a hidden shovel here which can be used to dig.\n")
        # Else, print long room description.
        else:
            self.visited = True
            self.long_room_description(player)

    # Function to print long room description.
    @staticmethod
    def long_room_description(player):
        print("\n******* Tea Room ******* \n"
              "This a dusty, but very bright room. In the front, there is a burning\n"
              "fireplace that lights up the whole room. Inside the fireplace, there seems\n"
              "to be a red hot metal. On the left, there is a locked elevator that leads\n"
              "to the second floor. Furthermore, in this room there is a hidden shovel which\n"
              "will be very useful to dig and retrieve items.\n")

    # Function to describe the fireplace.
    def fireplace_description(self):
        if not self.fireplace_is_out:
            print("\nBurning fireplace which is too hot to reach into. There is a red\n"
                  "hot metal inside, You will need a bucket full of water to put it out.\n")
        else:
            print("\nThe fireplace is out, maybe there is shovel inside.\n")

    # Function to describe the elevator.
    def elevator_description(self):
        if self.elevator_is_locked:
            print("\nLocked elevator, you will need a key to unlock it.\n")
        else:
            print("\nThe elevator is now unlocked, use this elevator to move up to the second floor.\n")

    # Function to guide the player in the first floor.
    @staticmethod
    def move_description(command):
        if command == "go second floor":
            print("\nTo go to the second floor, you must use the elevator.\n")
        else:
            print("\nTo go to the third floor, first you must\n"
                  "use the elevator and go to the second floor.\n")

    # Function to put out the fireplace.
    def put_out_fireplace(self, player):
        # Check if the player has a bucket full of water.
        for item in player.inventory_list:
            if item.name == "bucket":
                if item.isFull:
                    self.fireplace_is_out = True
                    print("\nThe fireplace is out.\n")
                    item.isFull = False
                    break
                else:
                    print("\nThe bucket is empty.\n")
                    print("Try to fill it up in the guest bathroom\n")
                    break
        else:
            print("\nThe fireplace is too hot to reach into.\n"
                  "Try getting a bucket full of water from the guest bathroom.\n")

    # Function to unlock the elevator.
    def unlock_elevator(self, player):
        if not self.elevator_is_locked:
            # If the elevator is not locked,
            # reroute the player to the second floor.
            print("You are moving up to the second floor.")
            player.update_current_floor("floor2")
            time.sleep(5)
        else:
            print("\nThe elevator is locked.\n"
                  "You will need to use the key from the garage room.\n")

    # Function to unlock the elevator with the key.
    def unlock_elevator_with_key(self, player):
        # Check that the player has the key.
        for item in player.inventory_list:
            if item.name == "key":
                self.elevator_is_locked = False
                # The player has cleared the first floor.
                print("\nCongratulations, you have cleared the first floor!\n")
                print("You are moving up to the second floor, good luck!\n")
                time.sleep(5)
                player.current_floor = "floor2"
                break
        else:
            print("\nYou don't have the key.\n"
                  "Try to get the key from the garage room.\n")

    # Function to take the shovel from the fireplace.
    def take_shovel(self, player):
        # Check that the fire is out.
        if self.fireplace_is_out:
            self.remove_item(self.shovel, player)
        else:
            print("\nYou need to put out the fireplace to get the shovel.\n")

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

    # Method to promp the player to turn off the flashlight.
    @staticmethod
    def turn_off_flashlight_room():
        print("\nYou should turn off the flashlight, is bright here.\n")

    def available_actions(self, player, command):

        actions_dict = {
            'look': partial(self.long_room_description, player),
            'take shovel': partial(self.take_shovel, player),
            'look at elevator': partial(self.elevator_description),
            'look at fireplace': partial(self.fireplace_description),
            'go third floor': partial(self.move_description, command),
            'go second floor': partial(self.move_description, command),
            'put out fireplace': partial(self.put_out_fireplace, player),
            'pour water in fireplace': partial(self.put_out_fireplace, player),
            'use elevator': partial(self.unlock_elevator, player),
            'take elevator': partial(self.unlock_elevator, player),
            'open elevator': partial(self.unlock_elevator, player),
            'unlock elevator': partial(self.unlock_elevator, player),
            'unlock elevator with key': partial(self.unlock_elevator_with_key, player),
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

        flashlight_is_on = False
        for item in player.inventory_list:
            if item.name == "flashlight":
                if item.isON:
                    flashlight_is_on = True

        if command == "go west" or command == "turn off flashlight":
            super().available_actions(player, command)

        elif flashlight_is_on and not self.fireplace_is_out:
            self.turn_off_flashlight_room()

        elif command in actions_dict.keys():
            actions_dict[command]()

        else:
            super().available_actions(player, command)
