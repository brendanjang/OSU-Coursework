from player import *
from room import *
from textparser import *
from art_ASCII import intro4


# This class manages the game state
class Game:

    @staticmethod
    def game_description():
        print(intro4)
        input("Please press enter to continue.\n")


def play_game():
    # Create a game object.
    game = Game()
    # Player stats.

    # Initialize player object
    player1 = Player()

    # Call game introduction
    game.game_description()

    # Initialize textparser object
    usr_input = Textparser()

    # Position player in game start location
    player_location = current_floor(player1.x, player1.y, player1)
    # -----------------------------------------------------------
    # If the player's visited list is empty, append the room.
    if not player1.rooms_visited:
        player1.rooms_visited.append(player_location)
    # -----------------------------------------------------------
    player_location.room_description(player1)

    while True:
        # Update player location.
        room = current_floor(player1.x, player1.y, player1)

        # --------------------------------------------------------
        # If the player is not in the same room.
        if player_location.name != room.name:
            # Check that the room is
            # not in the players visited list.
            visited = False
            for rm in player1.rooms_visited:
                if rm == room:
                    visited = True
                    break
            if not visited:
                # Append the new room to the
                # player's list of rooms visited.
                player1.rooms_visited.append(room)
            # ---------------------------------------------------------
            # Print long or short room description depending on
            # whether or not the player has visited the room before.
            room.room_description(player1)
            # Assign new room location
            # to the player_location.
            player_location = room

        # Prompt the user for input.
        user_input = input("What do you want to do?\n").lower()
        command = usr_input.parser(user_input)
        room.available_actions(player1, command)


if __name__ == "__main__":
    play_game()

