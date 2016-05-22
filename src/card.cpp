/*
 * card.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: Tumblr
 */

#include "card.h"
#include "console/utils.h"

using namespace std;

// Default contructor. This should rarely be called
// except for maybe when a token creature is generated
Card::Card() {
	// TODO Auto-generated constructor stub
	build_card("void");
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

void Card::build_card(string arg) {
	// TODO have card stats based on
	// input arg. This method is not set
	// in stone and can change to improve
	// performance and build times
	if      (arg == name)    return;
	else if (arg == "test1") {
		attack = 4;
		health = 2;
		cost = 3;
		currHP = health;
		ability = "Does a thing.";
		name = "Test1";
	} else if (arg == "test2") {
		attack = 3;
		health = 3;
		cost = 3;
		currHP = health;
		ability = "Does a thing.";
		name = "Test2";
	} else if (arg == "test3") {
		attack = 2;
		health = 2;
		cost = 2;
		currHP = health;
		ability = "Does a thing.";
		name = "Test3";
	} else if (arg == "void") {
		attack = 1;
		health = 1;
		cost = 1;
		currHP = health;
		ability = "Does a thing.";
		name = "Void";
	}

	image.set_image(load_file("card_template"));
	
	image.parse_flag("{0}", name, "left-pad");
	image.parse_flag("{1}", std::to_string(cost), "left-pad");
	image.parse_flag("{2}", ability);
	image.parse_flag("{3}", std::to_string(attack), "left-pad");
    image.parse_flag("{4}", std::to_string(currHP), "right-pad");
}

bool Card::trigger() {
	// TODO have the card's ability work here
	// so that at the start and end of each turn all cards
	// in play can have their tigger() called and their
	// ability checked. It should return true if the trigger
	// conditions are met. and goes off; false otherwise.

	// we should save looking at this for last. Many abilities
	// will be similar. So there must be a better way to have the
	// trigger work given the card name, without a uniquie ability
	// for each card.
	return true;
}

// Prints the card name in the form:
// NAME
// DESCRIPTION OF ABILITY
// (or flavor text)
// Atk/Def 
string Card::to_string() {
	string ret = name + "\n";
	ret += ability + "\n";
	ret += std::to_string(attack) + "/" + std::to_string(currHP);
	return ret;
}
