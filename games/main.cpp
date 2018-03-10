#include <iostream>
#include "gameboard.h"
#include "gametoken.h"

using namespace std;

int main()
{

    GameBoard<GameToken> g;
    for(int i=0; i< g.get_num_cols();i++){
        for(int j=0; j< g.get_num_rows();j++){
            if( g.get_token( i,j) != nullptr)
            GameToken *b = g.get_token(i,j);
        }
    }
    return 0;
}
