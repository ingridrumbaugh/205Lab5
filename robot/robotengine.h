#ifndef ROBOTENGINE_H
#define ROBOTENGINE_H

#include <iostream>
#include <random>
#include <vector>

#include "../games/gameengine.h"
#include "../games/gameboard.h"

#include "../games/gametoken.h"
#include "../games/playertoken.h"
#include "../games/robottoken.h"
#include "../games/trashtoken.h"
#include "../games/walltoken.h"

class RobotEngine : public GameEngine {

public:

    RobotEngine(); // create new gameboard, start_game, create_game_objects

    RobotEngine(int x, int y);

    GameToken* get_token(int x, int y);

    void next_level();

    void move_robots();

    void create_game_objects(); // calls get_rand_robot_pos, get_randomnum_robots,
    // above also creates instances of robots, player, and walls

    void quit(); // call gameboard constructor

    void teleport();

    /**
     * @brief move_north Methods for the player to move
     */
    // THIS IS ACTUALLY MOVE SOUTH
    void move_north(); // call check collision using tokens

    void move_northeast();

    void move_east();

    void move_southeast();

    // THIS IS ACTUALLY MOVE NORTH
    void move_south();

    void move_southwest();

    void move_west();

    void move_northwest();

    int get_random_pos(int pos); // called during teleport

    int get_randomnum_robots();

    int get_num_robots();

    int get_score();

    int get_num_moves();

    int get_player_x();

    int get_player_y();

    int get_robot_position_x(int i);

    int get_robot_position_y(int i);
protected:

    PlayerToken *p;
    RobotToken  r; // arraylist of random length
    TrashToken  t;
    WallToken   w;
    std::vector<RobotToken> rlist;
    std::vector<WallToken>  wlist;

    int rndPos;
    int rndNumRobots;
    int level;
    int rtn; // Respond to Neighbors
    // int rndRobotPos;

    int numMoves;
    int numRobots;
    int playerx;
    int playery;
    int score;

    int screenstartx;
    int screenstarty;
    int screenendx;
    int screenendy;

};

#endif // ROBOTENGINE_H
