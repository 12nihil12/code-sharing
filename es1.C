#include <iostream>
#include <fstream>
#include <cmath>



using namespace std; 

int true1 (bool v[], int dim, int); 
int contaprimi(bool p[], int dim); 


int main (){

    char nomefile[] = "primi.dat";
    int N_max; 
    bool * geq = NULL; 

    ofstream file_out;  

    cout << "Salve, inserisca un numero" << endl; 

    cin >> N_max; 

    int dim = N_max + 1; 

    geq= new bool [dim]; 

    //order(nomefile, 9); controllo per inserimento libreria 
    //cout << nomefile; 

    geq[0]= false; 
    geq[1] = false; 
    for (int c= 2; c <= N_max; c++){
        geq[c]= true; 
    }


    int i1 = 0;
    

    for(int p = 2; p <= N_max; p++){
        i1 = true1(geq,N_max,p); 
        cout << i1 << endl; 
        if(i1 != 0){
            for (int k = 2; i1*k <= N_max; k++){
                geq[i1*k] = false; 
            }
        }
        
        
    }

    file_out.open(nomefile); 

    int np = contaprimi(geq, N_max); 

    file_out << "I numeri primi minori o uguali di " << N_max << " sono " << np << endl; 
    file_out << "La densità di numeri primi nell'intervallo 0-"<< N_max << " è " << (float)np/N_max << endl; 
    file_out << "I numeri primi trovati sono: " << endl; 


    for(int c = 2; c <= N_max; c++){
        if(geq[c]){
            file_out << c << endl; 
        }
    }
    
    
    file_out.close(); 

    delete [] geq; 
    geq = NULL; 
    


    return 0;
}



int true1 (bool p[], int dim, int start){ //ritorna il primo indice per cui v[i]= 1
    int c = start; 
    while(!p[c]){
        if(c == dim ){
            return 0; 
        }
        c++; 
    }

    return c; 
}


int contaprimi(bool p[], int dim){
    int cp=0; 
    for(int c = 2; c <= dim; c++){
        if(p[c]){
            cp++;
        }
    }
    
    return cp; 
}

