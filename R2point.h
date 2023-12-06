#ifndef R2_POINT
#define R2_POINT

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip> 

using namespace std; 

struct R2point
{
    double x; //ascisse
    double y; //ordinate 
};

bool load_point (ifstream& file_in, R2point & p); //carica da file un singolo punto in p, restituisce true se l'ha fatto


void print_point_file (ofstream& file_out, char nomefile[], R2point p); //print on file


#endif

