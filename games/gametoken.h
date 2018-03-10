#ifndef GAMETOKEN_H
#define GAMETOKEN_H
#include "../tools/baseclass.h"
#include "gameboard.h"
//#include "robottoken.h"

/**
 * @brief The GameToken class Parent class for all different Token types
 *
 */
class GameToken : public BaseClass {
public:

    /**
     * @brief GameToken Default constructor
     */
    GameToken();

    //Definition of the enumerater that is being used to define token types
    enum tokenType {Player, Robot, Trash, Wall, Food, Empty};


    /**
     * @brief set_position Method to set the position of a piece
     * @param X int x position
     * @param Y int y position
     */
    void set_position(int X, int Y);


    /**
     * @brief what_are_you Method that returns what a kind a piece is
     * @return tokenType
     */
    virtual tokenType what_are_you();


    /**
     * @brief add_to_play Method to add a token to play
     * @param gameBoard GameBoard<Token> instance of gameboard
     * @param x int x location
     * @param y int y location
     * @return bool
     */
    bool add_to_play(GameBoard<GameToken> &gameBoard, int x, int y);

    /**
     * @brief remove_from_play Method to remove a token from play
     * @param gameBoard GameBoard<Token> instance of gameboard
     */
    void remove_from_play(GameBoard<GameToken> &gameBoard) ;

    /**
     * @brief get_location_x Return x position of token
     * @return int
     */
    int get_location_x();

    /**
     * @brief get_location_y Return y position of token
     * @return int
     */
    int get_location_y();

    /**
     * @brief get_state Return state of token
     * @return bool
     */
    bool get_state();


protected:

    //Variables for location of token
    int locationX ;
    int locationY ;

    //state of token
    bool active ;

    //type of token
    tokenType type;

};

#endif // GAMETOKEN_H
