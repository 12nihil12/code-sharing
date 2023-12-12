#ifndef arr_2_0
#define arr_2_0

#include <iostream> 
#include <fstream>
#include <cstring>
#include "libArray.h"

//#define dim0 20
//#define incr 10

using namespace std; 

struct arr_int{
    int * raw; // indirizzo di inzio array
    int used; // prima posizione libera array
    int size; // dimensione array
};

bool leggiDato(ifstream& file, int &rdato); 
int resize_arr (arr_int & myA, int newdim); 
int up_file (char nomefile [], arr_int& myA); 

#endif