"""------------------Assignment 5 Part 3 Source--------------------"""
def isPrime(p):
    """p: Prime integers greater than 1, return: p. If not return: 0."""

    num = 2

    # Use half of the integer of the value of candidate
    while num <= p // 2:
        # If mod division is equal to 0, is not prime
        if p % num == 0:
            return 0
        num += 1
    return p

def primes1000():
    """Finds only the first 3 primes larger than 1000 using isPrime()."""

    number = 1000
    primes = 0

    # Set parameters
    while (primes < 3) or (number > 1500):

        # isPrime function to test for prime
        if isPrime(number) == number:
            print("{0} is prime.".format(number))
            primes += 1
        number += 1

# Main program ------------------------------------
primes1000()
