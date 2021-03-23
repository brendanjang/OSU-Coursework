"""Source Program for Homework #4 for CS 3A
Written by Dong Hee Jang, 6/3/2018

----------------Assignment 4 Part 1 Source-----------------"""
# Set up the range of years
controlRange = range(1987, 2013)

# Loop through each year
for year in controlRange:

    digitCount = [0] * 10
    yearStr = str(year)

    # Loop through each character
    for num in yearStr:
        newNum = int(num)

        # Count up each digit found in digitCount
        digitCount[newNum] += 1

    # Assume there is no duplicate
    isDuplicate = False

    # Loop with numeration through each digitCount
    for value, newNum in enumerate(digitCount):

        # If count > 1
        if newNum > 1:
            isDuplicate = True
            print("Year {0}:"
                  " {1} occurrences of digit {2}".format(year, newNum, value))

    # If count < 1 there are no duplicates
    if not isDuplicate:
        print("Year {0}: No duplicates".format(yearStr))
