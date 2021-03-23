# This class store the player data such as inventory, current location, and current floor. It also has methods
# to manage the inventory, to show the map, and to move the player between rooms.
class Player:
    def __init__(self, current_floor="floor1", rooms_visited=None,
                 inventory_list=None, won=False):
        self.current_floor = current_floor
        self.rooms_visited = rooms_visited or []
        self.inventory_list = inventory_list or []
        self.won = won
        # Coordinates where we want the player to start.
        self.x = 0
        self.y = 0

    # Function to print the player's inventory.
    # Idea from https://stackoverflow.com/questions/29811082/how-to-print-out-a-numbered-list-in-python-3
    def print_inventory(self):
        # Check if the player's inventory is empty.
        if not self.inventory_list:
            print("\nYour inventory is empty.")
        else:
            print("\n")
            # Print a numbered inventory list in column
            print("\n************ INVENTORY ************\n")
            for n in self.inventory_list:
                print(self.inventory_list.index(n) + 1, end=" ")
                print(" ", n)
        print("\n")

    # This function can be used to initialize the player's
    # room location when the player moves between floors.
    # Function to update the floor the player is currently in.
    def update_current_floor(self, floor):
        self.current_floor = floor

    # Function to update player's status.
    def player_won(self, won):
        self.won = won

    # Function to add rooms to the player's list of rooms visited.
    def add_rooms_visited(self, room):
        # Check if the list is empty.
        if not self.rooms_visited:
            # If the list is empty, we append to the list.
            self.rooms_visited.append(room)
        else:
            # If not empty, check that
            # the item is not in the list.
            if room not in self.rooms_visited:
                self.rooms_visited.append(room)

    # Function to add items to the player's inventory.
    def add_inventory(self, item):
        # Check if the list is empty.
        if not self.inventory_list:
            # If the list is empty, we append to the list.
            self.inventory_list.append(item)
        else:
            # If not empty, check
            # that the item is not in the list.
            if item not in self.inventory_list:
                self.inventory_list.append(item)

    # Function to remove items from the inventory.
    def remove_inventory(self, item):
        # Check that the item is in the list.
        if item in self.inventory_list:
            self.inventory_list.remove(item)

    # Function to print the map.
    def show_map(self):

        if self.current_floor == "floor1":
            # First Floor map.
            row1 = ["|   EN   |", "|   TR   |", "= ==  = =|"]
            row2 = ["|   GB   |", "|   KI   |", "|   GA   |"]
        elif self.current_floor == "floor2":
            # Second floor map.
            row1 = ["|   LV   |", "|   DH   |", "= ==  = =|"]
            row2 = ["|   SQ   |", "|   MR   |", "|   LI   |"]
        else:
            # Third floor
            row1 = ["|   FR   |", "|   TB   |", "|   HR   |"]
            row2 = ["|   AR   |", "|   HW   |", "|   OF   |"]

        # Create the grid.
        grid = [row1, row2]
        # Initialize the player in the grid.
        player = '|  XX  | '
        display = f"\033[96m {player}\033[00m"
        grid[self.x][self.y] = display
        # Print the grid.
        print("\n")
        print("                         [[__]  ")
        print("     ____________________||  |_____")
        print("    /^^^^^^^^,-.^^^^^^^^^\|__|^^^^^\\")
        print("   /       ,',-.`.                  \\")
        print('  /      ,`,`   `.`.      ,-"""-.    \\')
        print(' /_____,`,`__   __`.`.___/_,"T"._\____\\')
        print(" |= ==  +--------+ +--------+  == = == |")
        print(" |== = ", ' '.join(row1))
        print(" |= ==  +--------+ +--------+  = == == |")
        print(" |=  +--------+ +--------+ +--------+ =|")
        print(" |= ", ' '.join(row2), "=|")
        print(" |=  +--------+ +--------+ +--------+ =|")
        print(' |= == ==|"""" """"|== == =|____|= = ==|')
        print(' """"""""|_________|""""""""====`"""""""')
        print("\n")

    # Functions to move the player
    def move(self, dx, dy):
        self.x = dx
        self.y = dy

    def move_north(self):
        if self.x == 1 and self.y == 2:
            print("\nYou cannot go that way!\n")
        elif self.x == 0:
            print("\nYou cannot go that way!\n")
        else:
            # self.move(dx=-1, dy=0)
            self.x -= 1

    def move_south(self):
        if self.x == 1:
            print("\nYou cannot go that way!\n")
        else:
            # self.move(dx=1, dy=0)
            self.x += 1

    def move_east(self):
        if self.x == 0 and self.y == 1:
            print("\nYou cannot go that way!\n")
        elif self.y == 2:
            print("\nYou cannot go that way!\n")
        else:
            # self.move(dx=0, dy=1)
            self.y += 1

    def move_west(self):
        if self.y == 0:
            print("\nYou cannot go that way!\n")
        else:
            # self.move(dx=0, dy=-1)
            self.y -= 1
