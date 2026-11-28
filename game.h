#ifndef GAME_H
#define GAME_H

#include <vector>
#include "deck.h"
#include "player.h"

class Game{
  public:
    Game(Player& human, Player& computer);

    void setup();
    void play();

  private:
    Deck deck_;
    std::vector<Card> discardPile_;

    Player* players_[2];
    int currentPlayer_;

    // Make a card available to draw if possible.
    // Return false if no cards can be supplied.
    bool prepareDraw();
};

#endif

