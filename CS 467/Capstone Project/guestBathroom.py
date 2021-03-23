from roomTile import RoomTile
from functools import partial

"""
Author: Pedro Varo
...........
class GuestBathroom:
    A class to represent the guest bathroom.
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
    Store the items of the room.
Bucket : object
    Object of class Bucket.

--------
Methods
--------
def room_description(self, player):
    Method to print the room's description.

@staticmethod
def long_room_description(player):
    Method to print the long room description.

@staticmethod
def bathtub_description(command, player):
    Method to print the bathtub description,

@staticmethod
def sink_description(command):
    Method to print the sink description.

@staticmethod
def flashlight_is_off():
    Method to let the user know that the flashlight is off.

@staticmethod
def fill_water_bottle(player):
    Method to fill the water bottle.

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
'open tap': Prints the sink message.
'look at sink': Prints sink description.
'fill bucket': Fills the bucket.
'fill water bottle': Fills the water bottle.
'look at bathtub': Prints bathtub description.
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
Sink:
    Dirty old sink that does not have running water.
Bathtub:
    Old bathtub full of moldy water.

--------------
Room Features
--------------
Bucket: 
    Plastic bucket that can be fill with water.
"""

class GuestBathroom(RoomTile):
    def __init__(self, x, y):
        super().__init__(x, y)
        self.x = x
        self.y = y
        self.visited = False
        self.name = "guest bathroom"
        # List to hold the items of the room.
        self.items = [self.bucket]

    # Function to print the room's description.
    def room_description(self, player):
        if self.visited:
            print("\n******* Guest Bathroom *******\n"
                  "This room is pitch dark. If the flashlight is turned OFF, the only way out is north.\n"
                  "There is a sink here and under the sink there is an empty bucket. Furthermore there\n"
                  "is and old bathtub full of moldy water. A bucket full of water can be useful.\n")
        # Else, print long room description.
        else:
            self.visited = True
            self.long_room_description(player)

    # Function to print long room description.
    @staticmethod
    def long_room_description(player):
        print("\n******* Guest Bathroom *******\n"
              "This room is pitch dark and it requires the flashlight to be turned ON in order to enter\n"
              "and pickup items. If the flashlight is turned OFF and while inside the room, the only way\n"
              "out is to go north. Furthermore, next to the entrance door there is a dirty sink and under\n"
              "the sink there is an empty bucket. In addition, on the left corner there a old bathtub full\n"
              "of moldy water. A bucket full of water can be useful to put put a fire.\n")

    # Function to describe the bathtub.
    @staticmethod
    def bathtub_description(command, player):
        if command == "fill bucket":
            # Check that the player has a bucket to fill.
            for item in player.inventory_list:
                if item.name == "bucket":
                    item.isFull = True
                    print("\nThe bucket is now full of water.\n")
                    break
            else:
                print("\nYou do not have a bucket.\n")
        else:
            print("\nOld bathtub full of moldy water.\n"
                  "Maybe you can fill up something here.\n")

    # Function to describe the sink.
    @staticmethod
    def sink_description(command):
        if command == "open tap":
            print("\nHmmm, there is no running water in this sink.\n")
        else:
            print("\nDirty old sink, looks like it might still work.\n")

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
              "Without light, the only way out is north.\n")

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

    # Function to fill the water bottle.
    @staticmethod
    def fill_water_bottle(player):
        for i in player.inventory_list:
            if i.name == "water bottle":
                if not i.isFull:
                    i.isFull = True
                    print("\nThe water bottle is full.\n"
                          "Not sure if you can drink it.\n")
                    break
                else:
                    print("\nThe water bottle is already full.\n")
                    break
        else:
            print("\nYou do not have a water bottle.\n")

    def available_actions(self, player, command):

        actions_dict = {
            'look': partial(self.long_room_description, player),
            'open tap': partial(self.sink_description, command),
            'look at sink': partial(self.sink_description, command),
            'fill bucket': partial(self.bathtub_description, command, player),
            'fill water bottle': partial(self.fill_water_bottle, player),
            'look at bathtub': partial(self.bathtub_description, command, player),
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

        elif command == "go north":
            player.move_north()

        elif not flashlight_is_on:
            self.flashlight_is_off()

        elif command in actions_dict.keys():
            actions_dict[command]()

        else:
            super().available_actions(player, command)
