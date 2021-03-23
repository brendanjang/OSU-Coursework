from item import Item


# This is the bucket object
class Bucket(Item):
    def __init__(self):
        self.isFull = False
        self.name = "bucket"
        super().__init__(self.name)

    def description(self):
        print("\nThis is a blue bucket made of plastic.\n"
              "This bucket can be filled with water and\n"
              "used to put out the fireplace in the first floor.\n"
              "To fill it, enter the command 'fill bucket'.")
        if self.isFull:
            print("Currently the bucket is full.\n")
        else:
            print("Currently the bucket is empty.\n")


if __name__ == "__main__":
    bucket = Bucket()
    bucket.description()
    print(bucket)
