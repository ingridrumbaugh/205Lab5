#include "foodtoken.h"

/**
 * @brief FoodToken Default constructor
 */
FoodToken::FoodToken(){
    active = true;
    locationX = -1;
    locationY = -1;;
    type = tokenType::Food;
    value = 1;
}

/**
 * @brief FoodToken Constructor that takes in value of food
 * @param val int
 */
FoodToken::FoodToken(int val){
    active = true;
    locationX = -1;
    locationY = -1;;
    type = tokenType::Food;
    value = val;
}


/**
 * @brief what_are_you Function that returns the type of the token
 * @return tokenType
 */
GameToken::tokenType FoodToken::what_are_you(){
    return type;
}

/**
 * @brief get_value Returns the value of the food
 * @return int
 */
int FoodToken::get_value(){
    return value;
}
