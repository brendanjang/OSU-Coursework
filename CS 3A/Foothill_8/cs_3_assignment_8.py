"""Source Program for Homework #8 for CS 3A
Written by Dong Hee Jang, 6/17/2018
---------------- Assignment 8 Source ---------------------------"""
import random


class TripleString:
    """ Encapsulates a 3-string object """
    # Intended class constants ------------------------------------
    MIN_LEN = 1
    MAX_LEN = 50
    DEFAULT_STRING = "(undefined)"

    # Constructor method ------------------------------------
    def __init__(self,
                 string1=DEFAULT_STRING,
                 string2=DEFAULT_STRING,
                 string3=DEFAULT_STRING):
        self.set_string1(string1)
        self.set_string2(string2)
        self.set_string3(string3)

    # Mutator ("set") methods -------------------------------
    def set_string1(self, string1):
        if self.valid_string(string1):
            self.string1 = string1
            return True
        else:
            self.string1 = TripleString.DEFAULT_STRING
            return False

    def set_string2(self, string2):
        if self.valid_string(string2):
            self.string2 = string2
            return True
        else:
            self.string2 = TripleString.DEFAULT_STRING
            return False

    def set_string3(self, string3):
        if self.valid_string(string3):
            self.string3 = string3
            return True
        else:
            self.string3 = TripleString.DEFAULT_STRING
            return False

    # Accessor ("get") methods -------------------------------
    def get_string1(self):
        return self.string1

    def get_string2(self):
        return self.string2

    def get_string3(self):
        return self.string3

    # Helper methods for entire class -----------------
    def valid_string(self, the_str):
        return len(the_str) >= TripleString.MIN_LEN and len(
            the_str) <= TripleString.MAX_LEN


# Method to get bet
def get_bet():
    while True:
        bet = input("How much would you like to bet (1 - 50) or 0 to quit? ")
        try:
            bet = int(bet)
            if bet >= 0 and bet <= 50:
                return bet
            else:
                print("Error: Invalid bet input")
        except ValueError:
            print("Error: Invalid bet input")


# Method to pull slots
def pull():
    return TripleString(rand_string(), rand_string(), rand_string())


# Method to generate random string
def rand_string():
    r = random.randrange(100)
    if r < 38:
        return "BAR"
    elif r < 78:
        return "cherries"
    elif r < 85:
        return "space"
    else:
        return "7"


# Method to get pay multiplier
def get_pay_multiplier(reels):
    if reels.get_string1() == "7" and reels.get_string2() == "7" and \
            reels.get_string3() == "7":
        return 100
    elif reels.get_string1() == "BAR" and reels.get_string2() == "BAR" \
            and reels.get_string3() == "BAR":
        return 50
    elif reels.get_string1() == "cherries" and reels.get_string2() == \
            "cherries" and reels.get_string3() == "cherries":
        return 30
    elif reels.get_string1() == "cherries" and reels.get_string2() == \
            "cherries" and reels.get_string3() != "cherries":
        return 15
    elif reels.get_string1() == "cherries" and reels.get_string2() != \
            "cherries":
        return 5
    else:
        return 0


# Method to display pull winnings
def display(reels, winnings):
    print(' ' + reels.get_string1() + ' ,  ' +
          reels.get_string2() + ' ,  ' + reels.get_string3())
    if winnings == 0:
        print("sorry, you lose.")
    else:
        print("congratulations, you win: " + str(winnings))


# Main method for program execution
def main():
    while True:
        print("")
        bet = get_bet()
        if bet == 0:
            break
        print("whirrrrrr .... and your pull is ...")
        print("")
        reels = pull()
        pay_multiplier = get_pay_multiplier(reels)
        winnings = bet * pay_multiplier
        display(reels, winnings)
        print("")
    print("Thanks for coming to Casino Random, where the House always wins.")


if __name__ == "__main__":
    main()
