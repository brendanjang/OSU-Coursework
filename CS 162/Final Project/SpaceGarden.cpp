/***************************************************************************** 
** Program Name:	Final Project - SpaceGarden.cpp
** Author:			Brendan Jang
** Date:			3/14/2019
** Description:		Implementation file for Space Garden class.
*****************************************************************************/

#include "SpaceGarden.hpp"
#include "Game.hpp"
#include <iostream>
using namespace std;

SpaceGarden::SpaceGarden() {
    name = "garden";
    task = "Water all the plants.";
}

SpaceGarden::~SpaceGarden() {
}

/**
 * watering the garden
 */
void SpaceGarden::watering() {
    cout << "OK, let's read the textbook.\n";
    cout << "Page 254\n";
    cout << "How to Water Plants Effectively\n";
    cout << "So it now comes to gardening! Want the most from your plants? "
			"To thrive, any plant needs the right amounts and kinds "
			"of sun, water, heat and soil. Watering your plants is key to "
			"keeping them healthy.\n";
    cout << "1.Check soil carefully. There are two types of soil:\n"
			<< "\tDry soil - It can be identified if the soil is sandy "
				"and has cracks in it.\n"
            << "\tClay soil - If the soil is sticky and muddy then it is "
				"clay soil.\n"
            << "2. Look at the type of plant. Is the plant younger, newly "
				"grown, or an older one. Younger plants can be at most 4-5 "
				"years of age. Then they are categorized as older plants. \n"
            << "3. Research how much water your plants need. This varies from "
				"species to species, so look online or in a gardening book.\n"
            << "4. See if the soil is wet. If the plants are grown in dry "
				"soil, it would need more water and clay soil obviously needs "
				"less water as it has more moisture.\n"
            << "5. Give appropriate water. Remember that different kinds and "
				"ages of plants have different requirements. Younger ones "
				"typically need less water than older ones, while newly "
				"planted ones need only small amounts of water.\n"
            << "6. Get the timing right. The best time of day to water is "
				"always in the morning. This gives the plant time to absorb "
				"the water and get ready to handle heat, cold, or just the "
				"energy it takes to produce chlorophyll, grow, and move "
				"nutrients around. If you water in the late afternoon or "
				"evening, the problem is that the plant is now wet and the "
				"air temperature is cool. Those are the best conditions for "
				"mildews, molds, and all kinds of disease problems. Keep "
				"life simple, water in the morning. \n"
            << "7. Concentrate watering on the roots. Roots require more "
				"water than leaves. In fact roots only require water. As "
				"stated earlier wet leaves will lead to diseases.\n"
            << "8. Water slowly. Watering fast is like giving just 20% of "
				"the water to plants rest all go to waste. Water slower. "
				"Doing this, water will remain around roots as a result it "
				"will get more water. Watering fast may generate a great "
				"flow, causing erosion and leading to most of the water "
				"flowing away anyway.\n"
            << "9. Use a rain gauge. It measures how many centimetre the "
				"rain falls in that area so you will be able to give plants "
				"the desired quantity of water.\n"
            << "10. Use a sprinkler in your garden. Sprinklers are very "
				"effective. They give water to plants at the proper time, "
				"and you don't have to worry about doing it with a hose or "
				"watering can.\n"
            << "11. Micro-drip irrigation systems can be installed to deliver "
				"water directly to where the plants can use it. Applied "
				"slowly, water gradually soaks to the roots, rather than "
				"running off or evaporating. It will save you time and reduce "
				"the amount of water that's wasted. \n\n";
            
    cout << "There are a lot of instructions. "
            "It's time to pick up the sprinkler and make it work\n\n";
}

/**
 * action
 * @param player
 */
void SpaceGarden::action(Player* player) {
    if (normalAction(player) == DO_SOMETHING) {
        // water plants
        if (player->hasItem(Game::howToBook) == true) {
            string message [] = {
                "Do you want to water all plants in the garden?",
                "1, Yes",
                "2. No"
            };
            int selection = menu.getValue(message, 3, 1, 2);
            if (selection == 1) {
                this->finished = true;
                watering();
            } else {
                cout << "Nothing happens.\n";
            }
        } else {
            cout << "You don't have the "
                    << Game::howToBook->getDescription() << " in your hand.\n";
        }
    }
}