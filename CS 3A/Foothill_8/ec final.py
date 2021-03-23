"""-------------------Extra Credit Source-------------------"""
import random


class TripleString:
    """ Encapsulates a 3-string object """
    # Intended class constants ------------------------------------
    MIN_LEN = 1
    MAX_LEN = 50
    DEFAULT_STRING = "(undefined)"

    # constructor method ------------------------------------
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
        except:
            print("Error: Invalid bet input")


# Method to get bet for simulation
def get_bet_simulation(num):
    if num < 100000:
        return 1
    else:
        return 0

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
    if winnings == 0:
        pass
    else:
        pass


# Main method for program execution
def main():
    counts = {"BAR": 0, "cherries": 0, "space": 0, "7": 0}
    winnings_total = [0, 0]
    n = 100000
    for i in range(n + 1):
        bet = get_bet_simulation(i)
        if bet == 0:
            break
        reels = pull()
        counts[reels.get_string1()] += 1
        counts[reels.get_string1()] += 1
        counts[reels.get_string1()] += 1
        pay_multiplier = get_pay_multiplier(reels)
        winnings = bet * pay_multiplier
        if winnings != 0:
            winnings_total[0] += winnings
            winnings_total[1] -= winnings
        else:
            winnings_total[0] -= bet
            winnings_total[1] += bet
        display(reels, winnings)

    print("--- SIMULATION RESULTS ---")
    print("")
    print("Number of simulations: " + str(n))
    print("")
    print("Symbol count:")
    print("cherries" + ": " + str(
        counts["cherries"]) + ", " + "Percentage: " + str(
        100 * counts["cherries"] / (3 * n)) + "% [ideal: 40%]")
    print("BAR" + ": " + str(counts["BAR"]) + ", " + "Percentage: " + str(
        100 * counts["BAR"] / (3 * n)) + "% [ideal: 38%]")
    print("7" + ": " + str(counts["7"]) + ", " + "Percentage: " + str(
        100 * counts["7"] / (3 * n)) + "% [ideal: 15%]")
    print("space" + ": " + str(counts["space"]) + ", " + "Percentage: " + str(
        100 * counts["space"] / (3 * n)) + "% [ideal: 7%]")
    print("")
    print("Winnings totals:")
    print("Gambler winnings: $" + str(winnings_total[0]))
    print("Casino winnings: $" + str(winnings_total[1]))


if __name__ == "__main__":
    main()
