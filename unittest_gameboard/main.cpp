#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "../games/gametoken.h"
#include "../unittest_gameboard/playertoken.h"
#include "../games/robottoken.h"
#include "../games/trashtoken.h"
#include "../games/walltoken.h"
#include "../games/gameboard.h"
//#include "../games/gameboardtemplate.h"

#define ROWS 5
#define COLS 5

using namespace std;

/**
 * @brief TEST that the default constructor creates a 5 X 5 gameboard
 * Also assert that the game has started
 */
TEST(Constructor, TESTDEFAULTCONSTRUCT) {
    GameBoard<GameToken> gb;
    // std::cout << "Game Finished: "<< gb.game_finished() << std::endl;
    ASSERT_FALSE(gb.game_finished() == false);
    ASSERT_TRUE(gb.get_num_rows() == 5);
    ASSERT_TRUE(gb.get_num_cols() == 5); // Standard gameboard size
}

/**
 * @brief TEST a custom constructor that it creates a 10 X 10 gameboard instead
 */
TEST(Constructor, TESTCUSTOMCONSTRUCT) {
    GameBoard<GameToken> *gb2 = new GameBoard<GameToken>(10, 10);
    // cerr<< "Executed build";
    ASSERT_FALSE(gb2->game_finished() == false);
    ASSERT_TRUE(gb2->get_num_rows() == 10);
    ASSERT_TRUE(gb2->get_num_cols() == 10);
}

/**
 * @brief TEST the game count variable when two games are played
 * with the same instance
 */
TEST(GameStatus, TESTMULTIPLEGAMES) {
    GameBoard<GameToken> gb1;
    ASSERT_TRUE(gb1.game_count() == 1);
    //gb1.add_token(0, 0, 1);
    gb1.restart_game();
    //gb1.add_token(0, 0, 1);
    ASSERT_TRUE(gb1.game_count() == 2);
}

/**
 * @brief TEST that a score is reset when the game is reset
 */
TEST(GameStatus, TESTSCORERESET) {
    GameBoard<GameToken> gb;
    gb.increase_score();
    ASSERT_TRUE(gb.check_score() != 0);
    gb.restart_game();
    ASSERT_TRUE(gb.check_score() == 0);
}

/**
  * @brief TEST this test will be implemented later once the game is finished
  */
TEST(GameStatus, TESTLOCATIONRESET) {

    GameBoard<GameToken> *gb = new GameBoard<GameToken>;
    GameToken *temp = new GameToken();

    //Add and get token

    //GameBoard::set_pointer() is being implicitly tested
    //by add_to_play
    temp->add_to_play(*gb, 1, 1);
    temp = gb->get_token(1, 1);

    //GameToken is of type empty
    ASSERT_TRUE(static_cast<int>(temp->what_are_you()) == 5);

    //Restarting and getting token
    //Restart game implicitly tests clear board
    gb->restart_game();
    temp = gb->get_token(1, 1);

    ASSERT_EQ(temp, nullptr);
}

TEST(AddingAndRemovingObjects, TESTGETPOINTER){
    GameBoard<GameToken> *gb = new GameBoard<GameToken>();
    PlayerToken *p = new PlayerToken();
    p->add_to_play(*gb, 1, 1);
    GameToken *g = new GameToken();
    g = gb->get_token(1,1);
    ASSERT_EQ(g, p);
}


/**
 * @brief main Run all tests
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
