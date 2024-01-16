#ifndef bersaglio_h
#define bersaglio_h

#include <iostream>
#include <fstream> 

#define delta 10

using namespace std; 

struct bersaglio {
    float x,y; //coordinate 
    float c; // capacita` di corazza
    bool distr; // distrutto? 
}; 

struct arr_ber {
    int used,size; 
    bersaglio * raw; 
}; 


void colpito (bersaglio & appo, float d, float & acc); 
bool readbersaglio (ifstream &file, bersaglio &appo);

int caricabersaglio(char nomefile[], arr_ber* pMyArray); 

bool printbersaglio(ofstream &file, bersaglio appo);
bool printbersaglio(bersaglio appo); 

void stampaarrber(arr_ber v, char nomefile []);

#endif