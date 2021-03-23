from item import Item


# This is the recorder object
# This can be taken and used to play recording in any room. It will require a slot to insert cassette tape.
# I will need to figure out how to insert tape object. I think the best way will be to have a method in the
# roomTile class.
class Recorder(Item):
    def __init__(self):
        self.name = "recorder"
        self.items = []
        self.tape_in_recorder = False
        super().__init__(self.name)

    def description(self):
        if not self.items:
            print("This is an old fashioned cassette tape recorder. There is nothing in it.")
        else:

            a_tape = self.items[0]
            i = getattr(a_tape, 'name')
            print(f"\nThis is an old fashioned cassette tape recorder. There is a {i} in the recorder.\n")

    # add tape to recorder
    def add_tape(self, item, player):
        item_added = False
        for n in player.inventory_list:
            if n.name == item.name and n not in self.items:
                player.inventory_list.remove(n)
                self.items.append(n)
                item_added = True
                print(f"\n{item} was removed from your inventory\n")
                self.tape_in_recorder = True
        if not item_added:
            print(f"\nYou do not have a {item}.\n")

    # remove tape from recorder
    def remove_tape(self, item, player):
        print("You remove the tape from the recorder and place it in inventory")
        item_removed = False
        for n in self.items:
            if n.name == item.name and n not in player.inventory_list:
                player.inventory_list.append(n)
                self.items.remove(n)
                item_removed = True
                self.tape_in_recorder = False
        if not item_removed:
            print(f"\nThere is no {item} here.\n")

    # play the recorder
    def play_recorder(self):
        if self.items:
            a_tape = self.items[0]
            i = getattr(a_tape, 'name')

            if i == 'cassette tape':
                print("A garbled voice speaks through the small speakers of the recorder. It sounds\n"
                      "disembodied and strange to your ears, a voice of an old man. He speaks about\n"
                      "how he had put a great secret in the library. He then shouts: \"They will never\n"
                      "escape. Never!\"")
            else:
                print("There is nothing in the recorder. Perhaps looks for a tape?")
        else:
            print("There is nothing in the tape recorder.")

if __name__ == "__main__":
    recorder = Recorder()
    recorder.description()
    print(recorder)