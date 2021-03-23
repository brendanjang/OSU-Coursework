"""---------------CS 3 Assignment 6 Part 4 EN & SP----------------"""
# Create data structure with en/sp words
sp_words = ["abeja", "iguana", "alacrán", "jirafa", "araña"]
en_words = ["bee", "iguana", "scorpion", "giraffe", "spider"]

# Create dictionary with spanish and english translations
dictionary = {}
for entry in range(len(sp_words)):
    sp_word = sp_words[entry]
    en_word = en_words[entry]
    dictionary[("sp", "en", sp_word)] = en_word
    dictionary[("en", "sp", en_word)] = sp_word

def translate(fm, to, word):
    # Method to translate from one language to another using dictionary

    if (fm, to, word) in dictionary:
        return dictionary[(fm, to, word)]
    else:
        return ""

# Test cases
word = translate("en", "sp", "bee")
print("Spanish for bee: ", word)
word = translate("en", "sp", "iguana")
print("Spanish for iguana: ", word)
word = translate("en", "sp", "scorpion")
print("Spanish for scorpion: ", word)
word = translate("en", "sp", "giraffe")
print("Spanish for giraffe: ", word)
word = translate("sp", "en", "abeja")
print("English for abeja: ", word)
word = translate("sp", "en", "iguana")
print("English for iguana: ", word)
word = translate("sp", "en", "alacrán")
print("English for alacrán: ", word)
word = translate("sp", "en", "jirafa")
print("English for jirafa: ", word)

# Test case key does not exist
word = translate("en", "sp", "flea")
print("Spanish for flea: ", word)