#include "R2point.h"

#ifndef R2_POINTS_ARRAY
#define R2_POINTS_ARRAY


struct points_array {
    int size; // dimensione
    int used; // indice dell'ultimo valore caricato !!CHIEDERE SE POSSO!!
    R2point * raw; //puntatore ad inizio array di tipo R2point 
}; 


points_array load_points_file (char nomefile[], int & errcode); //carica i punti da un file

void print_points_file(char nomefile[], R2point v[], int da, int a); //stampa array da indice a indice 


#endif
