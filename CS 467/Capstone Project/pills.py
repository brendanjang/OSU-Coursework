from item import Item


# This is the pills object
class Pills(Item):
    def __init__(self):
        self.name = "pills"
        super().__init__(self.name)

    @staticmethod
    def description():
        return "\nAn empty pill bottle.\n"


if __name__ == "__main__":
    pills = Pills()
    pills.description()
    print(pills)