#include "playertoken.h"
#include "gametoken.h"

using namespace std;


/**
 * @brief PlayerToken Default constructor
 */
PlayerToken::PlayerToken(){
 //   active = true;
//    locationX = -1;
//    locationY = -1;
    type = tokenType::Player;
}


/**
 * @brief respond_to_neighbours Function that controls the way Player
 *                              interacts with its neighbours
 * @param gb GameBoard<GameToken> gameboard
 * @param x1 int current position x
 * @param y1 int current position y
 * @param x2 int position to move to x
 * @param y2 int position to move to y
 */
int PlayerToken::respond_to_neighbours(GameBoard<GameToken> &gb, int x1, int y1, int x2, int y2){

    /**
     * result = 0 -> moving to empty space
     * result = k -> eating food where k is a natural number
     * result = -1 -> wall or trash
     * result = -2 -> robot
     */
    int result = -100;

   // std::cerr << "In respond to neighbours" << std::endl;


    //Player can only move if the next spot is empty
    if(gb.get_token(x2,y2) == nullptr){
        gb.set_pointer(this, x2, y2);
        gb.set_pointer(nullptr , x1, y1);
        locationX = x2;
        locationY = y2;
        result = 0;
     //   std::cerr << "Result:"<< result;
    }

    //If the next spot is food
   else if(gb.get_token(x2,y2)->what_are_you() == GameToken::Food){

        if(gb.get_token(x2,y2) != nullptr){

            FoodToken *f = (FoodToken *)gb.get_token(x2,y2) ;
            result = f->value;
            f->remove_from_play(gb);
            gb.set_pointer(this, x2, y2);
            gb.set_pointer(nullptr, x1, y1);
            locationX = x2;
            locationY = y2;

        }
    }

    //The next spot is robot
    else if(static_cast<int>(gb.get_token(x2, y2)->what_are_you()) == 1){
        gb.set_pointer(nullptr, x1, y1);
        this->remove_from_play(gb);
        result = -2;

    }

    //Something but an empty space, food, null or robot
    else{
        result = -1;
    }
    return result;
}


/**
 * @brief what_are_you Function that returns the type of the token
 * @return tokenType
 */
GameToken::tokenType PlayerToken::what_are_you(){
    return type;
}


/** All the movements are with respect to the origin of a cartesian
 * plane. So, movement east is move right. Movement north is move up.
 * Movement north south is move up in x and down in y.
 */


/**
 * @brief move_east Function for the token to move east
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_east(GameBoard<GameToken> &gb){

    /**
     * result = -100 -> Token is inactive
     * result = -1 -> Token is trying to move off board
     * result =  0 -> moving to empty location
     * result =  k -> eating food: where k is a natural number
     * result = -2 -> walked into robot
     */
    int result = -100;

    if(active){

        if( locationX+1 < gb.get_num_rows()-1){


            result = respond_to_neighbours(gb, locationX, locationY,
                                           locationX+1, locationY);
            return result;
        }
        else{
            result = -1;
            return result;
        }
    }
    else{

        std::cout<<"The token is inactive";
        return result;
    }
    return result;
}


/**
 * @brief move_west Function for the token to move west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_west(GameBoard<GameToken> &gb){
    int result = -100;
    if(active){

        if( locationX-1 >= 0 ){

            result = respond_to_neighbours(gb, locationX, locationY,
                                           locationX-1, locationY);
        }
        else
            result = -1;
    }
    else{
        std::cout<<"The token is inactive";

    }
    return result;

}


/**
 * @brief move_north Function for the token to move north
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_north(GameBoard<GameToken> &gb){
    int result = -100;
    if(active){

        if( locationY+1 < gb.get_num_cols()-1){

            result = respond_to_neighbours(gb, locationX, locationY,
                                           locationX, locationY+1);
        }
        else{
            result = -1;
        }
    }
    else{

        std::cout<<"The token is inactive";
    }

    return result;

}


/**
 * @brief move_south Function for the token to move south
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_south(GameBoard<GameToken> &gb){
    int result = -100;

    if(active){

        if( locationY-1 >= 0 ){

            result = respond_to_neighbours(gb, locationX, locationY,
                                           locationX, locationY-1);
        }
        else
            result = -1;
    }
    else{

        std::cout<<"The token is inactive";
    }
    return result;

}

/**
 * @brief move_north_east Function for the token to move north east
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_north_east(GameBoard<GameToken> &gb){
    int result = -100;

    if(active){

        if( locationX+1 < gb.get_num_rows()-1 &&

                locationY+1 < gb.get_num_cols()-1){

            result =respond_to_neighbours(gb, locationX, locationY,
                                          locationX+1, locationY+1);
        }
        else
            result = -1;
    }
    else{

        std::cout<<"The token is inactive";
    }
    return result;
}


/**
 * @brief move_north_west Function for the token to move north west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_north_west(GameBoard<GameToken> &gb){
    int result = -100;

    if(active){

        if( locationX-1 >=0 && locationY+1 < gb.get_num_cols()-1){

            result = respond_to_neighbours(gb, locationX, locationY,
                                           locationX-1, locationY+1);
        }
        else
            result = -1;
    }
    else{

        std::cout<<"The token is inactive";
    }
    return result;
}


/**
 * @brief move_south_east Function for the token to move south east
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_south_east(GameBoard<GameToken> &gb){

    int result = -100;

    if(active){

        if( locationX+1 < gb.get_num_rows()-1 && locationY+1 >= 0){

           result = respond_to_neighbours(gb, locationX, locationY,
                                  locationX+1, locationY-1);
        }
        else
            result = -1;
    }
    else{

        std::cout<<"The token is inactive";
    }
    return result;
}


/**
 * @brief move_south_west Function for the token to move south west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
int PlayerToken::move_south_west(GameBoard<GameToken> &gb){
    int result = -100;
    if(active){

        if( locationX-1 >= 0 && locationY-1 >= 0){

            result = respond_to_neighbours(gb, locationX, locationY,
                                  locationX-1, locationY-1);
        }
        else
            result = -1;
    }
    else{

        std::cout<<"The token is inactive";
    }
    return result;
}
