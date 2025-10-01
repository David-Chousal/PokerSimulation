/*
 * CSEN 79 Lab: Poker Statistics
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace csen79;

// Generate one sample hand for each rank
void pokerHands(Poker &poker) { // generate one sample hand for each rank
	bool found[Poker::POKER_ARRAY_SIZE];
	memset(found, 0, sizeof(found));
	int numFound = 0;
	while (numFound < Poker::POKER_ARRAY_SIZE) {
		poker.dealHand();
		Poker::Rank r = poker.rankHand();
		if (!found[r]) {
			found[r] = true;
			numFound++;
			cout << setw(17) << Poker::RankNames[r] << ": " << poker << endl;
		}
	}
	cout << endl;
}

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) { // collect statistics for each rank of Poker
	time_t tmark = clock();			// start the clock
	const long long NUM_TRIALS = 8795000; // adjust larger for better accuracy
	unsigned long long counts[Poker::POKER_ARRAY_SIZE]; 
	memset(counts, 0, sizeof(counts));
	for (long long i = 0; i < NUM_TRIALS; ++i) {
		poker.dealHand();
		Poker::Rank r = poker.rankHand();
		counts[r]++;
	}
	tmark = clock() - tmark;	// stop the clock
	double seconds = static_cast<double>(tmark) / CLOCKS_PER_SEC;
	double secondsPer50k = seconds * 50000.0 / static_cast<double>(NUM_TRIALS);
	double secondsPerHand = seconds / static_cast<double>(NUM_TRIALS);

	cout << left << setw(18) << "Rank" << right << setw(12) << "Count" << setw(12) << "%" << endl;
	cout << setfill('-') << setw(42) << "" << setfill(' ') << endl;
	for (int r = 0; r < Poker::POKER_ARRAY_SIZE; ++r) {
		double pct = 100.0 * static_cast<double>(counts[r]) / static_cast<double>(NUM_TRIALS);
		cout << left << setw(18) << Poker::RankNames[r]
		     << right << setw(12) << counts[r]
		     << setw(11) << fixed << setprecision(6) << pct << "%" << endl;
	}
	cout.unsetf(ios::fixed);
	cout << endl;
	cout << "Dealt " << NUM_TRIALS << " hands" << ", time elapsed: " << seconds << " s" << endl;
	cout << fixed << setprecision(6);
	cout << "Time per 50k hands: " << secondsPer50k << " s" << endl;
	cout << "Average time per hand: " << secondsPerHand << " s" << endl;
	cout.unsetf(ios::fixed);
}

int main(void) {
	Poker poker;
	cout << "Sample hand for each Rank:" << endl;
	pokerHands(poker);
	cout << endl << "Statistics:" << endl;
	pokerStats(poker);

	return EXIT_SUCCESS;
}
