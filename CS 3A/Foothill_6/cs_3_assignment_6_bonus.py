"""---------------CS 3 Assignment 6 Bonus Source----------------"""
import random

# Create data structures for en/sp/gr words using files
sp_words = []
for line in open("1kwords.sp.txt", encoding="utf8"):
    sp_words.append(line.strip())
en_words = []
for line in open("1kwords.en.txt", encoding="utf8"):
    en_words.append(line.strip())
gr_words = []
for line in open("1kwords.gr.txt", encoding="utf8"):
    gr_words.append(line.strip())

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


# Random test cases using random module.
# Use random.randint() to get randomly selected integer in range(a, b+1)
for num in range(5):
    en_word = en_words[random.randint(0, 999)]
    print(en_word, "in Spanish: ", translate("en", "sp", en_word))
for num in range(5):
    en_word = en_words[random.randint(0, 999)]
    print(en_word, "in Greek: ", translate("en", "gr", en_word))
for num in range(5):
    sp_word = sp_words[random.randint(0, 999)]
    print(sp_word, "in English: ", translate("sp", "en", sp_word))
for num in range(5):
    sp_word = sp_words[random.randint(0, 999)]
    print(sp_word, "in Greek: ", translate("sp", "gr", sp_word))
for num in range(5):
    gr_word = gr_words[random.randint(0, 999)]
    print(gr_word, "in Spanish: ", translate("gr", "sp", gr_word))
for num in range(5):
    gr_word = gr_words[random.randint(0, 999)]
    print(gr_word, "in English: ", translate("gr", "en", gr_word))