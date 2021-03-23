from item import Item


# This is the shrine object
class Shrine(Item):
    def __init__(self):
        self.name = "shrine"
        super().__init__(self.name)
        self.mirror_placed = False
        self.candles_lit = False
        self.picture_placed = False
        self.button_revealed = False
        self.button_pressed = False
        self.items = []

    def description(self):
        if self.button_revealed is False and self.mirror_placed is False \
                and self.candles_lit is False and self.picture_placed is False:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two unlit candles on the sides of the altar.\n ' 
                  'There is also an empty frame on the back of the altar.\n' 
                  'The center of the altar seems like it is missing '
                  'something.\n'
                  'Maybe you should find these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is True \
                and self.candles_lit is False and self.picture_placed is False:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two unlit candles on the sides of the altar.\n' 
                  'There is also an empty frame on the back of the altar.\n' 
                  'The center of the altar has a mirror on it.\n'
                  'Maybe you should find the rest of these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is False \
                and self.candles_lit is True and self.picture_placed is False:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two lit candles on the sides of the altar.\n' 
                  'There is also an empty frame on the back of the altar.\n' 
                  'The center of the altar seems like it is missing '
                  'something.\n'
                  'Maybe you should find these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is False \
                and self.candles_lit is False and self.picture_placed is True:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two unlit candles on the sides of the altar.\n' 
                  'There is also an frame with the painting of the little girl '
                  'on the back of the altar.\n'
                  'The center of the altar seems like it is missing '
                  'something.\n'
                  'Maybe you should find these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is True \
                and self.candles_lit is True and self.picture_placed is False:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two lit candles on the sides of the altar.\n' 
                  'There is also an empty frame on the back of the altar.\n' 
                  'The center of the altar has a mirror on it.\n'
                  'Maybe you should find these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is True \
                and self.candles_lit is False and self.picture_placed is True:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two lit candles on the sides of the altar.\n' 
                  'There is also an frame with the painting of the little girl '
                  'on the back of the altar.\n' 
                  'The center of the altar seems like it is missing '
                  'something.\n'
                  'Maybe you should find these items and place '
                  'them back where they belong.\n')
        if self.button_revealed is False and self.mirror_placed is False \
                and self.candles_lit is True and self.picture_placed is True:
            print('\nIt is a creepy wooden shrine with moonlight shining ' 
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There seems to be items missing from the shrine.\n'
                  'There are two lit candles on the sides of the altar.\n' 
                  'There is also a frame with the painting of the little girl '
                  'on the back of the altar.\n' 
                  'The center of the altar seems like it is missing '
                  'something.\n'
                  'Maybe you should find these items and place'
                  'them back where they belong.\n')
        if self.button_revealed is True:
            print('\nIt is a creepy wooden shrine with moonlight shining '
                  'on it. It seems to have been dedicated to someone that is '
                  'no longer in this world.\n'
                  'There are two lit candles on the sides of the altar.\n'
                  'There is also a frame with the painting of the little girl '
                  'on the back of the altar.\n'
                  '\nThe shrine is opened up revealing a small wooden ' 
                  'button inside of it.\n')

    def mirror_placed_desc(self):
        if self.candles_lit is True and self.picture_placed is True:
            self.mirror_placed = True
            self.button_revealed = True
            return '\nYou place the mirror on the center of the shrine. ' \
                   'You hear something in the shrine open.\n'
        else:
            self.mirror_placed = True
            return '\nYou place the mirror on the center of the shrine. ' \
                   'You can hear the sound of a gear turning.\n'

    def picture_placed_desc(self):
        if self.candles_lit is True and self.mirror_placed is True:
            self.picture_placed = True
            self.button_revealed = True
            return '\nYou place the picture of the girl on top of the ' \
                   'shrine. You hear something in the shrine open.\n'
        else:
            self.picture_placed = True
            return '\nYou place the picture of the girl on top of the ' \
                   'shrine. You hear a click.\n'

    def candles_lit_desc(self):
        if self.picture_placed is True and self.mirror_placed is True:
            self.candles_lit = True
            self.button_revealed = True
            return '\nYou light the candles. First the left then the right. ' \
                   'You hear something in the shrine open.\n'
        else:
            self.candles_lit = True
            return '\nYou light the candles. First the left then the right.\n'


if __name__ == "__main__":
    shrine = Shrine()
    shrine.description()
    print(shrine)