#include "gameengine.h"

GameEngine::GameEngine() {
    gb  = new GameBoard<GameToken>();

}


GameEngine::GameEngine(int x, int y) {
//    GameBoard<GameToken> temp(x,y);
//    gb = temp;
    gb = new GameBoard<GameToken>(x,y);

}

