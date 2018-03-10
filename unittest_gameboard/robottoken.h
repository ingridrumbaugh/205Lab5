#ifndef ROBOTTOKEN_H
#define ROBOTTOKEN_H
//#include "gametoken.h"
//#include "trashtoken.h"
#include "../games/gametoken.h"
#include "../games/gameboardtemplate.h"

class RobotToken : public GameToken {
public:
    /**
     * @brief RobotToken Default constructor
     */
    RobotToken();

    /**
     * @brief what_are_you Function that returns the type
     * of the token
     * @return
     */
    tokenType what_are_you();
};

#endif // ROBOTTOKEN_H
