#include "card.h"

Card::Card(std::string color, int value){
  color_=color;
  value_=value;
}

std::string Card::getColor() const{
  return color_;
}

int Card::getValue() const{
  return value_;
}

std::string Card::toString() const{
  return color_ + " " + std::to_string(value_);
}

bool Card::canPlay(const Card& topCard) const{
  return color_ == topCard.color_ || value_ == topCard.value_;

}