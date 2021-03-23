"""Source Program for Homework #7 for CS 3A
Written by Dong Hee Jang, 6/15/2018
---------------- Assignment 7 Source ---------------------------"""

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
        self.string1 = string1
        self.string2 = string2
        self.string3 = string3

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

    def to_string(self):
        return "strings are:\n\n\t" + self.string1 + "\n\n\t"\
               + self.string2 + "\n\n\t" + self.string3 + "\n"

    # Helper methods for entire class -----------------
    def valid_string(self, the_str):
        return len(the_str) >= TripleString.MIN_LEN and len(
            the_str) <= TripleString.MAX_LEN and type(the_str) == str

# ------------- CLIENT --------------------------------------------------

# Create 4 TripleString objects
triple_string_num_1 = TripleString()
triple_string_num_2 = TripleString("Hello there.")
triple_string_num_3 = TripleString("How are you?", "This is blank.",
                                   "This is a test.")
triple_string_num_4 = TripleString("Hi over there.", "I am here.",
                                   "What's this?")

# Display TripleString objects
print(triple_string_num_1.to_string())
print(triple_string_num_2.to_string())
print(triple_string_num_3.to_string())
print(triple_string_num_4.to_string())

# Mutate one or more members of every object
triple_string_num_1.set_string1("Thor")
triple_string_num_2.set_string2("Iron Man")
triple_string_num_3.set_string3("Hulk")
triple_string_num_4.set_string1("Spider-Man")
triple_string_num_4.set_string2("Dr Strange")
triple_string_num_4.set_string3("Thanos")

# Display TripleString objects
print(triple_string_num_1.to_string())
print(triple_string_num_2.to_string())
print(triple_string_num_3.to_string())
print(triple_string_num_4.to_string())

# Do 2 explicit mutator tests
value = "This is a very long sentence that should fail the mutator test."

if triple_string_num_1.set_string1(value):
    print("Successful mutator test: " + value + "\n")
else:
    print("Failed mutator test: " + value + "\n")

value = "This falls within parameters."

if triple_string_num_1.set_string1(value):
    print("Successful mutator test: " + value + "\n")
else:
    print("Failed mutator test: " + value + "\n")

# Make 2 accessor calls
triple_string_num_1.set_string1("This")
triple_string_num_1.set_string2("should")
triple_string_num_1.set_string3("be a test")

if triple_string_num_1.get_string1() == "This":
    print("Accessor call passed with good value.")
else:
    print("Accessor call failed with bad value.")

if triple_string_num_1.get_string2() == "should":
    print("Accessor call passed with good value.")
else:
    print("Accessor call failed with bad value.")

if triple_string_num_1.get_string1() == "":
    print("Accessor call passed with good value.")
else:
    print("Accessor call failed with bad value.")

if triple_string_num_1.get_string1() == "This is a failed call":
    print("Accessor call passed with good value.")
else:
    print("Accessor call failed with bad value.")