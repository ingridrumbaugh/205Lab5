#include "walltoken.h"


/**
 * @brief WallToken Default constructor
 */
WallToken::WallToken(){
    active = true;
    locationX = -1;
    locationY = -1;;
    type = tokenType::Wall;
}

/**
 * @brief what_are_you Function that returns the type of the token
 * @return tokenType
 */
GameToken::tokenType WallToken::what_are_you(){
    return type;
}
