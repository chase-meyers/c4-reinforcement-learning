#ifndef C4COL_H                              //why 1
#define C4COL_H
#include <vector>

using namespace std;

class C4Col{

    private: 
    int num_disc;              //No of dics in the column 
    int max_disc;              // maximum number of discs allowed 
    vector<char> disc;               //storing each player's disc, flexible size

    public: 
     C4Col(int maxHeight = 6);                //constructor, default to 6 if not specified
     bool  isFull() ;           //if colume is full 
     char getDisc(int i) ;      // return if disc[i] is valid
     int  getMaxDiscs() ;      //return the maxim number of disc
     void addDisc(char);     // adding a disc to non-occupied disc array 
};

#endif