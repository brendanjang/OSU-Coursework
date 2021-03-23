from item import Item


# This is the note object. You can read this note in any room.
class Note(Item):
    def __init__(self):
        self.name = "note"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is a partially burned note.  It has a few lines of writing that is not burned. It says:\n"
              "To move on, you must play my favorite tune. It is...")


if __name__ == "__main__":
    note = Note()
    note.description()
    print(note)