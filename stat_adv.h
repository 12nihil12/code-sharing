#ifndef stat_adv_h
#define stat_adv_h

#include <iostream> 
#include <cmath> 
#include "libArray.h"
#include "librandom.h"
#include "R2points_array.h"
#include "libstat.h"
#define e 2.71828

using namespace std; 



struct dato{ //memorizza il dato con la sua incertezza
    float val;  
    float sigma; 
}; 

struct data_set { //array dove salvo i dati
    int size; 
    int used;
    dato * raw; 

}; 


double retta_min_quad (points_array v,double & m, double& q); 

long int fact(int n); 


double binom(int k, int n, double p); //calcola la probabilità di avere k successi con probabilità singola p e num max successi n
double binom(int k, int n, double p,double& mu, double& sigma); // calcola la probabilità di k successi, restituisce mu e sigma

double poissonian (int k, double lambda); // calcola la probabilità di k successi con valore medio lambda 
double std_gaussian (double z); //standard gaussiana 

double int_gaussian (double mu, double sigma, double x, int k); //integrale gaussiana
//double gauss_int (double z_0,int k); //integrale gaussiana



double chi_quad (data_set x, double mu, double sigma); 

#endif



