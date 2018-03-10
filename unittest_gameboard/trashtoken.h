#ifndef TRASHTOKEN_H
#define TRASHTOKEN_H
#include "../games/gametoken.h"

class TrashToken : public GameToken {
public:

    /**
     * @brief TrashToken Default constructor
     */
    TrashToken();

    /**
     * @brief what_are_you Function that returns the
     * type of the token
     * @return
     */
    tokenType what_are_you();
};

#endif // TRASHTOKEN_H
