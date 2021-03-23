# hw8.py

import time

from random import randint
import matplotlib.pyplot as plt

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


class Packing:

    def __init__(self, capacity=10):

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

    item_size = list(range(100, 10000, 200))

    packings = list()

    first_fit = list()
    first_fit_decreasing = list()
    best_fit = list()

    ff_time = list()
    ffd_time = list()
    bf_time = list()

    for i in item_size:

        packing = Packing()

        for j in range(i):

            item = Item(randint(1, 10))
            packing.load_item(item)

        packings.append(packing)

    for packing in packings:

        now = time.time()
        ff = packing.first_fit()
        elapsed = time.time() - now
        ff_time.append(elapsed)

        now = time.time()
        ffd = packing.first_fit()
        elapsed = time.time() - now
        ffd_time.append(elapsed)

        now = time.time()
        bf = packing.best_fit()
        elapsed = time.time() - now
        bf_time.append(elapsed)

        first_fit.append(ff)
        first_fit_decreasing.append(ffd)
        best_fit.append(bf)

    plt.style.use('seaborn-darkgrid')
    plt.plot(item_size, first_fit, color='skyblue', linewidth=1, label="first fit")
    plt.plot(item_size, first_fit_decreasing, color='red', linewidth=1, label="first fit decreasing")
    plt.plot(item_size, best_fit, color='green', linewidth=1, label="best fit")
    plt.legend()
    plt.xlabel("Number of Items")
    plt.ylabel("Number of bins")

    plt.show()

    plt.style.use('seaborn-darkgrid')
    plt.plot(item_size, ff_time, color='skyblue', linewidth=1, label="first fit")
    plt.plot(item_size, ffd_time, color='red', linewidth=1, label="first fit decreasing")
    plt.plot(item_size, bf_time, color='green', linewidth=1, label="best fit")
    plt.legend()
    plt.xlabel("Number of Items")
    plt.ylabel("Running Time")

    plt.show()

if __name__ == "__main__":

    main()
    
