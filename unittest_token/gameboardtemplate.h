#ifndef GAMEBOARDTEMPLATE_H
#define GAMEBOARDTEMPLATE_H
using namespace std;
#include <iostream>

template <class T>
class GameBoardTemplate{
public:

    /**
     * @brief GameBoardTemplate Deafult constructor for GameBaord
     */
    GameBoardTemplate();

    //getter methods

    /**
     * @brief get_pointer Returns the triple pointer
     * @return
     */
    T*** get_pointer();

    /**
     * @brief get_num_rows Returns the number of rows
     * @return int
     */
    int get_num_rows();

    /**
     * @brief get_num_cols Returns the numer of columns
     * @return
     */
    int get_num_cols();

private:

    //instance variables for board data
    T ***board;
    int rows;
    int cols;

};

/**
 * @brief GameBoardTemplate default constructor that makes the board
 */
template <class T>
GameBoardTemplate<T>::GameBoardTemplate() {
    rows =5;
    cols =5;
    // allocationT
    board = new T**[rows];

    for(int i = 0; i < 5; i++) {
        board[i] = new T*[rows];
    }

    // initialization
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            board[i][j] = nullptr;
        }
    }
}

/**
 * @brief get_pointer Returns the triple pointer
 * @return
 */
template <class T>
T*** GameBoardTemplate<T>::get_pointer() {
    return board;
}

/**
 * @brief get_num_rows Returns the number of rows
 * @return int
 */
template <class T>
int GameBoardTemplate<T>::get_num_cols() {
    return cols;
}


/**
 * @brief get_num_cols Returns the numer of columns
 * @return
 */
template <class T>
int GameBoardTemplate<T>::get_num_rows() {
    return rows;
}


#endif // GAMEBOARD_H
