#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck{
  public:
    Deck();

    void shuffle();
    bool isEmpty() const;
    int size() const;

    Card drawCard();

    void refill(const std::vector<Card>& cards);

  private:
    std::vector<Card> cards_;

};

#endif