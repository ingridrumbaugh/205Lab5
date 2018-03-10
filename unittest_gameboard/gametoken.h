#ifndef GAMETOKEN_H
#define GAMETOKEN_H
#define ROWS 5
#define COLS 5
//#include "../unittest_token/gameboardtemplate.h"
#include "../games/gameboardtemplate.h"

class GameToken {
public:
    /**
     * @brief GameToken Default constructor
     */
    GameToken();

    // Definition of the enumerator that is being used
    // to define token types
    enum tokenType {Player, Robot, Trash, Wall, Empty};

    /**
     * @brief set_type Define the type of the token
     * @param t
     */
    void set_type(int t);

    /**
     * @brief set_position Method to set the position of a piece
     * @param X
     * @param Y
     */
    void set_position(int X, int Y);

    /**
     * @brief what_are_you Method that returns what kind a piece is
     * @return
     */
    virtual tokenType what_are_you();

    /**
     * @brief add_to_play Method to add a token to play
     * @param gameBoard GameBoardTemplate<Token> instance of gameboard
     * @param x int x location
     * @param y int y location
     */
    void add_to_play(GameBoardTemplate<GameToken> &b, int x, int y);

    /**
     * @brief remove_from_play Method to remove a token from play
     * @param gameBoard GameBoardTemplate<Token> instance of gameboard
     */
    void remove_from_play(GameBoardTemplate<GameToken> gameBoard) ;

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

protected:
    // State of token
    bool active ;
    // Type of token
    tokenType type;

};

#endif // GAMETOKEN_H
