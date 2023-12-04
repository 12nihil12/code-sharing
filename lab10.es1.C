
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include "C:/Users/user/Desktop/info_lab_uni/libtrans/libArray.h"
#include "C:\Users\user\Desktop\info_lab_uni\libtrans\libstat.h"
#include "C:\Users\user\Desktop\info_lab_uni\libtrans\random.h"

#define N 200 //punti per rilevazione
#define M 50 //numero rilevazioni
#define R 1 //raggio circonferenza

using namespace std;



struct puntoR2{ 
    double x; 
    double y; 
};


bool isInsideCircle(puntoR2 p, double r); 
int countwithin(int n, double r); 
double rilev(int n, double r); 


int main() {
    
    float _pi_; 
    float stdv, var; 
    float pi[M]; 
    ofstream file_out; 

    seedset(); 

    file_out.open("check.txt"); 
    file_out << "Hello world" << endl; 

    file_out.close();

    file_out.open("check.txt", ios_base::app); 

    for(int k = 0; k < M; k++){
        file_out << endl << "k | " << k << endl; 
        pi[k]=rilev(N,R); 
    }


    file_out.close(); 

    paf("pi_check.txt",pi, M); 



    _pi_ = media(pi,M); 

    stdv = devstd(pi,M); 

    var = pow(stdv,2); 

    cout << "Il valore di pi greco stimato e' " << _pi_ << endl; 
   cout << "La sua deviazione standard e' " <<stdv << endl; 
    cout << "La sua varianza e' " << var << endl; 


    return 0;
}


bool isInsideCircle(puntoR2 p, double r){

    if(pow(p.x,2)+pow(p.y,2) <= pow(r,2)){ //equazione della circonferenza 
        return true; 
    }

    return false; 
}

int countwithin(int n, double r){

    ofstream file_out; 

    file_out.open("check.txt", ios_base::app); 

    int c_i=0; //conta quanti punti cadono dentro la circonferenza

    puntoR2 a; 

    for(int k = 0;  k < n ; k++){
        a.x=randunif(0,r); //estrae una x a caso 
        //file_out << "x: " << a.x <<endl; 
        a.y=randunif(0,r); //estrae una y a caso
        //file_out << "y: " << a.y <<endl; 

        if(isInsideCircle(a,r)){ //controlla se è dentro
            c_i++; //conta quanti punti cadono dentro la circonferenza
            //file_out << c_i << endl; 
        }
    }

    
    file_out << "D = " << c_i << endl; 

    return c_i; 
}


double rilev(int n, double r){
    double pi; 
    int D; 
    ofstream file_out; 

    file_out.open("check.txt", ios_base::app); 

    
    D = countwithin(n, r); 


    pi = 4 *((double)D/n); 

    file_out << " pi: " << pi << endl; 

    return pi; 


}

