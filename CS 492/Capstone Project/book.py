from item import Item


# This is the book object. You can read it in any room. You can read just the inscription on the first page.
# It can be placed in the empty slot on the bookshelf to open secret compartment.
class Book(Item):
    def __init__(self):
        self.name = "book"
        super().__init__(self.name)

    @staticmethod
    def description():
        print("\nThis is an ancient book in a language you cannot understand. There is something written\n"
              "on the first page. It's an inscription that says: \"This book belongs with the other books\"")


if __name__ == "__main__":
    book = Book()
    book.description()
    print(book)