#ifndef __BET_HPP__
#define __BET_HPP__

enum BetType{
    Zero, Red, Black, High, Low, Even, Uneven
};
// As BetType is an enum we can use the corresponding number to get the corresponding string
static const char *BetTypeToStr[] = { "Zero", "Red", "Black", "High", "Low", "Even", "Uneven"};


#endif