# author: Brendan Jang
class Textparser:
    def __init__(self, action='', preposition='', adjective='',
                 obj='', item='', phrase=''):
        self.action = action
        self.preposition = preposition
        self.adjective = adjective
        self.obj = obj
        self.item = item
        self.phrase = phrase

    def parser(self, user_input):
        actions = ['go', 'take', 'look', 'drop', 'pick', 'exit', 'open',
                   'close', 'help', 'start', 'loadgame', 'search', 'move',
                   'turn', 'flip', 'peek', 'kick', 'put', 'jump', 'punch',
                   'hit', 'pull', 'fill', 'flip', 'peek', 'kick', 'put', 'jump',
                   'punch', 'hit', 'pull', 'fill', 'lie', 'sit', 'get', 'walk',
                   'enter', 'light', 'climb', 'stir', 'pour', 'use', 'unlock',
                   'savegame', 'lift', 'remove', 'retrieve', 'grab', 'pick', 'eat',
                   'drink', 'change', 'press', 'tie', 'wear', 'tie', 'flush']

        take_alias = ['grab', 'pick']

        prepositions = ['above', 'across', 'against', 'along', 'among',
                        'around', 'at', 'before', 'behind', 'below', 'beneath',
                        'beside', 'between', 'by', 'down', 'from', 'in',
                        'into', 'near', 'of', 'off', 'on', 'to', 'toward',
                        'under', 'upon', 'with', 'within', 'show', 'out',
                        'near', 'of', 'off', 'on', 'to', 'toward', 'under',
                        'up', 'upon', 'with', 'within', 'show', 'out', 'tool',
                        'dig', 'play']

        adjectives = ['first', 'second', 'third', 'old', 'hidden', 'small']

        keywords = ['north', 'south', 'east', 'west', 'down', 'left',
                    'right', 'map', 'inventory', 'door', 'game', 'music',
                    'chest', 'painting', 'window', 'light', 'lights', 'tank',
                    'shelf', 'fusebox', 'switches', 'mannequin', 'blanket',
                    'couch', 'table', 'chair', 'bed', 'water', 'center',
                    'drawer', 'compartment', 'couch', 'table', 'chair', 'bed',
                    'water', 'dresser', 'fist', 'wardrobe', 'tv', 'stand',
                    'music', 'ash', 'fireplace', 'ash', 'elevator', 'floor',
                    'mat', 'hole', 'refrigerator', 'oven', 'piano', 'bookcase',
                    'time', 'clock', 'button', 'rooms', 'cassette', 'fuses',
                    'shower', 'sink']

        items = ['key', 'mirror', 'box', 'flashlight', 'picture', 'sink',
                 'toilet', 'pills', 'coat', 'scarf', 'poker', 'bucket', 'arm',
                 'tape', 'batteries', 'shovel', 'key', 'tap', 'bathtub',
                 'ribs', 'bottle', 'desk', 'tape', 'batteries', 'shovel',
                 'key', 'tap', 'bathtub', 'ribs', 'bottle', 'duster', 'note',
                 'recorder', 'tape', 'watch', 'rope', 'shrine', 'box', 'rug',
                 'matches', 'candles', 'shrine', 'matches', 'book', 'candle', 'batteries2']

        phrase = []

        # take user input and change it to lower case and
        # split into list of words
        words = user_input.lower().split()

        # check input for preposition
        # if none found, sentence format is verb + keyword
        # if found, sentence format is verb + preposition + keyword
        # added a list for special items that the player can interact withs
        for word in words:
            if word in actions:
                if word in take_alias:
                    self.action = 'take'
                    phrase.append(self.action)
                elif words[0] == 'pick' and words[1] == 'up':
                    self.action = 'take'
                else:
                    self.action = word
                    phrase.append(self.action)
            elif word in prepositions:
                if word == 'up':
                    continue
                else:
                    self.preposition = word
                    phrase.append(self.preposition)
            elif word in adjectives:
                self.adjective = word
                phrase.append(self.adjective)
            elif word in keywords:
                self.obj = word
                phrase.append(self.obj)
            elif word in items:
                self.item = word
                phrase.append(self.item)
            else:
                continue

        # combine words in list into key phrase
        self.phrase = ' '.join(phrase)

        return self.phrase
