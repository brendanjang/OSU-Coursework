"""------------CS 3 Assignment 6 Part 4 EN & SP & GR-------------"""
# Create data structure with en/sp/gr words
sp_words = ["abeja", "iguana", "alacrán", "jirafa", "araña"]
en_words = ["bee", "iguana", "scorpion", "giraffe", "spider"]
gr_words = ["μέλισσα", "ιγκουάνα", "σκορπιός", "καμηλοπάρδαλη", "αράχνη"]

# Create dictionary with spanish, english, and greek translations
dictionary = {}
for entry in range(len(sp_words)):
    sp_word = sp_words[entry]
    en_word = en_words[entry]
    gr_word = gr_words[entry]
    dictionary[("sp", "en", sp_word)] = en_word
    dictionary[("en", "sp", en_word)] = sp_word
    dictionary[("sp", "gr", sp_word)] = gr_word
    dictionary[("gr", "sp", gr_word)] = sp_word
    dictionary[("gr", "en", gr_word)] = en_word
    dictionary[("en", "gr", en_word)] = gr_word

def translate(fm, to, word):
    # Method to translate from one language to another using dictionary

    if (fm, to, word) in dictionary:
        return dictionary[(fm, to, word)]
    else:
        return ""

# Test cases
word = translate("en", "sp", "bee")
print("Spanish for bee: ", word)
word = translate("sp", "gr", word)
print("Greek from Spanish for bee: ", word)

word = translate("en", "sp", "iguana")
print("Spanish for iguana: ", word)
word = translate("sp", "gr", word)
print("Greek from Spanish for iguana: ", word)

word = translate("en", "sp", "scorpion")
print("Spanish for scorpion: ", word)
word = translate("sp", "gr", word)
print("Greek from Spanish for alacrán: ", word)

word = translate("sp", "gr", "jirafa")
print("Greek for jirafa: ", word)
word = translate("gr", "en", word)
print("English from Greek for καμηλοπάρδαλη: ", word)

word = translate("gr", "en", "αράχνη")
print("English for αράχνη: ", word)
word = translate("en", "sp", word)
print("Spanish from English for spider: ", word)

# Key doesn't exist
word = translate("en", "sp", "caterpillar")
print("Spanish for caterpillar: ", word)
word = translate("sp", "gr", word)
print("Greek from Spanish for caterpillar: ", word)