#ifndef PLAYERTOKEN_H
#define PLAYERTOKEN_H
#include "../games/gametoken.h"
//#include "../games/gameboardtemplate.h"

class PlayerToken : public GameToken{
public:
    /**
     * @brief PlayerToken Default constructor
     */
    PlayerToken();

    /**
     * @brief what_are_you Function that returns the
     * type of the token
     * @return
     */
    tokenType what_are_you();
};

#endif // PLAYERTOKEN_H
