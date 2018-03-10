#include "robotengine.h"

/**
 * @brief RobotEngine::RobotEngine
 * Need to create a player,
 * a random number of robots along with
 * random positions -- this is done in
 * create_game_objects
 */
RobotEngine::RobotEngine() {
  //  PlayerToken p;
    p = new PlayerToken();
    screenstartx = 0;
    screenstarty = 0;
    screenendx   = 23;
    screenendy   = 65;
    level = 1;
    create_game_objects();

}

RobotEngine::RobotEngine(int x, int y) : GameEngine(x,y) {
  //  PlayerToken p;
    p = new PlayerToken();
    screenstartx = 0;
    screenstarty = 0;
    screenendx   = x;
    screenendy   = y;
    level = 1;
    create_game_objects();

}


GameToken* RobotEngine::get_token(int x, int y){
    if(gb->get_token(x,y) !=nullptr){
        GameToken *g = gb->get_token(x, y);
        return g;
    }
    else
        return nullptr;
}

/**
 * @brief RobotEngine::next_level
 * Restart game
 * call start_game to recreate game objects
 * Increment level number
 */
void RobotEngine::next_level() {
    level++;
    create_game_objects();
}

void RobotEngine::teleport() {
    int newx = get_random_pos(0);
    int newy = get_random_pos(1);
    p->respond_to_neighbours(*gb, p->get_location_x(), p->get_location_y(), newx, newy);
    // p.set_position(newx, newy);
}

/**
 * @brief RobotEngine::quit
 * Quits the game
 */
void RobotEngine::quit() {
    for (int i = 0; i < numRobots; i++) {
        r.remove_from_play(*gb);
    }
    p->remove_from_play(*gb);

    numRobots = 0;
    numMoves  = 0;
}

/**
 * @brief RobotEngine::create_game_objects
 * Adds player token at a random position
 * Generates randomnum of robots in an array
 * and places those at random positions on the board
 *
 * Randomnum of robots depends on the level
 *
 * also creates walls
 */
void RobotEngine::create_game_objects() {
    // Create an array of robots!
    int temp = get_randomnum_robots();
    if (level > 0) {
        temp = temp*level;
    }
    int rndposx;
    int rndposy;
   // RobotToken r;
    for (int i = 0; i < temp; i++) {
        //rlist[i] = r;
        RobotToken *r =  new RobotToken();

        rndposx = get_random_pos(0);
        rndposy = get_random_pos(1);

        r->add_to_play(*gb, rndposx, rndposy);
        r->set_position(rndposx, rndposy);
        rlist.push_back(*r);
    }

    rndposx = get_random_pos(0);
    rndposy = get_random_pos(1);
    p->add_to_play(*gb, rndposx, rndposy);

   // WallToken w;
    // Add Top wall
    for (int j = 0; j < screenendx; j ++) {
        WallToken *w = new WallToken();
         w->add_to_play(*gb, j, screenstarty);
        wlist.push_back(*w);
    }
    // Add Bottom Wall
    for (int k = 0; k < screenendx; k ++) {
        WallToken *w = new WallToken();

        w->add_to_play(*gb, k, screenendy-1);
         wlist.push_back(*w);
    }
    // Add Left Wall
    for (int l = 0; l < screenendy; l++) {
        WallToken *w = new WallToken();
         w->add_to_play(*gb, screenstartx, l);
        wlist.push_back(*w);

    }
    // Add Right Wall
    for (int m = 0; m < screenendy; m++) {
     WallToken *w = new WallToken();

        w->add_to_play(*gb, screenendx-1, m);
         wlist.push_back(*w);
    }
}

/**
 * @brief RobotEngine::get_random_pos
 * @param pos: 0 --> x position, 1 --> y position
 * @return random x or y position
 *
 */
int RobotEngine::get_random_pos(int pos) {
    // X COORDINATE
    // Rand between 0 and 500
    if (pos == 0) {
        rndPos = screenstartx + (std::rand() % (screenendx-screenstartx-1));
        return rndPos;
        // Y COORDINATE
        // Rand between 0 and 300
    } else if (pos == 1) {
        rndPos = screenstarty + (std::rand() % (screenendy-screenstarty-1));
        return rndPos;
    } else {
        return 0;
    }
}

/**
 * @brief RobotEngine::get_randomnum_robots
 * @return random num of robots between 10 and 25
 */
int RobotEngine::get_randomnum_robots() {
    // Random number of robots will be between 10 and 25
    rndNumRobots = 10 + (std::rand() % (25 - 10 + 1));
    numRobots = rndNumRobots;
    return rndNumRobots;
}

/**
 * @brief RobotEngine::move_robots
 * Move robots closer to the player
 */
void RobotEngine::move_robots() {
    int playerposx = p->get_location_x();
    int playerposy = p->get_location_y();

    for (int i = 0; i < numRobots; i ++) {
        int startx = screenstartx + playerposx/2 + 2*i;
        int endx   = screenendx   - playerposx/2 + 2*i;
        int starty = screenstarty + playerposy/2 + 2*i;
        int endy   = screenendy   - playerposy/2 + 2*i;

        int rndx = startx + (std::rand() % (endx - startx - 2));
        int rndy = starty + (std::rand() % (endy - starty - 2));

        int currentx = rlist.at(i).get_location_x();
        int currenty = rlist.at(i).get_location_y();
        int response;
        RobotToken *robo = &rlist.at(i);
       // response = robo->respond_to_neighbours(*gb, currentx, currenty, rndx, rndy);
        response = robo->respond_to_neighbours(*gb, currentx, currenty, rndx, rndy);
        // If robot hits a player, game is over
//        if (response == -3) {
//            quit();
//            // If robot hits another robot, then create trash and inc score
//        } else if (response == -2) {
//            score += 20;
//            TrashToken *trash = new TrashToken();
//            trash->add_to_play(*gb, rndx, rndy);
//        }
    }
}

/**
 * @brief move_north --> this is actually move south
 * Move player, move robots and check_collision
 */
void RobotEngine::move_north() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_south(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx, tempy+1) == -2) {
        quit();
    }
}

void RobotEngine::move_south() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_north(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx, tempy-1) == -2) {
        quit();
    }
}

void RobotEngine::move_east() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    int newx = tempx;
    int newy = tempy + 1;
    // check boundaries
    if (newy >= screenendy) {
        // just don't change position
        newy = tempy;
    } else {
        p->move_east(*gb);
        move_robots();
        numMoves ++;
    //    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx-1, tempy) == -2) {
    //        quit();
    //    }
    }
}

void RobotEngine::move_west() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_west(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx+1, tempy) == -2) {
        quit();
    }
}

void RobotEngine::move_northeast() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_south_east(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx-1, tempy+1) == -2) {
        quit();
    }
}

void RobotEngine::move_northwest() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_south_west(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx+1, tempy+1) == -2) {
        quit();
    }
}

void RobotEngine::move_southeast() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_north_east(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx-1, tempy-1) == -2) {
        quit();
    }
}

void RobotEngine::move_southwest() {
    int tempx = p->get_location_x();
    int tempy = p->get_location_y();
    p->move_north_west(*gb);
    move_robots();
    numMoves ++;
    if (p->respond_to_neighbours(*gb, tempx, tempy, tempx+1, tempy-1) == -2) {
        quit();
    }
}

int RobotEngine::get_num_robots() {
    return numRobots;
}

int RobotEngine::get_score() {
    return score;
}

int RobotEngine::get_num_moves() {
    return numMoves;
}

int RobotEngine::get_player_x() {
    return playerx;
}

int RobotEngine::get_player_y() {
    return playery;
}

/**
 * @brief get_robot_position_x Method to return x position of the
 *                             robot at the i-th position in the walls
 * @param i int position in the robot
 * @return int
 */
int RobotEngine::get_robot_position_x(int i){

    RobotToken *r = &rlist.at(i);
    return (r->get_location_x());

}

/**
 * @brief get_robot_position_y Method to return y position of the
 *                             robot at the i-th position in the walls
 * @param i int position in the robot
 * @return int
 */
int RobotEngine::get_robot_position_y(int i){

    RobotToken *r = &rlist.at(i);
    return (r->get_location_y());

}

