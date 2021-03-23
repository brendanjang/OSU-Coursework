"""Source Program for Homework #5 for CS 3A
Written by Dong Hee Jang, 6/8/2018
-----------------Assignment 5 Part 1 Source--------------------"""
# Set up list of numbers to check if prime.
candidatePrimes = [10, 12, 15, 17, 31, 89, 97, 3335, 62542, 967584]

# Loop through each candidate in list
for candidate in candidatePrimes:
    num = 2
    # Assume candidate is a prime number
    isPrime = True
    # Use half of the integer of the value of candidate
    while num <= candidate // 2:
        # If the mod division is equal to zero, is not prime
        if candidate % num == 0:
            isPrime = False
            break
        num += 1
    if isPrime:
        print("{0} is prime".format(candidate))
    else:
        print("{0} is not prime".format(candidate))

