
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib> 
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/libArray.h"
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/libstat.h"
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/librandom.h"


#define N 1000 //punti per rilevazione
#define M 200 //numero rilevazioni


int main (){



    double ri [M]; 
    double ra [M];
    ofstream file_out;  
    file_out.open("check1.txt"); 

    seedset(); 

    for (int m=0; m < M; m++){
        ri[m] = int_ril(N,0,2); 
        ra[m] = ril_area(N,0,2); 
        file_out << "area f(x) " << ri[m] << endl; 
        file_out << "area prop " << ra[m] << endl; 

    }

    cout << "media f(x) " << media(ri, M) << endl; 
    cout << "media prop (restituisce il modulo)" << media(ra,M) << endl; 
    
    cout << "dv f(x) " << devstd(ri, M) << endl; 
    cout << "dv prop " << devstd(ra,M) << endl; 



    return 0; 

}

