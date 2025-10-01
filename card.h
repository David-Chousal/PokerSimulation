/*
 * CSEN 79 Lab: Poker Statistics
 */
#ifndef CARD_H
#define CARD_H

#include <ostream>

// stand-alone Card class
namespace csen79 {
    class Card {
    public:
		/* 
		 * enum is a special "class" that enumerates the possible
		 * names.  Those names are uniquely mapped to intergers that
		 * are contiguous unless overridden In this case, Spade is
		 * "0", and what followed are numerically contiguous
		 */
		enum Suit : int {SPADE=0, HEART, DIAMOND, CLUB};
		/*
		 * Rank is the face value of a card.  Together with "suit",
		 * they define a card completely.  Here we chose the legal
		 * range of rank to be [1..13] (inclusive both ends) where
		 * "1" represennt "deuce" and "13" Ace.  Zero is reserved
		 * for error checking
		 */
		static const int NRANKS; // number of ranks
		static const int HonorIdx; // honors start at Jack (rank 11)
		static const char Honors[4]; // J, Q, K, A
		static const char *suitUCode[4]; // unicode for suits: spade, heart, diamond, club

		Card(Suit s=SPADE, int r=0) : rank{r}, suit{s} {
			if (r < 1 || r > NRANKS) {
				rank = 0;
				suit = SPADE;
			}
			if (s < SPADE || s > CLUB) {
				suit = SPADE;
			}
		}

		const int getRank() const { return rank; }
		const Suit getSuit() const { return suit; }

		// encode a card into an integer to facilitate comparison and sorting
		operator int() const { return suit + (rank << 2); }

		friend std::ostream& operator<<(std::ostream& os, const Card &c);

    private:
		int rank; // A, King, Queen, ..., 2 (stored as 1..13, 0 invalid)
		Suit suit; // suit of the card
    };
}

#endif // CARD_H
