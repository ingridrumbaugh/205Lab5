#ifndef WALLTOKEN_H
#define WALLTOKEN_H
#include "../games/gametoken.h"

class WallToken : public GameToken {
public:

    /**
     * @brief WallToken Default Constructor
     */
    WallToken();

    /**
     * @brief what_are_you Function taht returns the
     * type of the token
     * @return
     */
    tokenType what_are_you();
};

#endif // WALLTOKEN_H
