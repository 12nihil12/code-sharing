#include <iostream>
#include <fstream> 
#include <cstdlib> 
#include <time.h> 
#include <cmath> 

using namespace std; 

#define PI 3.14159

double randunif (double min, double max); //restituisce un valore random nell'intervallo [a,b]
double randgauss (double media, double stdv); //restituisce una variabile x appartenente ad una gaussiana a partire da una z random
void seedset (); //resetta il seed, se l'utente lo vuole


