#include "stat_adv.h"

//somme 

/*

double sum (double x [], int N){ // somma gli N termini x[i]
    double sum = 0; 
    for (int i = 0; i < N; i++){
        sum = sum + x[i]; 
    }
    return sum; 
}


double sum_2 (double x [], int N){ // somma gli N quadrati x[i]^2
    double sum = 0; 
    for (int i = 0; i < N; i++){
        sum = sum + pow(x[i],2); 
    }
    return sum; 
}

double cross_sum (points_array v){ // somma gli N prodotti x[i]*y[i]
    double sum = 0; 
    for (int i = 0; i < v.used; i++){
        sum = sum + v.raw[i].x*v.raw[i].y; 
    }
    return sum; 

}

double retta_min_quad (points_array v, double & m, double& q){

    double sum_x = sum(v.x, v.used); 
    double sum_y = sum(v.y, v.used); 
    double sum_2_x = sum_2(v.x,v.used); 
    double sum_2_y = sum_2(v.y,v.used); 
    double sum_xy = cross_sum(v); 

    double delta = v.used * sum_2_x - pow(sum_x,2); 


    m = (v.used* sum_xy - sum_x*sum_y)/delta; 

    q = (sum_2_x * sum_y - sum_x * sum_xy)/delta; 

} 


double scarto_xy (double x[], double y[], double x_m, double y_m){

    double ss = 0; //somma scarti 
    for(int i = 0; i < v.used; i++){
        ss = ss + (x[i]-x_m)*(y[i]-y_m)
    }

    return ss; 
}



*/


double retta_min_quad (points_array v,double & m, double& q){
    double x_m, y_m; 
    double m, q;
    baricentri(v, x_m, y_m); 
    
    m = scarto_xy(v,x_m,y_m)/scarto_2(v,x_m,0,1); 
    q= y_m - m*x_m; 

}



double std_gaussian (double z){
    double C = 1/sqrt(2*PI); 
    double exp = - pow(z,2)/2; 
    return C*pow(e,exp); 
}

double int_gaussian (double mu, double sigma, double x, int k){
    double z_0 = abs(mu - x)/sigma; 
    return int_ril(k,0,z_0,std_gaussian); 
}

/*double gauss_int (double z_0,int k){

    double P=0; 
    double z; 
    double C = 1/sqrt(2*PI); 
    double exp; 
    for(int c= 0; c < k; c++){
        z= randunif(0,z_0); 
        exp = - pow(z,2)/2; 
        P = P + C*pow(e,exp); 
    }

    return P*z_0/k; (se non funziona, metti 1.42)
}*/

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