#ifndef CARD_H
#define CARD_H

#include <string>

class Card{
  public:
    Card(std::string color, int value);
    std::string getColor() const;
    int getValue() const;

    std::string toString() const;
    bool canPlay(const Card& topCard) const;

  private:
    std::string color_;
    int value_;
};
#endif