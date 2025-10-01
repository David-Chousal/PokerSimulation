/*
 * CSEN 79 Lab: Poker Statistics
 */
#include <iomanip>
#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;
using namespace csen79;

// Test program for Deck class
int main(void) {
	Deck deck; // create a deck
	cout << "Fresh deck: " << endl << deck << endl;
	deck.shuffle(); // shuffle the deck
	int nDeals{20}; // number of deals
	cout << "Shuffle then deal " << nDeals * 13 << " cards" << endl;
	int stats[Deck::CARDS_PER_DECK] = {0}; // initialize the stats
	int shuffleThreshold = Deck::SHUFFLE_THRESHOLD; // initialize the shuffle threshold (nDeals)
	// Essentially test only with dealing.  That trigger shuffling
	for (auto i = 0; i < nDeals; i++) { // print the deal number
		cout << setw(2) << i + 1 << setw(0) << ": "; // print the deal number
		for (auto j = 0; j < 13; j++) { // print 13 cards each row
			Card c = deck.deal(); // deal a card
			cout << c; // print the card
			stats[c-4]++; // increment the stats
			if (i == shuffleThreshold) { // if the deal is the shuffle threshold
				cout << "Shuffling at deal " << i + 1 << endl; // print the shuffle threshold
				deck.shuffle(); // shuffle the deck
				shuffleThreshold += Deck::SHUFFLE_THRESHOLD; // increment the shuffle threshold
			}
		}
		cout << endl; // print a new line
	}

	return 0;
}

