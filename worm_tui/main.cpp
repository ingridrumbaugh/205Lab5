#include <iostream>
#include <curses.h>
#include <string>
#include "../worm/wormengine.h"

using namespace std;

/**
 * @brief draw_screen Function to draw the screen
 * @param v WormEngine object
 */
void draw_screen(WormEngine *v);

int rows,cols;


int main() {
    initscr();

    //Number of rows and cols in the gameboard
    rows = 73;
    cols = 23;

    //Variable determind starting a new game or not
    bool newGame;

    do{
        // hide the cursor from view (comment this line out for debugging)
        curs_set(0);

        // disables line buffering and erase/kill character-processing
        // (interrupt and flow control characters are unaffected),
        // making characters typed by the  user  immediately
        // available to the program
        cbreak();

        // control whether characters  typed  by  the user  are echoed
        // by getch as they are typed
        noecho();

        // the user can press a function key (such as an arrow key) and
        // getch returns a single value representing the  function  key,
        // as in KEY_LEFT
        keypad(stdscr, TRUE);


        // initialize the interaction loop to run
        bool continue_looping = true;

        WormEngine w(rows, cols);
        //examine_gameboard(&w);
        // draw the current screen
        draw_screen(&w);

        do {

            // draw the new screen
            refresh();

            // obtain character from keyboard
            int ch = getch();

            // operate based on input character
            bool result;
            switch (ch) {

            case KEY_DOWN:

                result = w.move(3);

                if(!result){
                    continue_looping = false;

                }
                break;

            case KEY_UP:

                result = w.move(2);

                if(!result){
                    continue_looping = false;
                }
                break;

            case KEY_LEFT:

                result =  w.move(1);

                if(!result){
                    continue_looping = false;
                }
                break;

            case KEY_RIGHT:

                result = w.move(0);

                if(!result){
                    continue_looping = false;
                }
                break;

            case '\n':

                continue_looping = false;
                break;

            }

            draw_screen(&w);

        } while(continue_looping);

        refresh();			/* Print it on to the real screen */

        // cleanup the window and return control to bash
        endwin();

        std::cout<< "Well you ran into something and the game is over"<<endl;
        std::cout<< "Your final score is:"<<w.get_score()<<endl;

        std::cout<< "Do you want to play another game? (Yes/No):";

        std::string ans;
        std::cin >> ans;
        if(! ans.compare("Yes") || !ans.compare("yes"))
            newGame = true;
        else
            newGame = false;

        std::cout << std::endl;
    }while(newGame);


    return 0;
}

/**
 * @brief draw_screen Function to draw the screen
 * @param v WormEngine object
 */
void draw_screen(WormEngine *v){

    //Clear the screen
    clear();

    //Drawing boundaries (top and bottom)
    for(int i=0; i<74; i++){
        mvprintw(0,i,"-");
        mvprintw(23,i ,"-");

    }

    //Drawing boundaries (left and right)
    for(int i=0; i<24; i++){
        mvprintw(i,0,"|");
        mvprintw(i,73 ,"|");

    }


   //Printing worm
    //Getting length of worm
    int length = v->get_length();

    //Printing head
    int x = v->get_token_position_x(0);
    int y = v->get_token_position_y(0);
    mvprintw(y+1 ,x+1,"@");

    //Printing worm body
    for(int i=1; i<length ;i++){

        int x = v->get_token_position_x(i);
        int y = v->get_token_position_y(i);
        mvprintw(y+1,x+1,"*");

    }

    //Printing walls
    int wallLength = v->get_wall_length();
    for(int i = 0; i < wallLength ; i++){

        int x = v->get_wall_position_x(i);
        int y = v->get_wall_position_y(i);
        mvprintw(y+1,x+1,"+");

    }


    //Printing food
    if(v->get_food_location_x() != -1 && v->get_food_location_y()!= -1)
    {
        int x = v->get_food_location_x() +1 ;
        int y = v->get_food_location_y() +1 ;
        int val = v->get_food_value();
        std::string display = std::to_string(val);
        mvprintw(y,x,display.c_str());

    }

    //Printing score
    std::string score = std::to_string(v->get_score());
    mvprintw(20, 74, "Score:");
    mvprintw(21, 74,score.c_str());

    //Printing name
    mvprintw(1, 74, "WORM");


}


