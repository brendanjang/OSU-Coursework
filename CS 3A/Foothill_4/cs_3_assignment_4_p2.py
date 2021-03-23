"""----------------Assignment 4 Part 2 Source-----------------"""
ROW = 0.5
ROWS = 6
COLUMNS = 6

# Print with no end line
print("  ", end=" ")
COLUMN = 0.5

# Loop through each column to print header
for num in range(COLUMNS):
    print('{:>5}'.format(COLUMN), end=" ")
    COLUMN += 1
print("")

# Loop through each row
for num in range(ROWS):
    COLUMN = 0.5
    print(ROW, end=" ")

    # Loop through each column
    for newNum in range(COLUMNS):
        mul = ROW * COLUMN
        print('{:>5}'.format(mul), end=" ")
        COLUMN += 1
    ROW += 1
    print("")
