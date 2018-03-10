#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "../games/gameboard.h"
#include <curses.h>
#include "../games/gametoken.h"

class GameEngine {
public:

    /**
     * @brief GameEngine Default Constructor
     */
    GameEngine();

    GameEngine(int x, int y);


protected:

    GameBoard<GameToken> *gb;

};

#endif // GAMEENGINE_H
