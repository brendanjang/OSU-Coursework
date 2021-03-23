from item import Item


# This is the music box object
# Here, you will need to allow the box to be open any time during the game.
class MusicBox(Item):
    def __init__(self):
        self.name = "music box"
        self.music_box_open = False
        super().__init__(self.name)

    def description(self):
        if self.music_box_open:
            print("\nThis is an ornate music box. It is open and playing a simple lullaby\n")
        elif not self.music_box_open:
            print("\nThis is an ornate music box. It is closed.")

    # player can open the box to listen to the song. It will be required to reach the library.
    def open_music_box(self):
        self.music_box_open = True
        print("A simple lullaby begins to play.")

    def close_music_box(self):
        self.music_box_open = False
        print("You close the music box")


if __name__ == "__main__":
    box = MusicBox()
    box.description()
    print(box)