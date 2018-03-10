#include "gametoken.h"

using namespace std;

/**
 * @brief GameToken::GameToken Default constructor for GameToken
 */
GameToken::GameToken()
{
    //active is initially set to false
    active = false;

    //x anf y are set to initial invalid value : -1
    locationX = -1;
    locationY = -1;
    type = Empty;

}

/**
 * @brief GameToken::set_position Method that sets the position of a Token
 *                   if it is active
 * @param X int x location
 * @param Y int y location
 */
void GameToken::set_position(int X, int Y){
    if(active){
        locationX = X;
        locationY = Y;
    }
    else
        std::cout<<"Token is inactive";
}

/**
 * @brief GameToken::what_are_you Method that returns the enum type of a
 *                  token
 * @return GameToken::enum
 */
GameToken::tokenType GameToken::what_are_you(){
    return type;
}

/**
 * @brief add_to_play Method to add a token to play
 * @param gameBoard GameBoard<Token> instance of gameboard
 * @param x int x location
 * @param y int y location
 */
bool GameToken::add_to_play(GameBoard<GameToken> &gameBoard, int x, int y){

    //GameToken ***tempBoard = gameBoard.get_pointer();
    bool result = false ;
    active = true;
    if (x >= 0 && y >= 0 && x <= gameBoard.get_num_rows() && y < gameBoard.get_num_cols() && gameBoard.get_token(x,y) == nullptr) {
        gameBoard.set_pointer(this, x ,y);
        bool val = (this == gameBoard.get_token(x,y));
        set_position(x,y);
        result = true;
    }
    return result;

}


/**
 * @brief remove_from_play Method to remove a token from play
 * @param gameBoard GameBoard<Token> instance of gameboard
 */
void GameToken::remove_from_play(GameBoard<GameToken> &gameBoard){
    //GameToken ***temp = gameBoard.get_pointer();
    gameBoard.set_pointer(nullptr,locationX,locationY);
   // temp[locationX][locationY] = nullptr;
    active = false;
    locationX = -1;
    locationY = -1;
    (*this).~GameToken();
}


/**
 * @brief get_location_x Return x position of token
 * @return int
 */
int GameToken::get_location_x(){
    return locationX;
}


/**
 * @brief get_location_y Return y position of token
 * @return int
 */
int GameToken::get_location_y(){
    return locationY;
}


/**
 * @brief get_state Return state of token
 * @return bool
 */
bool GameToken::get_state(){
    return active;
}
