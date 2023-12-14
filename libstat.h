#ifndef libstat_h
#define libstat_h

#include <iostream> 
#include <cmath> 
#include "libArray.h"

using namespace std; 



float media (int [], int );
float media (float [], int );
double media (double [], int );


float devstd (int [], int );
float devstd (float [], int );
double devstd (double [], int );

float devstd (int [], int , float ); //dvst con media 
float devstd (float [], int , float); //dvst con media 
double devstd (double [], int , float); //dvst con media 


float mediana (int [], int );
float mediana (float [], int );


#endif