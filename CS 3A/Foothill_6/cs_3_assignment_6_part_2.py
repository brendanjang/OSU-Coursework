"""There is an index error occurring on line 10 at the end of the loop. The
iteration variable i is holding the value and not pointing to the item
directly. When i == 2, index 4 in myCheeseList (Emmental) is deleted. Once
Emmental is deleted, Gloucester which had the index 5 becomes the new index 4
and Gouda which had the index 6, becomes the new index 5. This causes the
IndexError, list index out of range to be given. We can fix this problem by
using the built in function enumerate(). This will give us a tuple made up of
the list index and its corresponding value in each iteration. Then we can use
the index to modify the list as we see fit."""

# set up a list to iterate on
myCheeseList = ["Apple", "Asiago", "Brie", "Caerphilly", "Emmental",
                "Gloucester", "Gouda"]

for i, item in enumerate(myCheeseList):
    if i == 2:
        del myCheeseList[4]
    print(i, myCheeseList[i])