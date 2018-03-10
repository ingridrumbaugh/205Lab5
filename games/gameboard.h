#ifndef GAMEBOARD_H
#define GAMEBOARD_H
//#include "gametoken.h"
//#include "playertoken.h"
//#include "foodtoken.h"
//#include "trashtoken.h"
//#include "walltoken.h"

using namespace std;
template <class T>
class GameBoard{

public:

    /**
     * @brief GameBoard Default constructor for GameBoard
     */
    GameBoard();

    /**
     * @brief GameBoard
     * Constructor to define size of gameboard
     * @param x
     * @param y
     */
    GameBoard(int x, int y);

    /**
      * @brief Default destructor for GameBoard
      */
    ~GameBoard();

    /**
     * @brief get_num_rows Returns the number of Rows
     * @return
     */
    int get_num_rows();

    /**
     * @brief get_num_cols Returns the number of Cols
     * @return
     */
    int get_num_cols();

    /**
     * @brief clear_board Makes all positions of board nullptr
     */
    void clear_board();

    /**
     * @brief get_token Get the token at certain location on the board
     * @param x int x location
     * @param y int y location
     * @return T*
     */
    T* get_token(int x, int y);

    /**
     * @brief set_pointer Setting the pointer at a specific location
     *                    to a given pointer of T
     * @param t T* pointer to object
     * @param x int x location
     * @param y int y location
     */
    void set_pointer(T* t, int x, int y);

    /**
     * @brief reset_game Method that clears the gameboard
     */
    void reset_game();


    /**
     * @brief restart_game Method the restarts the game
     */
    void restart_game();

    /**
     * @brief GameBoard::game_count Returns the number of games played with a game instance
     * @return
     */
    int game_count();

    /**
     * @brief game_finished method that returns if the game is finished
     * @return
     */
    bool game_finished();

    /**
     * @brief increase_score Method that increases the score
     */
    void increase_score();

    /**
     * @brief check_score Method that returns the score
     * @return
     */
    int check_score();
private:

    //instance variables for board data
    T ***board;
    int rows;
    int cols;

    bool gameActive;
    bool whosTurn;     // Player 1 or 2 turn
    bool spotOccupied; // Is there a token at this location

    int playerType; // = 0;
    int robotType;  // = 1;
    int trashType;  // = 2;
    int wallType;   // = 3;

    int numTokens; // Number of tokens, players, robots, etc.
    int numPlayers;
    int numRobots;
    int numTrash;
    int numWalls;

    int score;     // score of the game
    int p1Turns;   // Number of turns played by p1
    int p2Turns;   // Number of turns played by p2
    int numGames;  // Number of games played with that instance of gameboard
    int whoWon;    // 1 if P1 won, 2 if P2 won

};

/**
 * @briefGameBoard default constructor that makes the board
 */
template <class T>
GameBoard<T>::GameBoard() {
    rows = 5;
    cols = 5;
    // allocationT
    board = new T**[rows];

    for(int i = 0; i < rows; i++) {
        board[i] = new T*[cols];
    }

    // initialization
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            board[i][j] = nullptr;
        }
    }

    gameActive = true;
    numGames = 1;
    score = 0;
    p1Turns = 0;
    p2Turns = 0;
    // << "Leaving Gameboard cosntructor";
}

/**
 * @brief Constructor that makes board
 * User defined gameboard of size x and y
 */
template <class T>
GameBoard<T>::GameBoard(int x, int y) {
    // std::cerr<<"Entering gameboard template"<<endl;
    rows = x;
    cols = y;
    board = new T**[rows];

    for(int i = 0; i < rows; i++) {
        board[i] = new T*[cols];
    }

    // initialization
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            board[i][j] = nullptr;
        }
    }

    gameActive = true;
    numGames = 1;
    score = 0;
    p1Turns = 0;
    p2Turns = 0;
    // std::cerr<<"Leaving gameboard template"<<endl;
}

/**
 * @brief Default destructor that removes board
 */
template <class T>
GameBoard<T>::~GameBoard() {
    gameActive = false;
    numGames = 0;
    score = 0;
    p1Turns = 0;
    p2Turns = 0;
    for(int i = 0; i < rows; i ++) {
        if(board[i] != nullptr)
            delete board[i];
    }
    delete board;
}

/**
 * @brief Clears the board - makes all elements nullptr
 */
template <class T>
void GameBoard<T>::clear_board() {
    for(int j = 0; j < cols; j++) {
        for(int i = 0; i < rows; i++) {
            board[i][j] = nullptr;
        }
    }

}

/**
 * @brief get_num_cols  Returns the number of columns
 */
template <class T>
int GameBoard<T>::get_num_cols() {
    return cols;
}

/**
 * @brief get_num_rows Returns the number of rows
 */
template <class T>
int GameBoard<T>::get_num_rows() {
    return rows;
}

/**
 * @brief get_token Get the token at certain location on the board
 * @param x int x location
 * @param y int y location
 * @return T*
 */
template <class T>
T* GameBoard<T>::get_token(int x, int y){

    T *t = board[x][y];
    if(t == nullptr)
        t = nullptr;
    return t;
}

/**
 * @brief set_pointer Setting the pointer at a specific location
 *                    to a given pointer of T
 * @param t T* pointer to object
 * @param x int x location
 * @param y int y location
 */
template <class T>
void GameBoard<T>::set_pointer(T* t,int x, int y ){
    board[x][y] = t;
}

/**
 * @brief reset_game Method that clears the gameboard
 */
template <class T>
void GameBoard<T>::reset_game(){
    clear_board();
    score = 0;
    numGames ++;
    p1Turns = 0;
    p2Turns = 0;
    gameActive = true;
}


/**
 * @brief GameBoard::game_count Returns the number of games played with a game instance
 * @return
 */
template <class T>
int GameBoard<T>::game_count() {
    return numGames;
}

/**
 * @brief GameBoard::game_finished Returns the status of the game
 * @return
 */
template <class T>
bool GameBoard<T>::game_finished() {
    // std::cerr<<"In game Finished "<<gameActive<<endl;
    return gameActive;
}

/**
 * @brief GameBoard::restart_game
 * Clears the gameboard, resets score and increases number of games.
 */
template <class T>
void GameBoard<T>::restart_game() {
    // Reset board by setting all ptrs to null,
    // Can still access player token instances that were created.
    clear_board();
    score = 0;
    numGames ++;
    p1Turns = 0;
    p2Turns = 0;
    gameActive = true;
}


/**
 * @brief GameBoard::increase_score Increments the score
 */
template <class T>
void GameBoard<T>::increase_score() {
    score++;
}

/**
 * @brief GameBoard::check_score Returns the score of the game.
 * @return
 */
template <class T>
int GameBoard<T>::check_score() {
    return score;
}


#endif // GAMEBOARD_H
