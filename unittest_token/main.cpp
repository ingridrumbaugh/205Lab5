#include <iostream>
#include <string>

using namespace std;
#include "gtest/gtest.h"
#include "../games/gametoken.h"
#include "../games/playertoken.h"
#include "../games/robottoken.h"
#include "../games/trashtoken.h"
#include "../games/walltoken.h"

#include "../games/gameboard.h"

#define ROWS 5
#define COLS 5

using namespace std;

///**
// * @brief The GameBoard class Mock gameboard class
// */
//class GameBoard{

//public:

//    //Creating the board
//    GameBoard<GameToken> board;

//    /**
//     * @brief GameBoard Default constructor for the gameboard
//     */
//    GameBoard();

//    /**
//     * @brief get_template Returns the board
//     * @return
//     */
//    GameBoard<GameToken> get_template();



//};

///**
// * @brief get_template Returns the board
// * @return
// */
//GameBoard<GameToken> GameBoard::get_template() {
//    return board;
//}

/**
 * @brief TEST Test that the token is correctly added to the board
 */
TEST(TokensState, TESTSTATEACTIVE){
    GameBoard<GameToken> board;
    GameToken g;
    //GameToken ***temp = board.get_pointer();
    g.add_to_play(board, 2, 4);
    //ASSERT_EQ(temp[2][4], &g);
    ASSERT_EQ(board.get_token(2,4), &g);

}

/**
 * @brief TEST Test that the token is correctly removes
 *        from the board
 */
TEST(TokensState, TESTSTATEINACTIVE){
    GameBoard<GameToken> board;
    GameToken g;
    //GameToken ***temp = board.get_pointer();
    g.add_to_play(board, 2, 4);
    std::cerr<<"added to play";
    g.remove_from_play(board);
    ASSERT_EQ(board.get_token(2,4),nullptr);

}

/**
 * @brief TEST Test that the correct number is returned for Player
 */
TEST(TokenKind, TESTPLAYER){
    PlayerToken p;
    int val = p.what_are_you();
    ASSERT_EQ(val, 0);
}


/**
 * @brief TEST Test that the correct number is returned for Robot
 */
TEST(TokenKind, TESTROBOT){
    RobotToken p;
    int val = p.what_are_you();
    ASSERT_EQ(val, 1);
}


/**
 * @brief TEST Test that the correct number is returned for Trash
 */
TEST(TokenKind, TESTTRASH){
    TrashToken p;
    int val = p.what_are_you();
    ASSERT_EQ(val, 2);
}

/**
 * @brief TEST Test that the correct number is returned for Wall
 */
TEST(TokenKind, TESTWALL){
    WallToken p;
    int val = p.what_are_you();
    ASSERT_EQ(val, 3);
}

/**
 * @brief TEST Testing that the location is being set correctly
 */
TEST(TokenLocation, TESTLOCATION){
    GameToken g;
    GameBoard<GameToken>gb;

    g.add_to_play(gb,2,3);

    std::string exp = "2,3";

    std::string result;
    result = std::to_string(g.get_location_x());
    result =  result + ",";
    result = result + std::to_string(g.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Testing that when a Player runs into a Robot, the
 *             Player is removed from play
 */
TEST(TokenResponse, TESTPLAYERROBOT){

    GameBoard<GameToken> gb;

    PlayerToken p;
    RobotToken r;
    p.add_to_play(gb,2,3);

    int x = p.get_location_x() + 1;
    int y = p.get_location_y();

    r.add_to_play(gb,x,y);
    p.move_east(gb);

    //GameToken ***temp =gb.get_pointer();

    ASSERT_EQ(static_cast<int>(gb.get_token(x,y)->what_are_you()),1);
    ASSERT_EQ(gb.get_token(2,3),nullptr );

}

/**
 * @brief TEST Testing that when a Player cannot over trash
 */
TEST(TokenResponse, TESEPLAYERTRASH){

    GameBoard<GameToken> gb;
    PlayerToken p;
    TrashToken t;
    p.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = p.get_location_x() + 1;
    int y = p.get_location_y();

    t.add_to_play(gb,x,y);
    p.move_east(gb);
    //GameToken ***temp =gb.get_pointer();

//    ASSERT_EQ(static_cast<int>(temp[x][y]->what_are_you()),2);
//    ASSERT_EQ(static_cast<int>(temp[2][3]->what_are_you()),0);
    ASSERT_EQ(static_cast<int>(gb.get_token(x,y)->what_are_you()),2);
    ASSERT_EQ(static_cast<int>(gb.get_token(2,3)->what_are_you()),0);

}

/**
 * @brief TEST Testing that when a Player cannot over wall
 */
TEST(TokenResponse, TESEPLAYERWALL){

    GameBoard<GameToken> gb;

    PlayerToken p;
    WallToken w;
    p.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = p.get_location_x() + 1;
    int y = p.get_location_y();

    w.add_to_play(gb,x,y);
    p.move_east(gb);
    //GameToken ***temp =gb.get_pointer();
    ASSERT_EQ(static_cast<int>(gb.get_token(x,y)->what_are_you()),3);
    ASSERT_EQ(static_cast<int>(gb.get_token(2,3)->what_are_you()),0);

}

/**
 * @brief TEST Robot can move into empty location
 */
TEST(TokenResponse, TESEROBOTMOVE){


    RobotToken r;
    GameBoard<GameToken> gb;

    r.add_to_play(gb,2,3);

    r.move_east(gb);
    //GameToken ***temp =gb.get_pointer();

    ASSERT_EQ(static_cast<int>(gb.get_token(3,3)->what_are_you()),1);
    ASSERT_EQ(gb.get_token(2,3), nullptr);

}

/**
 * @brief TEST If a robot moves into a player, the player is removed
 */
TEST(TokenResponse, TESEROBOTPLAYER){


    RobotToken r;
    PlayerToken p;


    GameBoard<GameToken> gb;

    r.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r.get_location_x() + 1;
    int y = r.get_location_y();

    p.add_to_play(gb,x,y);
    r.move_east(gb);

    //GameToken ***temp =gb.get_pointer();
    ASSERT_EQ(static_cast<int>(gb.get_token(x,y)->what_are_you()),1);
    ASSERT_EQ(gb.get_token(2,3), nullptr);


}

/**
 * @brief TEST If a robot runs into trash, it must be removed
 */
TEST(TokenResponse, TESEROBOTTRASH){


    RobotToken r;
    TrashToken t;
    GameBoard<GameToken> gb;

    r.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r.get_location_x() + 1;
    int y = r.get_location_y();

    t.add_to_play(gb,x,y);
    r.move_east(gb);

    //GameToken ***temp =gb.get_pointer();
    ASSERT_EQ(gb.get_token(2,3), nullptr);
    ASSERT_EQ(gb.get_token(x,y), &t);

}

/**
 * @brief TEST When robot runs into trash, its state must be reset
 *             inactive
 */
TEST(TokenResponse, TESEROBOTTRASHSTATE){

    RobotToken r;
    TrashToken t;
    GameBoard<GameToken> gb;

    r.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r.get_location_x() + 1;
    int y = r.get_location_y();

    t.add_to_play(gb,x,y);
    r.move_east(gb);


    ASSERT_FALSE(r.get_state());

}


/**
 * @brief TEST When two robots collide they make trash
 */
TEST(TokenResponse, TESEROBOTROBOT){

    RobotToken r1;
    RobotToken r2;

    GameBoard<GameToken> gb;

    r1.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r1.get_location_x() + 1;
    int y = r1.get_location_y();

    r2.add_to_play(gb,x,y);
    r1.move_east(gb);

    //GameToken ***temp =gb.get_pointer();
    ASSERT_EQ(static_cast<int>(gb.get_token(x,y)->what_are_you()),2);

}

/**
 * @brief TEST When robot runs into another robot, its state must be reset
 *             inactive
 */
TEST(TokenResponse, TESEROBOTROBOTSTATE1){

    RobotToken r1;
    RobotToken r2;

    GameBoard<GameToken> gb;

    r1.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r1.get_location_x() + 1;
    int y = r1.get_location_y();

    r2.add_to_play(gb,x,y);
    r1.move_east(gb);


    ASSERT_FALSE(r1.get_state());


}

/**
 * @brief TEST When robot runs into another robot, the other robots state
 *             must be reset inactive
 */
TEST(TokenResponse, TESEROBOTROBOTSTATE2){

    RobotToken r1;
    RobotToken r2;

    GameBoard<GameToken> gb;

    r1.add_to_play(gb,2,3);

    //Getting position to one step east
    int x = r1.get_location_x() + 1;
    int y = r1.get_location_y();

    r2.add_to_play(gb,x,y);
    r1.move_east(gb);


    ASSERT_FALSE(r2.get_state());


}

/**
 * @brief TEST Test that player can move East
 */
TEST(TestMovementPlayer, TESTMOVEEAST){

    PlayerToken p;
    GameBoard<GameToken> gb;
    std::cerr<<"Adding to play";
    p.add_to_play(gb,2,3);

    std::cerr<<"Move east";
    p.move_east(gb);

    std::cerr << "after move east \n";
    std::string exp = "3,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
    ASSERT_EQ(gb.get_token(2,3), nullptr);
    ASSERT_EQ(gb.get_token(3,3), &p);

}


/**
 * @brief TEST Test that player can move West
 */
TEST(TestMovementPlayer, TESTMOVEWEST){

    PlayerToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);

    p.move_west(gb);

    std::string exp = "1,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move North
 */
TEST(TestMovementPlayer, TESTMOVENORTH){

    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,2);
    p.move_north(gb);

    std::string exp = "2,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move South
 */
TEST(TestMovementPlayer, TESTMOVESOUTH){

    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);
    p.move_south(gb);

    std::string exp = "2,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}


/**
 * @brief TEST Test that player can move North East
 */
TEST(TestMovementPlayer, TESTMOVENORTHEAST){
    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,1,2);;
    p.move_north_east(gb);

    std::string exp = "2,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move North West
 */
TEST(TestMovementPlayer, TESTMOVENORTHWEST){
    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,2);
    p.move_north_west(gb);

    std::string exp = "1,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move South East
 */
TEST(TestMovementPlayer, TESTMOVESOUTHEAST){

    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);
    p.move_south_east(gb);

    std::string exp = "3,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}


/**
 * @brief TEST Test that player can move South West
 */
TEST(TestMovementPlayer, TESTMOVESOUTHWEST){

    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);
    p.move_south_west(gb);

    std::string exp = "1,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Cannot move an inactive piece
 */
TEST(TestMovementPlayer, TESTINACTIVEPIECE){
    PlayerToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);

    p.remove_from_play(gb);
    //GameToken ***temp = gb.get_pointer();

    ASSERT_EQ(gb.get_token(2,3), nullptr);

}

/**
 * @brief TEST Token cannot move off baord in the West
 */
TEST(TestMovementPlayer, TESTMOVEOFFBOARDWEST){
    PlayerToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,1);

    p.move_west(gb);

    std::string exp = "0,1";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


/**
 * @brief TEST Token cannot move off baord in the East
 */
TEST(TestMovementPlayer, TESTMOVEOFFBOARDEAST){
    PlayerToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,4,0);
    p.move_east(gb);

    std::string exp = "4,0";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


/**
 * @brief TEST Token cannot move off baord in the North
 */
TEST(TestMovementPlayer, TESTMOVEOFFBOARDNORTH){
    PlayerToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,4);
    p.move_north(gb);

    std::string exp = "0,4";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


/**
 * @brief TEST Token cannot move off baord in the South
 */
TEST(TestMovementPlayer, TESTMOVEOFFBOARDSOUTH){
    PlayerToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,0);
    p.move_south(gb);

    std::string exp = "0,0";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


//**************//


/**
 * @brief TEST Test that Robot can move East
 */
TEST(TokenMovementRobot, TESTMOVEEAST){

    RobotToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);
    p.move_east(gb);

    std::string exp = "3,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move West
 */
TEST(TokenMovementRobot, TESTMOVEWEST){

    RobotToken p;
    GameBoard<GameToken> gb;

    p.add_to_play(gb,2,3);
    p.move_west(gb);

    std::string exp = "1,3";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move North
 */
TEST(TokenMovementRobot, TESTMOVENORTH){
    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);
    p.move_north(gb);
    std::string exp = "2,4";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move South
 */
TEST(TokenMovementRobot, TESTMOVESOUTH){
    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);
    p.move_south(gb);
    std::string exp = "2,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move North East
 */
TEST(TokenMovementRobot, TESTMOVENORTHEAST){
    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);;
    p.move_north_east(gb);
    std::string exp = "3,4";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}


/**
 * @brief TEST Test that player can move North West
 */
TEST(TokenMovementRobot, TESTMOVENORTHWEST){
    RobotToken p;

    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);
    p.move_north_west(gb);
    std::string exp = "1,4";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move South East
 */
TEST(TokenMovementRobot, TESTMOVESOUTHEAST){
    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);
    p.move_south_east(gb);
    std::string exp = "3,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Test that player can move South West
 */
TEST(TokenMovementRobot, TESTMOVESOUTHWEST){

    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);
    p.move_south_west(gb);
    std::string exp = "1,2";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);

}

/**
 * @brief TEST Cannot move inactive Robot
 */
TEST(TokenMovementRobot, TESTINACTIVEPIECE){

    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,2,3);

    p.remove_from_play(gb);
    //GameToken ***temp = gb.get_pointer();

    ASSERT_EQ(gb.get_token(2,3), nullptr);

}

/**
 * @brief TEST Token cannot move off baord in the West
 */
TEST(TokenMovementRobot, TESTMOVEOFFBOARDWEST){

    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,1);

    p.move_west(gb);

    std::string exp = "0,1";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}

/**
 * @brief TEST Token cannot move off baord in the East
 */
TEST(TokenMovementRobot, TESTMOVEOFFBOARDEAST){

    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,4,0);
    p.move_east(gb);

    std::string exp = "4,0";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


/**
 * @brief TEST Token cannot move off baord in the North
 */
TEST(TokenMovementRobot, TESTMOVEOFFBOARDNORTH){
    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,4);
    p.move_north(gb);

    std::string exp = "0,4";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}

/**
 * @brief TEST Token cannot move off baord in the South
 */
TEST(TokenMovementRobot, TESTMOVEOFFBOARDSOUTH){

    RobotToken p;
    GameBoard<GameToken> gb;
    p.add_to_play(gb,0,0);
    p.move_south(gb);

    std::string exp = "0,0";

    std::string result;
    result = std::to_string(p.get_location_x());
    result = result + ",";
    result = result + std::to_string(p.get_location_y());

    ASSERT_EQ(exp, result);
}


int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

