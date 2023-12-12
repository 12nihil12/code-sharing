#include "mathfunctions.h"

double f_max (double (*f)(double x), double a, double b, double & p_max, int k){
    double x; 
    double max = f(a); 


    for(int c = 0; c < k; c++ ){
        x = randunif(a,b); 
        if(f(x) > max){
            p_max = x; //mi passa per riferimento il punto di massimo
            max = f(x); 
        }
    }

    if(max < f(b)){ //siccome è improbabile che mi prenda l'estremo b
        max = f(b); 
        p_max = b; 
    }

    return max; 
}

double f_min (double (*f)(double x), double a, double b, double & p_min, int k){
    double x; 
    double min = f(a); 


    for(int c = 0; c < k; c++ ){
        x = randunif(a,b); 
        if(f(x) <  min){
            p_min = x; //mi passa per riferimento il punto di massimo
            min = f(x); 
        }
    }

    if (min > f(b)){ //siccome è improbabile che mi prenda l'estremo b
        min = f(b); 
        p_min = b; 
    }
    return min; 
}