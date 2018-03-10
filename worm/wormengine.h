#ifndef WORMENGINE_H
#define WORMENGINE_H

#include <vector>
#include <stdlib.h>

#include "../games/gameengine.h"
#include "../games/playertoken.h"
#include "../games/gametoken.h"
#include "../games/gameboard.h"
#include "../games/foodtoken.h"
#include "../games/walltoken.h"

/**
 * @brief The WormEngine class that controls the worm game
 */
class WormEngine :public GameEngine {
public:

    /**
    * @brief WormEngine Default constructor for the class
    */
    WormEngine();

    /**
    * @brief WormEngine Paramterised constructor for the class
    * @param x int number of rows
    * @param y int number of columns
    */
    WormEngine(int x, int y);

    /**
    * @brief create_worm Method that creates the initial worm with length
    *       2 at a given position
    * @param x int x position of starting worm
    * @param y int y position of starting worm
    */
    void create_worm(int x, int y);

    /**
    * @brief move Method that controls the movement of player token
    *             in various directions
    * @param direction int direction to move in
    * @return
    */

    bool move(int direction);

    /**
    * @brief get_token Returns pointer to a token at a certain location
    * @param x int x location
    * @param y int y location
    * @return
    */
    GameToken* get_token(int x, int y);

    /**
    * @brief get_score Return score
    * @return int
    */
    int get_score();


    /**
    * @brief get_length Return length
    * @return int
    */
    int get_length();

    /**
    * @brief get_token_position_x Method to return x position of the
    *                             token at the i-th position in the worm
    * @param i int position in the worm
    * @return int
    */
    int get_token_position_x(int i);

    /**
    * @brief get_token_position_y Method to return y position of the
    *                             token at the i-th position in the worm
    * @param i int position in the worm
    * @return int
    */
    int get_token_position_y(int i);


    /**
    * @brief get_wall_position_x Method to return x position of the
    *                             wall at the i-th position in the walls
    * @param i int position in the worm
    * @return int
    */
    int get_wall_position_x(int i);

    /**
    * @brief get_wall_position_y Method to return y position of the
    *                             wall at the i-th position in the walls
    * @param i int position in the worm
    * @return int
    */
    int get_wall_position_y(int i);



    /**
    * @brief get_wall_length Returns the number of walls on the board
    * @return int
    */
    int get_wall_length();

    /**
    * @brief get_food_location_x Returns the x location of the food
    *                           currently on the board
    * @return int
    */
    int get_food_location_x();

    /**
    * @brief get_food_location_y Returns the y location of the food
    *                           currently on the board
    * @return int
    */
    int get_food_location_y();

    /**
    * @brief get_food_value Returns the value of the food on the board
    * @return int
    */
    int get_food_value();



private:

    /**
    * @brief add_random_food Method that adds food at a random location
    *                       Returns  -> true when successful
    *                                   false when not
    * @return bool
    */
    bool add_random_food();

    /**
    * @brief add_random_wall Method that adds wall at a random location
    *                       Returns  -> true when successful
    *                                   false when not
    * @return bool
    */
    bool add_random_wall();

    /**
    * @brief add_to_worm Add a new piece to the worm
    * @param x int x location
    * @param y int y location
    */
    void add_to_worm(int x, int y);

    /**
    * @brief worm Vector of PlayerToken for the worm
    */
    vector<PlayerToken> worm;

    /**
    * @brief food Current food on the board
    */
    FoodToken *food;

    /**
    * @brief walls Vector of WallToken
    */
    vector<WallToken> walls;

    /**
    * @brief wormLength length of the worm
    */
    int wormLength;

    /**
    * @brief wallLength number of walls on the board
    */
    int wallLength;

    /**
    * @brief score Current score
    */
    int score;

    /**
    * @brief foodLocationX x location of current food
    */
    int foodLocationX ;
    /**
    * @brief foodLocationY y location of current food
    */
    int foodLocationY;

    /**
    * @brief totalAddToWorm number of tokens to add to the worm
    */
    int totalAddToWorm;




};

#endif // WORMENGINE_H
