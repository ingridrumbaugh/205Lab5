#ifndef PLAYERTOKEN_H
#define PLAYERTOKEN_H
#include "gametoken.h"
//#include "../unittest_token/gameboard.h"
#include "foodtoken.h"
#include "gameboard.h"

class PlayerToken : public GameToken{
public:
    /**
     * @brief PlayerToken Default constructor
     */
    PlayerToken();

    /**
     * @brief respond_to_neighbours Function that controls the way Player
     *                              interacts with its neighbours
     * @param gb GameBoard<GameToken> gameboard
     * @param x1 int current position x
     * @param y1 int current position y
     * @param x2 int position to move to x
     * @param y2 int position to move to y
     * return int
     */
    int respond_to_neighbours(GameBoard<GameToken> &gb, int x1, int y1, int x2, int y2);

    /**
     * @brief what_are_you Function that returns the type of the token
     * @return tokenType
     */
    tokenType what_are_you();

    /** All the movements are with respect to the origin of a cartesian
     * plane. So, movement east is move right. Movement north is move up.
     * Movement north south is move up in x and down in y.
     */

    /**
     * @brief move_east Function for the token to move east
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_east(GameBoard<GameToken> &gb);


    /**
     * @brief move_west Function for the token to move west
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_west(GameBoard<GameToken> &gb);


    /**
     * @brief move_north Function for the token to move north
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_north(GameBoard<GameToken> &gb);


    /**
     * @brief move_south Function for the token to move south
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_south(GameBoard<GameToken> &gb);


    /**
     * @brief move_north_east Function for the token to move north east
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_north_east(GameBoard<GameToken> &gb);


    /**
     * @brief move_north_west Function for the token to move north west
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_north_west(GameBoard<GameToken> &gb);


    /**
     * @brief move_south_east Function for the token to move south east
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_south_east(GameBoard<GameToken> &gb);


    /**
     * @brief move_south_west Function for the token to move south west
     * @param gb GameBoard<GameToken> instance of gameboard
     */
    int move_south_west(GameBoard<GameToken> &gb);
};

#endif // PLAYERTOKEN_H
