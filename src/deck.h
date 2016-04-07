/*
 * deck.h
 *
 *  Created on: Mar 13, 2016
 *      Author: Tumblr
 */

#ifndef SRC_DECK_H_
#define SRC_DECK_H_

#include <array>
#include "card.h"

class Deck {
private:
	std::array<Card* , 20> deck;
	std::string deckName;
	unsigned int count;
	bool well_formed();
	bool print_err(std::string err);
public:
	Deck();
	virtual ~Deck();
	Deck(const Deck &clone);
	Card * draw_card();
	Deck draw_cards(int num);
	Deck& operator=(const Deck &clone);
	void shuffle();
	bool add_card(Card* card);
	bool add_card(Card* card, unsigned int index);
	unsigned int size();
	std::string to_string();

};

#endif /* SRC_DECK_H_ */
