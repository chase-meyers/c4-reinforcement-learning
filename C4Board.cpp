#include "C4Board.h"
#include "C4Col.h"

#include <iostream>
#include <fstream>
using namespace std;

//setting the initiation 
C4Board::C4Board(int cols, int rows){
      num_col = cols; 
      board = vector<C4Col>(num_col, C4Col(rows));
}

void C4Board::display(){
    int max_rows = board[0].getMaxDiscs();

    for( int row = max_rows - 1; row >= 0; row-- ){
        for( int col = 0; col < num_col; col++ ){
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
        cout << col % 10 << " " ;
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
   int counter = 1; // Starts at 1 (Odd = Human 'x', Even = AI 'o')
   while (true) {    

    display(); 

    // Determine whose turn it is based on counter parity
    char playerturn = (counter % 2 != 0) ? 'x' : 'o';
   
    if (playerturn == 'x') {
        cout << "Player x's turn: choose column (0-6), or -1 to end: "; 
        cin >> choice;      

        if (choice == -1) {                                    
            cout << "input -1: end the game" << endl; 
            break;
        }
    } 
    else {
        cout << "\nAI (o) is thinking..." << endl;
        exportBoardToFile();
        system("python3 agent_current.py");
        
        ifstream inFile("move.txt");
        if (inFile >> choice) {
            inFile.close();
        } else {
            choice = 0; 
        }
        cout << "AI chose column: " << choice << endl;
    }

    if (choice < 0 || choice >= num_col){                 
        cout << "invalid column number" << endl;
        continue; // <--- WARNING: If it hits this, counter++ is skipped!
    }

    board[choice].addDisc(playerturn);
   
    char winner = checkwin();
    if (winner != ' ') {
        display();
        cout << "\nCongratulations! Player " << winner << " wins!\n";
        return;
    }

    counter++; // <--- Must execute every successful turn to switch players!
   }
}

   
void C4Board:: exportBoardToFile(){
    ofstream outFile("board.txt");
    for (int row = board[0].getMaxDiscs() -1; row >= 0; row -- ){
        for (int col = 0; col < num_col; col++){
            outFile << board[col].getDisc(row) << "  ";
        }
        outFile << endl;
    }
    outFile.close(); 
}



