# Poker Simulation - CSEN 79

## Requirements
- C++20 compiler (g++/clang++)
- make

## Build Everything
```bash
make
```
This compiles all sources and links the executables:
- `cardtest`
- `decktest`
- `pokertest`

## Run
```bash
./cardtest    # prints all cards
./decktest    # demonstrates shuffling and dealing
./pokertest   # sample poker hands + statistics
```

## Build/Run Individual Targets
```bash
make cardtest && ./cardtest
make decktest && ./decktest
make pokertest && ./pokertest
```

## Clean
```bash
make clean
```
Removes object files and executables.

## Notes
- You can adjust the number of trials for poker statistics in `pokermain.cxx` (`NUM_TRIALS`). Larger values improve accuracy but take longer.

