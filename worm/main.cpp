#include <iostream>
#include "wormengine.h"

using namespace std;

void test_default_constructor();
void test_parameterised_constructor();
void test_move_east();
void test_move_west();
void test_move_north();
void test_move_south();
int main()
{
    /**Note that there arent a lot of tests
     * because a lot of major functions are private**/

    test_default_constructor();
    test_parameterised_constructor();


    test_move_east();
    test_move_west();
    test_move_south();
    test_move_north();




}
void test_default_constructor(){

    //Testing default constructor
    WormEngine *w1 = new WormEngine();
    GameToken *g1 = w1->get_token(0,0);
    if(g1->what_are_you() == 0){
        if(w1->get_food_location_x()!= -1
                && w1->get_food_location_y() != -1)
        {
            if(w1->get_wall_length()>0){
                int wallX = w1->get_wall_position_x(0);
                int wallY =  w1->get_wall_position_y(0);
                if(w1->get_token(wallX, wallY)->what_are_you() == 3){

                    std::cout<<"Default constructor test passed"
                            << std::endl;
                }
            }
        }

    }
}

void test_parameterised_constructor(){
    //testing parameterised constructor
    WormEngine *w2 = new WormEngine(5,5);
    GameToken *g2 = w2->get_token(0,0);
    if(g2->what_are_you() == 0){
        if(w2->get_food_location_x()!= -1
                && w2->get_food_location_y() != -1)
        {
            if(w2->get_wall_length()>0){
                int wallX = w2->get_wall_position_x(0);
                int wallY =  w2->get_wall_position_y(0);
                if(w2->get_token(wallX, wallY)->what_are_you() == 3){

                    std::cout<<"Parameterised constructor test passed"
                            << std::endl;
                }
            }
        }

    }

}
void test_move_east(){
    WormEngine *w3 = new WormEngine();
    // PlayerToken *p1 = w3->get_token(0);
    int x1 = w3->get_token_position_x(0);
    int y1 = w3->get_token_position_y(0);
    w3->move(0);
    int x2 = w3->get_token_position_x(0);
    int y2 = w3->get_token_position_y(0);

    if(x2 - x1 == 1 && y1==y2){
        std::cout<<"Test move east passed"<<std::endl;
    }
}

void test_move_west(){
    WormEngine *w3 = new WormEngine();
    int x1 = w3->get_token_position_x(0);
    int y1 = w3->get_token_position_y(0);

    w3->move(0);
    w3->move(1);
    int x2 = w3->get_token_position_x(0);
    int y2 = w3->get_token_position_y(0);

    if(x2 == x1 && y1==y2){
        std::cout<<"Test move west passed"<<std::endl;
    }
}

void test_move_south(){
    WormEngine *w3 = new WormEngine();
    //  PlayerToken *p1 = w3->get_token(0);
    int x1 = w3->get_token_position_x(0);
    int y1 = w3->get_token_position_y(0);

    w3->move(3);
    int x2 = w3->get_token_position_x(0);
    int y2 = w3->get_token_position_y(0);

    if(x2 == x1 && y2 - y1 == 1){
        std::cout<<"Test move south passed"<<std::endl;
    }
}

void test_move_north(){
    WormEngine *w3 = new WormEngine();
    // PlayerToken *p1 = w3->get_token(0);
    int x1 = w3->get_token_position_x(0);
    int y1 = w3->get_token_position_y(0);
    w3->move(2);
    w3->move(0);
    w3->move(3);

    int x2 = w3->get_token_position_x(0);
    int y2 = w3->get_token_position_y(0);

    if(x2 -x1 == 1 && y2 - y1
            == 1){
        std::cout<<"Test move north passed"<<std::endl;
    }
}
