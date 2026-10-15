#ifndef C4BOARD_H                              //why 1
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

class C4Board{
private: 
    int  num_col ;        //number of colums
    C4Col board[7];           //board composed of 10 C4col colums
public:
    C4Board();            //constructor
    void display();         //display current board
    void play();            //two players to play a game
    char  checkwin();        //check winning status      
};
#endif
