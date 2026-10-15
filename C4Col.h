#ifndef C4COL_H                              //why 1
#define C4COL_H

class C4Col{

    private: 
    int num_disc;              //No of dics in the column 
    int max_disc;              // maximum number of discs allowed 
    char disc[6];               //storing each player's disc, 6 being maxim

    public: 
     C4Col();                //constructor
     bool  isFull() ;           //if colume is full 
     char getDisc(int i) ;      // return if disc[i] is valid
     int  getMaxDiscs() ;      //return the maxim number of disc
     void addDisc(char);     // adding a disc to non-occupied disc array 
};

#endif