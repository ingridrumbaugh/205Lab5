#include "trashtoken.h"

/**
 * @brief TrashToken Deafult constructor
 */
TrashToken::TrashToken(){
    active = false;
    locationX = -1;
    locationY = -1;
    type = tokenType::Trash;
}


/**
 * @brief what_are_you Function that returns the type of the token
 * @return tokenType
 */
GameToken::tokenType TrashToken::what_are_you(){
    return type;
}
