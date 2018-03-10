#ifndef TRASHTOKEN_H
#define TRASHTOKEN_H
#include "gametoken.h"


class TrashToken : public GameToken
{
public:
    TrashToken();

    tokenType what_are_you();

};

#endif // TRASHTOKEN_H
