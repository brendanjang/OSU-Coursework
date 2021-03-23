import Dominion
import random
import unittest

class TestGameOver(unittest.TestCase):

    NUM_TRIALS = 10

    # Test gameover function
    def test_gameover(self):
        for i in range(TestGameOver.NUM_TRIALS):
            supply = {}
            supply["Copper"] = [Dominion.Copper()] * random.randint(0,1)
            supply["Silver"] = [Dominion.Silver()] * random.randint(0,1)
            supply["Gold"] = [Dominion.Gold()] * random.randint(0,1)
            supply["Estate"] = [Dominion.Estate()] * random.randint(0,1)
            supply["Duchy"] = [Dominion.Duchy()] * random.randint(0,1)
            supply["Province"] = [Dominion.Province()] * random.randint(0,1)
            supply["Curse"] = [Dominion.Curse()] * random.randint(0,1)
            out = 0
            for stack in supply:
                if len(supply[stack]) == 0:
                    out += 1
            expected = (out >= 3 or len(supply["Province"]) == 0)
            self.assertEqual(Dominion.gameover(supply), expected)

if __name__ == '__main__':
    unittest.main()
