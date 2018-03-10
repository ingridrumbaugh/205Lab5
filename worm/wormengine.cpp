#include "wormengine.h"


/**
* @brief WormEngine Default constructor for the class
*/
WormEngine::WormEngine()
{
    //Intialising variables
    wormLength = 1;
    score =0;
    wallLength = 0;
    foodLocationX = -1;
    foodLocationY = -1;
    totalAddToWorm = 0;

    //Creating worm, food and wall
    create_worm(0,0);
    add_random_food();
    add_random_wall();

}

/**
 * @brief WormEngine Paramterised constructor for the class
 * @param x int number of rows
 * @param y int number of columns
 */
WormEngine::WormEngine(int x, int y) : GameEngine(x,y)
{

    //Initialisation of variables
    wormLength = 2;
    score = 0;
    wallLength = 0;
    foodLocationX = -1;
    foodLocationY = -1;
    totalAddToWorm = 0;


    //Creating worm, food and wall
    create_worm(0,0);
    add_random_food();
    add_random_wall();

}


/**
 * @brief create_worm Method that creates the initial worm with length
 *       2 at a given position
 * @param x int x position of starting worm
 * @param y int y position of starting worm
 */
void WormEngine::create_worm(int x, int y){

    int count = wormLength - 1;

    for(int i = 0; i < wormLength ; i++ ){

        //Creating and adding new token
        PlayerToken *p = new PlayerToken();
        p->add_to_play(*gb, count,  y);
        GameToken *g = gb->get_token(count, y);
        worm.push_back(*p);
        count -= 1;

    }

}



/**
 * @brief move Method that controls the movement of player token
 *             in various directions
 * @param direction int direction to move in
 * @return
 */
bool WormEngine::move(int direction){

    int lastX;
    int lastY;

    bool flag = false;

    //Getting head and setting last location
    PlayerToken *head = &worm.front();
    lastX = head->get_location_x();
    lastY = head->get_location_y();

    /**
     * Direction integer
     * direction == 0 -> move east
     * direction == 1 -> move west
     * direction == 2 -> move north
     * direction == 3 -> move south
     */
    if(direction == 0){

        /**
         * result = -100 -> Token is inactive
         * result = -1 -> Token is trying to move off board
         * result =  0 -> moving to empty location
         * result =  k -> eating food: where k is a natural number
         * result = -2 -> walked into robot
         */
        int result = head->move_east(*gb);
        if(result == -100 || result == -1 || result == -2){

            flag = false;
        }

        else if(result > 0){

            score += result;
            totalAddToWorm += result;

            flag = true;
            bool success = false;
            do{

                success = add_random_food();

            }while(!success);

            bool success2 = false;
            do{

                success2 = add_random_wall();

            }while(!success2);
        }

        else if(result == 0){

            flag = true;

        }


    }

    else if(direction == 1){

        /**
         * result = -100 -> Token is inactive
         * result = -1 -> Token is trying to move off board
         * result =  0 -> moving to empty location
         * result =  k -> eating food: where k is a natural number
         * result = -2 -> walked into robot
         */

        int result = head->move_west(*gb);
        if(result == -100 || result == -1 || result == -2){

            flag = false;
        }

        else if( result > 0){

            score += result;
            totalAddToWorm += result;

            flag = true;
            bool success = false;
            do{

                success = add_random_food();

            }while(!success);

            bool success2 = false;
            do{

                success2 = add_random_wall();

            }while(!success2);

        }
        else if(result == 0){
            flag = true;
        }

    }
    else if(direction == 2){
        /**
         * result = -100 -> Token is inactive
         * result = -1 -> Token is trying to move off board
         * result =  0 -> moving to empty location
         * result =  k -> eating food: where k is a natural number
         * result = -2 -> walked into robot
         */

        int result = head->move_south(*gb);
        //std::cerr<<"Result = "<< result << std::endl;
        if(result == -100 || result == -1 || result == -2){

            flag = false;
        }
        else if(result > 0){
            score += result;

            totalAddToWorm += result;
            //  wormLength += result;
            flag = true;
            bool success = false;
            do{
                success = add_random_food();
            }while(!success);

            bool success2 = false;
            do{
                success2 = add_random_wall();
            }while(!success2);
        }
        else if(result == 0){
            flag = true;
        }

    }
    else if(direction == 3){
        /**
         * result = -100 -> Token is inactive
         * result = -1 -> Token is trying to move off board
         * result =  0 -> moving to empty location
         * result =  k -> eating food: where k is a natural number
         * result = -2 -> walked into robot
         */

        int result = head->move_north(*gb);
        //  std::cerr<<"Result = "<< result << std::endl;
        if(result == -100 || result == -1 || result == -2){

            flag = false;
        }
        else if(result > 0){
            score += result;

            totalAddToWorm += result;
            // wormLength += result;
            flag = true;
            bool success = false;
            do{
                success = add_random_food();
            }while(!success);

            bool success2 = false;
            do{
                success2 = add_random_wall();
            }while(!success2);
        }
        else if(result == 0){
            flag = true;
        }

    }

    //For the rest of the worm
    if(flag){
        if(wormLength > 1){
            for(int i = 1; i < wormLength ; i++){

                PlayerToken *element = &worm.at(i);
                int diffX = (lastX - element->get_location_x());
                int diffY = (lastY - element->get_location_y());

                //Move east
                if(diffX > 0 && diffY == 0 ){
                    lastX = element->get_location_x();
                    lastY = element->get_location_y();
                    int result = element->move_east(*gb);
                    // std::cerr<<"Result = "<< result << std::endl;
                    if(result == -100 || result == -1 || result == -2){

                        flag = false;
                    }
                    else if(result > 0){

                        flag = true;
                        bool success = false;
                        do{
                            success = add_random_food();
                        }while(!success);

                        bool success2 = false;
                        do{
                            success2 = add_random_wall();
                        }while(!success2);
                    }
                    else if(result == 0){
                        flag = true;
                    }
                }

                //Move west
                else if(diffX < 0 && diffY == 0){

                    lastX = element->get_location_x();
                    lastY = element->get_location_y();

                    int result= element->move_west(*gb);
                    std::cerr<<"Result = "<< result << std::endl;
                    if(result == -100 || result == -1 || result == -2){

                        flag = false;
                    }
                    else if(result > 0){

                        flag = true;
                        bool success = false;
                        do{
                            success = add_random_food();
                        }while(!success);

                        bool success2 = false;
                        do{
                            success2 = add_random_wall();
                        }while(!success2);
                    }
                    else if(result == 0){
                        flag = true;
                    }

                }
                else if( diffX == 0 && diffY < 0){

                    lastX = element->get_location_x();
                    lastY = element->get_location_y();

                    int result= element->move_south(*gb);
                    std::cerr<<"Result = "<< result << std::endl;
                    if(result == -100 || result == -1 || result == -2){

                        flag = false;
                    }
                    else if(result >0){

                        flag = true;
                        bool success = false;
                        do{
                            success = add_random_food();
                        }while(!success);

                        bool success2 = false;
                        do{
                            success2 = add_random_wall();
                        }while(!success2);
                    }
                    else if(result == 0){
                        flag = true;
                    }
                }
                else if( diffX == 0 && diffY > 0){

                    lastX = element->get_location_x();
                    lastY = element->get_location_y();

                    int result= element->move_north(*gb);
                    // std::cerr<<"Result = "<< result << std::endl;
                    if(result == -100 || result == -1 || result == -2){

                        flag = false;
                    }
                    else if(result >0){
                        score += result;
                        //  wormLength += result;
                        flag = true;
                        bool success = false;
                        do{
                            success = add_random_food();
                        }while(!success);
                        bool success2 = false;
                        do{
                            success2 = add_random_wall();
                        }while(!success2);
                    }
                    else if(result == 0){
                        flag = true;
                    }
                }

            }
        }

    }

    if(totalAddToWorm > 0){
        add_to_worm(lastX, lastY);
    }
    return flag;
}

/**
 * @brief add_random_food Method that adds food at a random location
 *                       Returns  -> true when successful
 *                                   false when not
 * @return bool
 */
bool WormEngine::add_random_food(){

    //Generate random location and value
    int randomX = rand() % (gb->get_num_rows()-1) ;
    int randomY = rand() % (gb->get_num_cols()-1);
    int foodVal = rand( )% 10 +1;

    //Update food token
    food = new FoodToken(foodVal);
    bool success = false;
    success = food->add_to_play(*gb, randomX, randomY);
    return success;
}

/**
 * @brief add_random_wall Method that adds wall at a random location
 *                       Returns  -> true when successful
 *                                   false when not
 * @return bool
 */
bool WormEngine::add_random_wall(){

    //Generate random location
    int randomX = rand() % (gb->get_num_rows()-1)  ;
    int randomY = rand() % (gb->get_num_cols()-1)  ;

    //Add wall
    WallToken *w = new WallToken();
    bool success = false;
    success = w->add_to_play(*gb, randomX, randomY);
    walls.push_back(*w);
    wallLength ++;

    return success;
}


/**
 * @brief add_to_worm Add a new piece to the worm
 * @param x int x location
 * @param y int y location
 */
void WormEngine::add_to_worm(int x, int y){

    PlayerToken *p = new PlayerToken();
    p->add_to_play(*gb, x,  y);
    GameToken *g = gb->get_token(x, y);
    worm.push_back(*p);

    wormLength += 1;
    totalAddToWorm -= 1;
}
/**
 * @brief get_wall_length Returns the number of walls on the board
 * @return int
 */
int WormEngine::get_wall_length(){

    return wallLength;
}


/**
 * @brief get_wall_position_x Method to return x position of the
 *                             wall at the i-th position in the walls
 * @param i int position in the worm
 * @return int
 */
int WormEngine::get_wall_position_x(int i){

    WallToken p = walls.at(i);
    return (p.get_location_x());

}

/**
 * @brief get_wall_position_y Method to return y position of the
 *                             wall at the i-th position in the walls
 * @param i int position in the worm
 * @return int
 */
int WormEngine::get_wall_position_y(int i){

    WallToken p = walls.at(i);
    return (p.get_location_y());

}

/**
 * @brief get_food_location_x Returns the x location of the food
 *                           currently on the board
 * @return int
 */
int WormEngine::get_food_location_x(){

    return food->get_location_x();

}

/**
 * @brief get_food_location_y Returns the y location of the food
 *                           currently on the board
 * @return int
 */
int WormEngine::get_food_location_y(){

    return food->get_location_y();

}

/**
 * @brief get_food_value Returns the value of the food on the board
 * @return int
 */
int WormEngine::get_food_value(){
    return food->get_value();
}


/**
 * @brief get_token Returns pointer to a token at a certain location
 * @param x int x location
 * @param y int y location
 * @return
 */
GameToken* WormEngine::get_token(int x, int y){

    if(gb->get_token(x,y) !=nullptr){
        GameToken *g = gb->get_token(x, y);
        return g;
    }
    else
        return nullptr;

}

/**
 * @brief get_token_position_x Method to return x position of the
 *                             token at the i-th position in the worm
 * @param i int position in the worm
 * @return int
 */
int WormEngine::get_token_position_x(int i){

    PlayerToken p = worm.at(i);
    return (p.get_location_x());

}

/**
 * @brief get_token_position_y Method to return y position of the
 *                             token at the i-th position in the worm
 * @param i int position in the worm
 * @return int
 */
int WormEngine::get_token_position_y(int i){

    PlayerToken p = worm.at(i);
    return (p.get_location_y());

}

/**
 * @brief get_score Return score
 * @return int
 */
int WormEngine::get_score(){

    return score;
}


/**
 * @brief get_length Return length
 * @return int
 */
int WormEngine::get_length(){

    return wormLength;
}

