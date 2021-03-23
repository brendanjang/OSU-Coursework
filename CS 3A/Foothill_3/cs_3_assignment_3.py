"""Source Program for Homework #3 for CS 3A
Written by Dong Hee Jang, 5/31/2018

----------------Assignment 3 Part 1 Source-----------------"""

# print dir on class list to display
print(dir(list))

"""--------------Assignment 3 Part 1 Run-------------------"""

C:\Users\Brendan\PycharmProjects\hw3\venv\Scripts\python.exe C:/Users/Brendan/PycharmProjects/hw3/cs_3_assignment_3_part_1.py
['__add__', '__class__', '__contains__', '__delattr__', '__delitem__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__gt__', '__hash__', '__iadd__', '__imul__', '__init__', '__init_subclass__', '__iter__', '__le__', '__len__', '__lt__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__reversed__', '__rmul__', '__setattr__', '__setitem__', '__sizeof__', '__str__', '__subclasshook__', 'append', 'clear', 'copy', 'count', 'extend', 'index', 'insert', 'pop', 'remove', 'reverse', 'sort']

Process finished with exit code 0

"""----------------Assignment 3 Part 2 Source-----------------"""

# create lists and empty list
firstList = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89]
secondList = [1, 2, 3, 4, 5, 6, 8, 7, 5, 9, 10, 11, 34, 12, 13]
combinedList = []

# if secondList has more values and if values not in combinedList already
if len(secondList) > len(firstList):
    for number in firstList:
        if number in secondList and number not in combinedList:
            combinedList.append(number)

# if firstList has more values and if values s in combinedList already
if len(secondList) < len(firstList):
    for number in secondList:
        if number in firstList and number not in combinedList:
            combinedList.append(number)

# print new combinedList with no duplicates
print(combinedList)

"""---------------Assignment 3 Part 2 Run--------------------"""
C:\Users\Brendan\PycharmProjects\hw3\venv\Scripts\python.exe C:/Users/Brendan/PycharmProjects/hw3/cs_3_assignment_3_part_2.py
[1, 2, 3, 5, 8, 13, 34]

Process finished with exit code 0

"""------------------Assignment 3 Part 3 Source-----------------"""

# create appropriate list and nested lists
dogs_purpose = ["A Dog's Purpose",
                ["Buddie", "Margot Robbie", "Carrie Fisher"]]
star_wars = ["Star Wars", ["Harrison Ford", "Carrie Fisher", "Mark Hamill"]]
am_legend = ["I am Legend", ["Kona", "Will Smith", "Carrie Fisher"]]
suicide_squad = ["Suicide Squad",
                 ["Viola Davis", "Margot Robbie", "Will Smith"]]
movies = [dogs_purpose, star_wars, am_legend, suicide_squad]

# if Carrie Fisher is in movie, add movie to m_list.
m_list = []
for actor in movies[0][1]:
    if actor == "Carrie Fisher":
        m_list.append(movies[0][0])

for actor in movies[1][1]:
    if actor == "Carrie Fisher":
        m_list.append(movies[1][0])

for actor in movies[2][1]:
    if actor == "Carrie Fisher":
        m_list.append(movies[2][0])

for actor in movies[3][1]:
    if actor == "Carrie Fisher":
        m_list.append(movies[3][0])

# print new m_list
print("Movies that star Carrie Fisher are: " + str(m_list) + ".\n")

# if Viola Davis is in movie = True -> break. If Fail, add to m_list.
m_list = []
for actor in movies[0][1]:
    if actor == "Viola Davis":
        break
else:
    m_list.append(movies[0][0])

for actor in movies[1][1]:
    if actor == "Viola Davis":
        break
else:
    m_list.append(movies[1][0])

for actor in movies[2][1]:
    if actor == "Viola Davis":
        break
else:
    m_list.append(movies[2][0])

for actor in movies[3][1]:
    if actor == "Viola Davis":
        break
else:
    m_list.append(movies[3][0])

# print new m_list
print("Movies that do not feature Viola Davis are: " + str(m_list) + ".\n")

# if Margot Robbie is in movie and Carrie Fisher is not, add to m_list.
m_list = []
for actor in movies[0][1]:
    if actor is "Margot Robbie" in movies[0][1] \
            and "Carrie Fisher" not in movies[0][1]:
        m_list.append(movies[0][1])

for actor in movies[1][1]:
    if actor is "Margot Robbie" in movies[1][1] \
            and "Carrie Fisher" not in movies[1][1]:
        m_list.append(movies[1][0])

for actor in movies[2][1]:
    if actor is "Margot Robbie" in movies[2][1] \
            and "Carrie Fisher" not in movies[2][1]:
        m_list.append(movies[2][0])

for actor in movies[3][1]:
    if actor is "Margot Robbie" in movies[3][1] \
            and "Carrie Fisher" not in movies[3][1]:
        m_list.append(movies[3][0])

# print new m_list
print("Movies that Margot Robbie is in, but Carrie Fisher is not are: "
      + str(m_list) + ".\n")

"""------------------Assignment 3 Part 3 Run-----------------"""

C:\Users\Brendan\PycharmProjects\hw3\venv\Scripts\python.exe C:/Users/Brendan/PycharmProjects/hw3/cs_3_assignment_3_part_3.py
Movies that star Carrie Fisher are: ["A Dog's Purpose", 'Star Wars', 'I am Legend'].

Movies that do not feature Viola Davis are: ["A Dog's Purpose", 'Star Wars', 'I am Legend'].

Movies that Margot Robbie is in, but Carrie Fisher is not are: ['Suicide Squad'].


Process finished with exit code 0

