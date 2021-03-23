"""Source Program for Homework #2 for CS 3A
Written by Dong Hee Jang, 5/24/2018"""

# set up input values for variables l_name, myId, and numLet:
l_name = "Jang"
myId = 12345678
numLet = len(l_name)

# start with given intro
print( "My family name is " + l_name + ".\n"
       "Number is " + str(myId) + ".\n"
       "The number of characters in my last name is " + str(numLet) + ".\n")

# first expression:
answer = myId % 17
print( str(myId) + " % 17 = " + str(answer) + "\n" )

# second expression:
answer = (numLet + 17) % 11
print( "(" + str(numLet) + " + 17) % 11 = " + str(answer) + "\n" )

# third expression:
answer = (myId) / (numLet + 800) 
print( str(myId) + " / (" + str(numLet) + " + 800) = " + str(answer) + "\n" )

# fourth expression:
answer = 1 + 2 + 3 + numLet
print( "1 + 2 + 3 + " + str(numLet) + " = " + str(answer) + "\n" )

# fifth expression:
answer = 15000 / (80 + ( (myId)-123456) / ( (numLet + 20) * (numLet + 20) ) )
print( "15000 / [80 + ((" + str(myId) + " - 123456) / (" + str(numLet) \
       + " + 20)^2)] = " + str(answer) + "\n")

"""----------------------Sample Run-------------------

== RESTART: C:\Users\Brendan\PythonProjects\Foothill_2\cs_3_assignment_2.py ==
My family name is Jang.
Number is 12345678.
The number of characters in my last name is 4.

12345678 % 17 = 6

(4 + 17) % 11 = 10

12345678 / (4 + 800) = 15355.320895522387

1 + 2 + 3 + 4 = 10

15000 / [80 + ((12345678 - 123456) / (4 + 20)^2)] = 0.7042539383200707

>>> 
----------------------End Sample Run---------------"""
