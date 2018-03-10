#include <iostream>
#include <curses.h>
#include <string>
#include "../robot/robotengine.h"

using namespace std;

void draw_screen(RobotEngine *r);
void examine_gameboard(RobotEngine *r);
int rows,cols;
bool continue_looping;

int main() {
    initscr();

    rows = 23;
    cols = 65;

    bool newGame;


        // hide the cursor from view (comment this line out for debugging)
        curs_set(0);
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

        RobotEngine *r = new RobotEngine(rows, cols);
        // examine_gameboard(&r);
        mvprintw(0,0,"Before draw 0,0");
        mvprintw(20,65,"Before draw 100,100");
        refresh();
        draw_screen(r);
        do {

            // draw the new screen
            refresh();

            // obtain character from keyboard
            int ch = getch();

            // operate based on input character
            bool result;
            switch (ch) {

            case 'l':
                r->move_east();

            case '\n':

                continue_looping = false;
                break;

            }

        //continue_looping = false;
        refresh();

    } while(continue_looping);
    refresh();
    endwin();

}


void draw_screen(RobotEngine *r) {
    //Clear the screen
    clear();

    for(int i = 0; i < rows; i++){
        mvprintw(i, 0, "|");
        mvprintw(i, cols, "|");
    }

    for(int i = 0; i < cols; i++){
        mvprintw(0, i,    "-");
        mvprintw(rows, i, "-");
    }

    // get player position
    int x = r->get_player_x();
    int y = r->get_player_y();

    mvprintw(x+1 ,y+1,"@");

    int roboLength = r->get_num_robots();
    //Printing worm body
    for(int i=0; i<roboLength ;i++){

        int roboX = r->get_robot_position_x(i)+1;
        int roboY= r->get_robot_position_y(i)+1;
        mvprintw(roboX,roboY,"+");
        refresh();

    }


    //Setting up directions
    mvprintw(0,66, "Directions:");
    mvprintw( 2, 66, "y");
    mvprintw(2, 70,"k" );
    mvprintw(2, 74, "u");

    mvprintw(4, 66, "h");
    mvprintw(4, 74, "l");

    mvprintw( 6, 66, "b");
    mvprintw(6, 70,"j" );
    mvprintw(6, 74, "n");

    mvprintw(3, 68,"\\");
    mvprintw(3, 70, "|");
    mvprintw(3, 72,"/");

    mvprintw(4, 68, "-");
    mvprintw(4, 72, "-");

    mvprintw(5, 68,"/");
    mvprintw(5, 70, "|");
    mvprintw(5, 72,"\\");


    mvprintw( 9, 66, "Commands:");
    mvprintw(11, 66, "t : Teleport");
    mvprintw(12, 66, "Enter: quit");

    mvprintw(14, 66, "Legend:");
    mvprintw(16, 66, "@ : You");
    mvprintw(17, 66, "+ : Robot");
    mvprintw(18, 66, "* : Trash");

    refresh();

}

void examine_gameboard(RobotEngine *r){

    for(int i = 0; i < cols; i++){
        for(int j = 0; j< rows; j++){
            GameToken *g = r->get_token(j,i);
        }
    }
}




