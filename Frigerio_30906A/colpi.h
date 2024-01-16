#ifndef colpo_h
#define colpo_h

#include <iostream>
#include <fstream> 
#include <cmath>

# define V 100

using namespace std; 

struct colpo {
    float theta,phi; //alzo e angolo di tiro
    float xf,yf; // coordinate impatto
    bool hit; // a segno?  
}; 

struct arr_colpi {
    int used,size; 
    colpo * raw; 
}; 

int posmax (float v[], int i, int size);//restituisce posizione elemento minimo array di (size) elementi a partire da i
int posmin (float v[], int i, int size);//restituisce posizione elemento minimo array di (size) elementi a partire da i


void segno(colpo & appo,float d); 

bool readcolpo (ifstream &file, colpo &appo);

int caricacolpo(char nomefile[], arr_colpi* pMyArray); 

bool printcolpo(ofstream &file, colpo appo);
bool printcolpo( colpo appo);


void stampaarrcolpi(arr_colpi v, char nomefile []);

#endif