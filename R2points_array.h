#include "R2point.h"
#include <iostream>
#include <fstream> 

#ifndef R2_POINTS_ARRAY
#define R2_POINTS_ARRAY


struct points_array {
    int size; // dimensione
    int used; // indice della prima posizione libera
    R2point * raw; //puntatore ad inizio array di tipo R2point 
}; 


points_array load_points_file (char nomefile[], int & errcode); //carica i punti da un file

void print_points_file(char nomefile[], R2point v[], int da, int a); //stampa array da indice a indice 

void retta(points_array v, double m, double q); 

void baricentri (points_array v, double & x_m, double & y_m); // restituisce i p
double scarto_xy (points_array v,double x_m, double y_m); //calcola il prodotto degli scarti (per covarianza)
double scarto_2 (points_array v,double x_m, double y_m, bool which); //calcola lo scarto al quadrato di x (which = 1) o y (which = 0)


#endif
