"""---------------Assignment 5 Part 2 Source----------------"""
# Function definitions
def isPrime(p):
    """p: Prime integers greater than 1, return: p. If not return: 0."""

    num = 2

    # Use half of the integer of the value of candidate
    while num <= p // 2:
        # If mod division is equal to zero, is not prime
        if p % num == 0:
            return 0
        num += 1
    return p

# Get integer input. If input == p value is prime, else value is not prime.
p = int(input("Enter an integer greater than 1: "))

if isPrime(p) == p:
    print("Result is {0}. {1} is prime.".format(isPrime(p), p))
else:
    print("Result is {0}. {1} is not prime.".format(isPrime(p), p))