/*
 * David Chousal
 * CSEN 79 Lab: Poker Statistics
 */
#ifndef DECK_H
#define DECK_H

#include <cstddef>
#include <ostream>
#include "card.h"

namespace csen79 {
    /*
     * Abstract one deck of playing cards, without Jokers.
     * "deal" returns the top of the deck. It reshuffles when
     * the number of remaining cards drops below the "guard" value.
     */
    class Deck {
    public:
        static const size_t CARDS_PER_DECK = 52;
        static const int SHUFFLE_THRESHOLD = 5; // for demo/testing intervals

        Deck(): Deck(5) {}	// default guard
        Deck(int);	// argument is the guard
        const Card &deal(void);
        void shuffle(void);

    friend std::ostream& operator<<(std::ostream& os, const Deck &);

    private:
        int nCards;	// number of cards across all decks (currently 52)
        Card cards[CARDS_PER_DECK]; // cards in the deck
        int next;   	// index of next card to deal
        int guard;  	// reshuffle when remaining < guard
    };
}

#endif
