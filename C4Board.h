#ifndef C4BOARD_H                              //why 1
#define C4BOARD_H

#include <iostream>
#include <vector>
#include "C4Col.h"

using namespace std;

class C4Board{
private: 
    int  num_col ;        //number of colums
    vector<C4Col> board;           //board composed of vector C4col colums
public:
    C4Board(int cols =7, int rows =6);            //constructor set default to 7 * 6 board
    void display();         //display current board
    void play();            //two players to play a game
    char  checkwin();        //check winning status    
    void exportBoardToFile();  
};
#endif
