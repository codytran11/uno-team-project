#include "game.h"
#include <iostream>

Game::Game(Player& human, Player& computer){
  players_[0] = &human;
  players_[1] = &computer;
  currentPlayer_ = 0;
}

void Game::setup(){
  deck_.shuffle();

  for(int i =0; i<7; i++){
    players_[0]->addCard(deck_.drawCard());
    players_[1]->addCard(deck_.drawCard());
  }
  discardPile_.push_back(deck_.drawCard());
}

bool Game::prepareDraw()
{
  if(!deck_.isEmpty()){
    return true;
  }

  if(discardPile_.size()<=1){
    return false;
  }

  Card topCard = discardPile_.back();
  discardPile_.pop_back();

  deck_.refill(discardPile_);

  discardPile_.clear();
  discardPile_.push_back(topCard);

  return true;
}

void Game::play(){
  if(discardPile_.empty()){
    std::cout << "Run setup before playing."<<std::endl;
    return;
  }

  while(true){
    Player* current = players_[currentPlayer_];

    std::cout << "\nTop card: "<< discardPile_.back().toString() << std::endl;
    std::cout << current->getName() << "'s turn"<<std::endl;

    int choice = current->chooseCard(discardPile_.back());
    if(choice == -1){
      if(!prepareDraw()){
        std::cout << "No cards available. Game ends in draw."<<std::endl;
        return;
      }

      current->addCard(deck_.drawCard());

      std::cout << current->getName() << " draws a card."<<std::endl;

    }
    else{
      Card played = current->removeCard(choice);
      discardPile_.push_back(played);

      std::cout << current ->getName() << " plays "<< played.toString() << std::endl;

      if(current->getHandSize() == 0){
        std::cout << current->getName() << " wins!"<<std::endl;
        return;
      }
    }
    currentPlayer_ = 1 - currentPlayer_;
  }
}