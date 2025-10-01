/*
 * David Chousal
 * dchousal@scu.edu
 * CSEN 79 Lab: Poker Statistics
 */
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"

namespace csen79 {
    // Fisher-Yates shuffle
    void Deck::shuffle(void) { // shuffle the deck
        for (int i = static_cast<int>(CARDS_PER_DECK) - 1; i > 0; --i) { // shuffle the deck
            int j = std::rand() % (i + 1); // random index from 0 to i
            Card tmp = cards[i]; // swap the cards tmp is first card
            cards[i] = cards[j]; // swap the cards first card becomes second card
            cards[j] = tmp; // swap the cards second card becomes first card
        }
    }
    // Deal out one card; reshuffle when remaining < guard
    const Card &Deck::deal(void) { // deal out one card
        if (next >= nCards || (nCards - next) < guard) { // if the next card is the last card
            std::srand(static_cast<unsigned>(std::time(nullptr))); // random seed
            shuffle(); // shuffle the deck
            next = 0; // reset the next card index
        }
        return cards[next++]; // return the next card
    }
}

