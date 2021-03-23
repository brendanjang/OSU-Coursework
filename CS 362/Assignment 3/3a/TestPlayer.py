import Dominion
import random
import unittest

class TestPlayer(unittest.TestCase):

    NUM_TRIALS = 10

    # Test Player action_balance function
    def test_action_balance(self):
        player = Dominion.Player("Bob")
        self.assertEqual(player.action_balance(), 0.0)
        for i in range(TestPlayer.NUM_TRIALS):
            cost, actions, cards, buys, coins = [random.randint(1,30) for i in range(5)]
            card = Dominion.Action_card("name", cost, actions, cards, buys, coins)
            player.deck.append(card)
            balance = 0
            for c in player.stack():
                if c.category == "action":
                    balance = balance - 1 + c.actions
            balance = 70*balance / len(player.stack())
            self.assertEqual(player.action_balance(), balance)

    # Test Player calcpoints function
    def test_calcpoints(self):
        player = Dominion.Player("Bob")
        points = 3
        self.assertEqual(player.calcpoints(), points)
        for i in range(TestPlayer.NUM_TRIALS):
            vpoints = random.randint(1,30)
            card = Dominion.Card("name", "category", 0, 0, vpoints)
            player.deck.append(card)
            points += vpoints
            self.assertEqual(player.calcpoints(), points)
        for i in range(TestPlayer.NUM_TRIALS):
            card = Dominion.Gardens()
            player.deck.append(card)
            points2 = points + len(player.stack()) // 10 * (i+1)
            self.assertEqual(player.calcpoints(), points2)
            

    # Test Player draw function
    def test_draw(self):
        player = Dominion.Player("Bob")
        while len(player.deck) > 0:
            size = len(player.deck)
            card = player.deck[0]
            player.draw()
            self.assertEqual(len(player.deck), size-1)
            self.assertTrue(card in player.hand)
        player = Dominion.Player("Bill")
        dest = []
        while len(player.deck) > 0:
            size = len(player.deck)
            card = player.deck[0]
            player.draw(dest)
            self.assertEqual(len(player.deck), size-1)
            self.assertTrue(card in dest)

    # Test Player cardsummary function
    def test_cardsummary(self):
        player = Dominion.Player("Bob")
        points = 3
        self.assertEqual(player.cardsummary(), {'Estate': 3, 'Copper': 7, 'VICTORY POINTS': points})
        for i in range(TestPlayer.NUM_TRIALS):
            vpoints = random.randint(1,30)
            card = Dominion.Card("name", "category", 0, 0, vpoints)
            player.deck.append(card)
            points += vpoints
            self.assertEqual(player.cardsummary(), {'Estate': 3, 'Copper': 7, 'name': (i+1), 'VICTORY POINTS': points})


if __name__ == '__main__':
    unittest.main()
