#include "C4Board.h"
#include "C4Col.h"

#include <iostream>
using namespace std;

//setting the initiation 
C4Board::C4Board(){
      num_col = 7; 
}

void C4Board::display(){

    for( int row = board[0].getMaxDiscs() - 1; row >= 0; row-- ){
        for( int col = 0; col < 7; col++ ){
            cout  << board[col].getDisc(row) << " | ";
        }
        cout << endl;
    }

    for (int col = 0; col < num_col; col++) {
        cout << "--" ;
    }
    cout << endl;

    // print column numbers
    for (int col = 0; col < num_col; col++) {
        cout << col << " " ;
    }
    cout << endl;
}

char C4Board::checkwin() {
    int ROWS = board[0].getMaxDiscs();  // usually 6
    int COLS = num_col;                 // usually 7

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {

            char p = board[c].getDisc(r);
            if (p == '-' || p == ' ' || p == '\0') continue;

// ---- Horizontal (to the right) ----
            if (c + 3 < COLS) {
                if (board[c+1].getDisc(r) == p &&
                    board[c+2].getDisc(r) == p &&
                    board[c+3].getDisc(r) == p) {
                    return p;
                }
            }

            // ---- Vertical (upwards in the column) ----
            if (r + 3 < ROWS) {
                if (board[c].getDisc(r+1) == p &&
                    board[c].getDisc(r+2) == p &&
                    board[c].getDisc(r+3) == p) {
                    return p;
                }
            }

            // ---- Diagonal down-right ----
            if (c + 3 < COLS && r + 3 < ROWS) {
                if (board[c+1].getDisc(r+1) == p &&
                    board[c+2].getDisc(r+2) == p &&
                    board[c+3].getDisc(r+3) == p) {
                    return p;
                }
            }

 // ---- Diagonal up-right ----
            if (c + 3 < COLS && r - 3 >= 0) {
                if (board[c+1].getDisc(r-1) == p &&
                    board[c+2].getDisc(r-2) == p &&
                    board[c+3].getDisc(r-3) == p) {
                    return p;
                }
            }
        }
    }
    return ' ';  // no winner
}


void C4Board::play(){
   int choice = 0;
   int counter = 0;
   while (true) {    

    display(); 

    char playerturn = (counter % 2 == 0) ? 'x' : 'o';
   
    cout << "Player's " << playerturn << "'s turn: choose the colum to add disc, or -1 to end the game"<< counter << endl; 
  
    cin >> choice;      // player's input 

    // check the validity of input
    if (choice == -1) {                                    //input to end the game by -1
        cout << "input -1: end the grame" << endl; 
        break;
    }

    if (choice < 0 || choice >= num_col){                 //input out of boundary to restart the loop
        cout << "invalid column number" << endl;
        continue;
    }

//    cout << "board: " << board[choice] << endl;
    board[choice].addDisc(playerturn);
   
//using checkwin to declare win
    char winner = checkwin();
    if (winner != ' ') {
        display();
        cout << "\n*****************************\n";
        cout << "🎉 Congratulations! Player " << winner << " wins! 🎉\n";
        cout << "\n*****************************\n";
        return;
    }
    else{
        cout << "No winners, tied" << endl;
    }
//    //continue to next player and looping

    counter ++; 
    }
}





