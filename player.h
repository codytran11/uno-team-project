#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

class Player{
  public:
    Player(std::string name);
    virtual ~Player();

    std::string getName() const;
    int getHandSize() const;

    void addCard(const Card& card);

    Card removeCard(int index);

    virtual int chooseCard(const Card& topCard) = 0;

  protected:
    std::vector<Card> hand_;
};

#endif