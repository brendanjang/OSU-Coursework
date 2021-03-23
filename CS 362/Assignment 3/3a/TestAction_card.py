import Dominion
import random
import unittest

class TestAction_card(unittest.TestCase):
    
    NUM_TRIALS = 10

    # Test Action_card initialization
    def test_initialization(self):
        for n in range(TestAction_card.NUM_TRIALS):
            cost, actions, cards, buys, coins = [random.randint(1,30) for i in range(5)]
            card = Dominion.Action_card("name", cost, actions, cards, buys, coins)
            self.assertEqual(card.name, "name")
            self.assertEqual(card.category, "action")
            self.assertEqual(card.cost, cost)
            self.assertEqual(card.actions, actions)
            self.assertEqual(card.cards, cards)
            self.assertEqual(card.buys, buys)
            self.assertEqual(card.coins, coins)

    # Test Action_card use function
    def test_use(self):
        for n in range(TestAction_card.NUM_TRIALS):
            player = Dominion.Player("Bob")
            trash = []
            cost, actions, cards, buys, coins = [random.randint(1,30) for i in range(5)]
            card = Dominion.Action_card("name", cost, actions, cards, buys, coins)
            player.hand.append(card)
            card.use(player, trash)
            self.assertTrue(card not in player.hand)
            self.assertTrue(card in player.played)
        
    # Test Action_card augment function
    def test_augment(self):
        for n in range(TestAction_card.NUM_TRIALS):
            player = Dominion.Player("Bob")
            player.actions = 0
            player.buys = 0
            player.purse = 0
            hand = len(player.hand)
            cost, actions, cards, buys, coins = [random.randint(1,30) for i in range(5)]
            card = Dominion.Action_card("name", cost, actions, cards, buys, coins)
            card.augment(player)
            self.assertEqual(player.actions, card.actions)
            self.assertEqual(player.buys, card.buys)
            self.assertEqual(player.purse, card.coins)
            self.assertEqual(len(player.hand) - hand, min(card.cards, 5)) 

if __name__ == '__main__':
    unittest.main()
