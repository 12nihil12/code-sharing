#ifndef mathfunctions_h
#define mathfunctions_h

#include <iostream>
#include "librandom.h"


double f_max (double (*f)(double x), double a, double b, double & p_max, int k); //trova max funzione continua in un intervallo
double f_min (double (*f)(double x), double a, double b, double & p_min, int k); //trova min funzione continua in un intervallo


#endif
