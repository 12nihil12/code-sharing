#include "stat_adv.h"

double std_gaussian (double z){
    double C = 1/sqrt(2*PI); 
    double exp = - pow(z,2)/2; 
    return C*pow(e,exp); 
}

double int_gaussian (double mu, double sigma, double x, int k){
    double z_0 = abs(mu - x)/sigma; 
    return int_ril(k,0,z_0,std_gaussian); 
}

double gauss_int (double z_0,int k){

    double P=0; 
    double z; 
    double C = 1/sqrt(2*PI); 
    double exp; 
    for(int c= 0; c < k; c++){
        z= randunif(0,z_0); 
        exp = - pow(z,2)/2; 
        P = P + C*pow(e,exp); 
    }

    return P*1.42/k; 
}

long int fact(int n){
    if(n == 0){
        return 1; 
    }
    return n*fact(n-1); 
}

double binom(int k, int n, double p){ //calcola la probabilità di avere k successi con probabilità singola p e num max successi n
        double q = 1-p;  
        double C = double(fact(n))/(fact(k)*fact(n-k)); 
        return C*pow(p,k)*pow(q, n-k); 
}

double binom(int k, int n, double p,double& mu, double& sigma){// calcola la probabilità di k successi, restituisce mu e sigma
        double q = 1-p;  
        double C = double(fact(n))/(fact(k)*fact(n-k)); 
        mu = n*p; 
        sigma = sqrt(n*p*q); 
        return C*pow(p,k)*pow(q, n-k); 
}


double poissonian (int k, double lambda){ // calcola la probabilità di k successi con valore medio lambda 
    return (pow(lambda, k)/fact(k))*pow(e,-lambda); 
}



double chi_quad (data_set x, double mu, double sigma){
    double chi = 0;  
    double scarto; 
    for (int i = 1; i <= x.used; i++){
        scarto = x.raw[i]-mu; 
        chi = pow((scarto),2)/pow(sigma,2); 
    }

    return chi; 
}