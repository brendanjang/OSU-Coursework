"""Source Program for Homework #5 for CS 3A
Written by Dong Hee Jang, 6/8/2018
-----------------Assignment 5 Part 1 Source--------------------"""

def isColliding(balla, ballb):
    # Method to calculate if two balls are colliding

    # Get balla and ballb values
    xa, ya, ra = balla
    xb, yb, rb = ballb
    # Calculate distance between balls
    d = ((xb-xa)**2 + (yb-ya)**2)**0.5
    # Return True if distance is less than or equal to
    # The sum of the balls' radii
    return d <= ra + rb

# Test Run
print("A(1, 1, 0.7), B(2, 62, 0.7):", isColliding((1, 1, 0.7), (2, 2, 0.7)))
print("B(1, 1, 0.8), B(2, 62, 0.8):", isColliding((1, 1, 0.8), (2, 2, 0.8)))
