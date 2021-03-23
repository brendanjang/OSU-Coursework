from entrance import Entrance
from teaRoom import TeaRoom
from guestBathroom import GuestBathroom
from kitchen import Kitchen
from garage import Garage
from artRoom import ArtRoom
from fuseRoom import FuseRoom
from office import Office
from thirdBathroom import ThirdBathroom
from hiddenRoom import HiddenRoom
from darkHallway import DarkHallway
from musicRoom import MusicRoom
from library import Library
from servantQuarters import ServantQuarters
from livingRoom import LivingRoom
from hallway import Hallway

# ------------------------------------------------------------+
# First Floor Map -- Pedro's rooms
Entrance = Entrance(0, 0)
TeaRoom = TeaRoom(0, 1)
GuestBathroom = GuestBathroom(1, 0)
Kitchen = Kitchen(1, 1)
Garage = Garage(1, 2)
row1 = [Entrance, TeaRoom]
row2 = [GuestBathroom, Kitchen, Garage]
floor1_map = [row1, row2]
# ------------------------------------------------------------+
# ------------------------------------------------------------+
# Second Floor Map -- Jason's rooms
# row1 = [LivingRoom(0, 0), DarkHallway(0, 1)]
# row2 = [ServantQuarters(1, 0), MusicRoom(1, 1), Library(1, 2)]
LivingRoom = LivingRoom(0, 0)
DarkHallway = DarkHallway(0, 1)
ServantQuarters = ServantQuarters(1, 0)
MusicRoom = MusicRoom(1, 1)
Library = Library(1, 2)
row1 = [LivingRoom, DarkHallway]
row2 = [ServantQuarters, MusicRoom, Library]
floor2_map = [row1, row2]
# ------------------------------------------------------------+
# ------------------------------------------------------------+
FuseRoom = FuseRoom(0, 0)
ThirdBathroom = ThirdBathroom(0, 1)
HiddenRoom = HiddenRoom(0, 2)
ArtRoom = ArtRoom(1, 0)
Hallway = Hallway(1, 1)
Office = Office(1, 2)
row1 = [FuseRoom, ThirdBathroom, HiddenRoom]
row2 = [ArtRoom, Hallway, Office]
floor3_map = [row1, row2]
# ------------------------------------------------------------+


# Function to return the current floor.
def current_floor(x, y, player):
    # Return the current floor
    # according to the player's position.
    if player.current_floor == "floor1":
        return floor1_map[x][y]
    elif player.current_floor == "floor2":
        return floor2_map[x][y]
    elif player.current_floor == "floor3":
        return floor3_map[x][y]
    # Else, there was an error.
    else:
        print("Error: no floor found!")

