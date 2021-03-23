import library
import random
import unittest

class TestLibrary(unittest.TestCase):

    '''
    Unit test to confirm positive behavior of functions
    '''
    def test_positive(self):
        container = []
        maxelements = 7
        library.create(container,maxelements)

        # Test remove positive cases
        self.assertEqual(library.size(container), 0)
        for n in range(maxelements):
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.add(n, container), 1)
            self.assertEqual(library.inList(n, container), 1)
            self.assertEqual(library.size(container), n+1)
        for n in range(maxelements):
            self.assertEqual(library.inList(n, container), 1)
            self.assertEqual(library.remove(n, container), 1)
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.size(container), maxelements-(n+1))
        self.assertEqual(library.size(container), 0)

        # Test removeAll positive cases
        self.assertEqual(library.size(container), 0)
        self.assertEqual(library.inList(9, container), 0)
        for n in range(maxelements):
            self.assertEqual(library.add(9, container), 1)
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.size(container), n+1)
        for n in range(maxelements,10):
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.add(9, container), 0)
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.size(container), maxelements)
        self.assertEqual(library.removeAll(9, container), maxelements)
        self.assertEqual(library.size(container), 0)

    '''
    Unit Test to confirm boundary behavior of functions
    '''
    def test_boundary(self):
        container = []
        maxelements = 7
        library.create(container,maxelements)

        # Test remove boundary cases
        self.assertEqual(library.inList(0, container), 0)
        self.assertEqual(library.remove(0, container), 0)
        for n in range(maxelements):
            library.add(n, container)
        for n in range(maxelements,10):
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.add(n, container), 0)
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.size(container), maxelements)
        for n in range(maxelements,10):
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.remove(n, container), 0)
            self.assertEqual(library.inList(n, container), 0)
            self.assertEqual(library.size(container), maxelements)
        for n in range(maxelements):
            library.remove(n, container)
        self.assertEqual(library.remove(0, container), 0)
        self.assertEqual(library.inList(9, container), 0)

        # Test removeAll boundary cases
        self.assertEqual(library.inList(9, container), 0)
        self.assertEqual(library.removeAll(9, container), 0)
        for n in range(maxelements):
            self.assertEqual(library.add(9, container), 1)
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.size(container), n+1)
        for n in range(maxelements,10):
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.add(9, container), 0)
            self.assertEqual(library.inList(9, container), 1)
            self.assertEqual(library.size(container), maxelements)
        self.assertEqual(library.removeAll(9, container), maxelements)
        self.assertEqual(library.size(container), 0)
        self.assertEqual(library.removeAll(9, container), 0)
        self.assertEqual(library.inList(9, container), 0)

    '''
    Unit Test to confirm random behavior of functions
    '''
    def test_random(self):
        container = []
        maxelements = 7
        library.create(container,maxelements)

        random_numbers = [random.randint(1,9) for i in range(maxelements)]

        # Test random cases
        self.assertEqual(library.size(container), 0)
        size = 0
        for n in random_numbers:
            self.assertEqual(library.size(container), size)
            self.assertEqual(library.add(n, container), 1)
            size += 1
            self.assertEqual(library.inList(n, container), 1)
            self.assertEqual(library.size(container), size)
        for n in random_numbers:
            self.assertEqual(library.size(container), size)
            self.assertEqual(library.inList(n, container), 1)
            self.assertEqual(library.remove(n, container), 1)
            size -= 1
            self.assertEqual(library.size(container), size)
        self.assertEqual(library.size(container), 0)
        
# Run unit tests
if __name__ == '__main__':
    unittest.main()
