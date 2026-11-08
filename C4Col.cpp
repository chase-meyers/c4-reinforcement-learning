#include <iostream>
#include "C4Col.h"

using namespace std;

//initalize the functions 
C4Col::C4Col(int maxHeight){ 
    num_disc = 0; 
    max_disc = maxHeight;
    disc.resize(max_disc, '-');
}

// member functions elaborated 
bool C4Col::isFull(){                        //checking whether the board is full
   return num_disc >= max_disc; 
}

char C4Col::getDisc(int i){                             //setting up the board 
     if (i < 0 || i > max_disc) { return '\0';}
     return disc[i];                                   //return disc number
}             

int  C4Col::getMaxDiscs(){return max_disc;}                   // the maxim of disc

void C4Col::addDisc(char di){                              //adding more discs if not full. if full, warning
    if( isFull() ){
        cout<< "Column full ! " << endl; 
        return; 
    }

    disc[num_disc] =  di;
    num_disc++ ;
}   


