from item import Item


# This is the matches object
class Matches(Item):
    def __init__(self):
        self.name = "matches"
        super().__init__(self.name)

    @staticmethod
    def description():
        return '\nIt is a bundle of matches. Maybe you can use it to light ' \
               'something.\n'


if __name__ == "__main__":
    matches = Matches()
    matches.description()
    print(matches)