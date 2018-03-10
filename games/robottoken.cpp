#include "robottoken.h"
#include "gametoken.h"

/**
 * @brief RobotToken Deafult constructor
 */
RobotToken::RobotToken(){
    active = true;
    locationX = -1;
    locationY = -1;
    type = tokenType::Robot;
}

/**
 * @brief respond_to_neighbours Function that controls the way Player
 *                              interacts with its neighbours
 * @param gb GameBoard<GameToken> gameboard
 * @param x1 int current position x
 * @param y1 int current position y
 * @param x2 int position to move to x
 * @param y2 int position to move to y
 *
 * if empty  -->  0
 * if trash  --> -1
 * if robot  --> -2
 * if player --> -3
 */
int RobotToken::respond_to_neighbours(GameBoard<GameToken> &gb, int x1, int y1, int x2, int y2){
    int result = -100;
  //  GameToken ***temp = gb.get_pointer();

    //If the place next to it is empty
    if(gb.get_token(x2, y2) == nullptr){
        gb.set_pointer(this, x2, y2);
        gb.set_pointer(nullptr, x1, y1);
        //temp[x1][y1] = nullptr;
        locationX = x2;
        locationY = y2;
        result = 0;
    }

    //If the place next to it is trash
    else if(gb.get_token(x2, y2)->what_are_you() == GameToken::Trash){
        gb.set_pointer(nullptr, x1, y1);
        this->remove_from_play(gb);
        result = -1;
    }

    //If the place next to it is a player
    else if(gb.get_token(x2, y2)->what_are_you() == GameToken::Player){
        gb.get_token(x2, y2)->remove_from_play(gb);
        gb.set_pointer(nullptr, x2, y2);
        gb.set_pointer(this, x2, y2);
        gb.set_pointer(nullptr, x1, y1);
//        temp[x2][y2]->remove_from_play(gb);
//        temp[x2][y2] = nullptr;
//        temp[x2][y2] = this;
        locationX = x2;
        locationY = y2;
        result = -3;
    }
    else if(gb.get_token(x2, y2)->what_are_you() == GameToken::Robot){
        gb.get_token(x2, y2)->remove_from_play(gb);
        TrashToken k;
        k.add_to_play(gb, x2, y2);
        gb.set_pointer(&k, x2, y2);
        //*temp[x2][y2] = k;
        this->remove_from_play(gb);
        result = -2;
    }
    return result;
}


/**
 * @brief what_are_you Function that returns the type of the token
 * @return tokenType
 */
GameToken::tokenType RobotToken::what_are_you(){
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
void RobotToken::move_east(GameBoard<GameToken> &gb){
    if(active){
        if( locationX+1 < gb.get_num_rows() ){
            respond_to_neighbours(gb, locationX, locationY, locationX+1, locationY);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }

}


/**
 * @brief move_west Function for the token to move west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_west(GameBoard<GameToken> &gb){

    if(active){
        if( locationX-1 >= 0 ){
            respond_to_neighbours(gb, locationX, locationY, locationX-1, locationY);
            std::cout<<"In move_west():"<<locationX<<":"<<locationY;
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}


/**
 * @brief move_north Function for the token to move north
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_north(GameBoard<GameToken> &gb){
    if(active){
        if( locationY+1 < gb.get_num_cols() ){
            respond_to_neighbours(gb, locationX, locationY, locationX, locationY+1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}


/**
 * @brief move_south Function for the token to move south
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_south(GameBoard<GameToken> &gb){

    if(active){
        if( locationY-1 >= 0 ){
            respond_to_neighbours(gb, locationX, locationY, locationX, locationY-1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}


/**
 * @brief move_north_east Function for the token to move north east
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_north_east(GameBoard<GameToken> &gb){
    if(active){
        if( locationX+1 < gb.get_num_rows() && locationY+1 < gb.get_num_cols()){
            respond_to_neighbours(gb, locationX, locationY, locationX+1, locationY+1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}


/**
 * @brief move_north_west Function for the token to move north west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_north_west(GameBoard<GameToken> &gb){
    if(active){
        if( locationX-1 >=0 && locationY+1 < gb.get_num_cols()){
            respond_to_neighbours(gb, locationX, locationY, locationX-1, locationY+1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}


/**
 * @brief move_south_east Function for the token to move south east
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_south_east(GameBoard<GameToken> &gb){
    if(active){
        if( locationX+1 < gb.get_num_rows() && locationY+1 >= 0){
            respond_to_neighbours(gb, locationX, locationY, locationX+1, locationY-1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}

/**
 * @brief move_south_west Function for the token to move south west
 * @param gb GameBoard<GameToken> instance of gameboard
 */
void RobotToken::move_south_west(GameBoard<GameToken> &gb){
    if(active){
        if( locationX-1 >= 0 && locationY-1 >= 0){
            respond_to_neighbours(gb, locationX, locationY, locationX-1, locationY-1);
        }
    }
    else{
        std::cout<<"The token is inactive";
    }
}
