#ifndef FOODTOKEN_H
#define FOODTOKEN_H
#include "gametoken.h"


class FoodToken : public GameToken
{
public:

    /**
     * @brief FoodToken Default constructor, sets val to 1
     */
    FoodToken();


    /**
     * @brief FoodToken Constructor that takes in value of food
     * @param val int
     */
    FoodToken(int val);

    /**
     * @brief get_value Returns the value of the food
     * @return int
     */
    int get_value();

    /**
     * @brief what_are_you Returns the type
     * @return GameToken::tokenType
     */
    tokenType what_are_you();

    int value;
};

#endif // FOODTOKEN_H
