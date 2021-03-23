from item import Item


# This is the cassette tape object
# It's only purpose is to go into the tape recorder. I think it will require a recording method to be called when
# the recorder is played.
class Tape(Item):
    def __init__(self):
        self.name = "cassette tape"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a cassette tape.\n")


if __name__ == "__main__":
    tape = Tape()
    tape.description()
    print(tape)