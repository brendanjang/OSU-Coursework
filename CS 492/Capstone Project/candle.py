from item import Item


# This is the candle object
class Candle(Item):
    def __init__(self):
        self.name = "candle"
        super().__init__(self.name)
        self.lit = False

    def description(self):
        if self.lit is False:
            print('\nThey are a pair of unlit candles sitting on top of '
                  'the shrine.\n')
        else:
            print('\nThey are a pair of lit candles sitting on top of the '
                  'shrine. Their flickering creates shadows that dance '
                  'around the room.\n')


if __name__ == "__main__":
    candle = Candle()
    candle.description()
    print(candle)