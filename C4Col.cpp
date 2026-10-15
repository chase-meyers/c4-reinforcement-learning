#include <iostream>
#include "C4Col.h"

using namespace std;

//initalize the functions 
C4Col::C4Col(){ 
    num_disc = 0; 
    max_disc = 6;
    
    for (int i=0; i < max_disc; i++){
        disc[i] = '-';
    }
}

// member functions elaborated 
bool C4Col::isFull(){                        //checking whether the board is full
    if( num_disc == max_disc ){
        return(1);
    }else{
        return(0);
    }
}

char C4Col::getDisc(int i){                             //setting up the board 
    // cout << "I: " << i <<endl;
     if (i < 0 || i > max_disc) {
        cout << "Error: not getting right" << endl;
        return '\0';
     }

      if (i >= num_disc) {
        return '-';   // or whatever you used for empty
    }
     return disc[i];                                   //return what???
}             

int  C4Col::getMaxDiscs(){return max_disc;}                   // the maxim of disc

void C4Col::addDisc(char di){                              //adding more discs if not full. if full, warning
    if( isFull() ){
        cout << "Disc Full, not able to add " << endl;
    }

    cout << "di: " << di << endl;
    disc[num_disc] =  di ;
    cout << "test" << endl;
    
    num_disc++ ;
}   


