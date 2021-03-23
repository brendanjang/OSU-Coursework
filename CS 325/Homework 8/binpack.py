"""	
Author:		 Brendan Jang
Date:		 8/15/2019
Description: Implementation file for binpack
"""

import time
class Item:

    def __init__(self, weight):

        self.weight = weight

    def __repr__(self):

        return "<Item: " + str(self.weight) + ">"

class Bin:

    def __init__(self, capacity):

        self.capacity = capacity
        self.available = self.capacity
        self.items = list()

    def place_item(self, item):
        self.items.append(item)
        self.available -= item.weight

    def __repr__(self):

        return "<Bin: " + str(len(self.items)) + ">"

class TestCase:

    def __init__(self, capacity):

        self.capacity = capacity
        self.items = list()

    def load_item(self, item):

        self.items.append(item)

    def __repr__(self):

        return "<TestCase: Capacity:" + str(self.capacity) + "-Size:" + str(len(self.items)) + ">"

    def first_fit(self, sizes=None):

        bins = list()

        if not sizes:
            sizes = [item.weight for item in self.items]

        ibin = Bin(self.capacity)

        while sizes:
            size = sizes.pop(0)
            bin_index = -1
            if bins:
                for i, ibin in enumerate(bins):
                    
                    if ibin.available >= size:
                        bin_index = i
                        break

                if bin_index >= 0:
                    bins[bin_index].place_item(Item(size))
                else:
                    ibin = Bin(self.capacity)
                    ibin.place_item(Item(size))
                    bins.append(ibin)
                

            else:
                ibin = Bin(self.capacity)
                ibin.place_item(Item(size))
                bins.append(ibin)
        
        return len(bins)

    def first_fit_decreasing(self):

        sizes = [item.weight for item in self.items]
        sizes = sorted(sizes, reverse=True)

        return self.first_fit(sizes)

    def best_fit(self):

        sizes = [item.weight for item in self.items]

        bins = list()

        while sizes:
            bin_index = -1
            size = sizes.pop(0)
            free_space = self.capacity
            
            if bins:
                for i, ibin in enumerate(bins):
                    
                    if ibin.available >= size and free_space > (ibin.available - size):
                        free_space = ibin.available - size
                        bin_index = i
                
                if bin_index >= 0:
                    bins[bin_index].place_item(Item(size))
                else:
                    ibin = Bin(self.capacity)
                    ibin.place_item(Item(size))
                    bins.append(ibin)

            else:
                ibin = Bin(self.capacity)
                ibin.place_item(Item(size))
                bins.append(ibin)

        return len(bins)

cases = list()

def load_cases(filename, cases):

    f = open(filename, "r")

    lines = f.readlines()

    f.close()

    size = int(lines.pop(0).strip())

    for i in range(size):

        capacity = int(lines.pop(0).strip())
        numbers = int(lines.pop(0).strip())

        case = TestCase(capacity)

        values = lines.pop(0).strip().split(" ")

        for value in values:

            item = Item(int(value))
            case.load_item(item)

        cases.append(case)

def main():

    filename = "bin.txt"

    load_cases(filename, cases)

    row_format = "Test Case {} First Fit: {}, {}."
    row_format += " First Fit Decreasing: {}, {}."
    row_format += " Best Fit: {}, {}."

    for i, case in enumerate(cases):
        now = time.time()
        ff = case.first_fit()
        t1 = time.time() - now
        t1 *= 100000

        now = time.time()
        ffd = case.first_fit_decreasing()
        t2 = time.time() - now
        t2 *= 100000

        now = time.time()
        bf = case.best_fit()
        t3 = time.time() - now
        t3 *= 100000

        
        print(row_format.format(i+1, ff, t1, ffd, t2, bf, t3))

if __name__ == "__main__":

    main()