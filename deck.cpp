#include "deck.h"
#include <stdexcept>
#include <cstdlib>
Deck::Deck() {
  std::string colors[4]={
    "Red","Yellow","Green","Blue"
  };

  for(int c = 0; c<4; c++){
    for(int value=0; value<10; value++){
      cards_.push_back(Card(colors[c],value));
    }
  }
}

bool Deck::isEmpty() const {
  return cards_.empty();
}
int Deck::size() const{
  return cards_.size();
}

Card Deck::drawCard() {
  if(isEmpty()){
    throw std::out_of_range("Can't draw from an empty deck");
  }

  Card drawn = cards_.back();
  cards_.pop_back();
  return drawn;
}

void Deck::shuffle(){
    for(int i = size() - 1; i > 0; i--) {
        int j = std::rand() % (i + 1);

        Card temp = cards_[i];
        cards_[i] = cards_[j];
        cards_[j] = temp;
    }
}

void Deck::refill(const std::vector<Card>& cards){
  for(int i =0; i<cards.size(); i++){
    cards_.push_back(cards[i]);
  }
  shuffle();
}