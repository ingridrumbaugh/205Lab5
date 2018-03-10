#ifndef WALLTOKEN_H
#define WALLTOKEN_H
#include "gametoken.h"


class WallToken : public GameToken
{
public:

    /**
     * @brief WallToken Default constructor
     */
    WallToken();

    /**
     * @brief what_are_you Function that returns the type of the token
     * @return tokenType
     */
    tokenType what_are_you();
};

#endif // WALLTOKEN_H
