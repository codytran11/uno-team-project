#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "deck.h"

using namespace std;

int main() {
    srand(time(nullptr));

    Deck deck;
    cout << "Starting size: " << deck.size() << endl;

    deck.shuffle();

    Card drawn = deck.drawCard();
    cout << "Drew: " << drawn.toString() << endl;
    cout << "After drawing: " << deck.size() << endl;

    while(!deck.isEmpty()) {
        deck.drawCard();
    }

    cout << "Empty: " << boolalpha << deck.isEmpty() << endl;

    try {
        deck.drawCard();
    }
    catch(const out_of_range& error) {
        cout << error.what() << endl;
    }

    vector<Card> discards;
    discards.push_back(Card("Red", 3));
    discards.push_back(Card("Blue", 7));

    deck.refill(discards);
    cout << "After refill: " << deck.size() << endl;

    return 0;
}