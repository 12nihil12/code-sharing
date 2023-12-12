#ifndef arr_2_0_h
#define arr_2_0_h

#include <iostream> 
#include <fstream>
#include <cstring>
#include "libArray.h"

// per caricamento dati da file su array: dimensione di partenza e incremento
#define dim0 20 
#define incr 10

using namespace std; 

struct arr_int{
    int * raw; // indirizzo di inzio array
    int used; // prima posizione libera array
    int size; // dimensione array
};

bool readdata(ifstream& file, int &rdato); //carico un singolo dato da file
int resize_arr (arr_int & myA, int newdim); // resizes array to newdim
int up_file (char nomefile [], arr_int& myA); //carica dati da file in array
int searchkey(arr_int & myA, int key); 
#endif