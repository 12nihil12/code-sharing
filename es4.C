#include <iostream>
#include <fstream>
#include <cmath>
#include "libArray.h" 

using namespace std; 


bool issquare(int n); 
bool isprime (int n); 
int delswap3(int v[], bool ip[], bool is[], int used,  int where, int *);
void print3f (char nomefile[],int v[], bool is[], bool ip[], int used); 

int main(){


    char nomefile[] = "interi.dat"; 
    int c = 0; 
    ifstream file_in; 
    ofstream file_out; 
    int * v = NULL; 
    bool * ip = NULL;
    bool * is = NULL; 
    int dimeff; 


    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR 404. NOT FOUND. :-( "; 
        return -1; 
    }

    int appo; 

    file_in >> appo; 
    while(!file_in.eof()){
        c++; 
        file_in >> appo; 
    }

    file_in.close(); 


    cout << "c: " << c; 

    v = new int [c]; 

    fff(nomefile, v , c); 

    
    cout << "c: " << c; 

    paf("arrcheck.dat", v, c); 

    is = new bool [c]; 
    ip = new bool [c]; 

    for (int k = 0; k < c; k++){
        is[k] = false; 
        ip[k] = false; 
    }

    for(int k=0; k<c ; k++){
        ip[k] = isprime(v[k]);
        is[k] = issquare(v[k]);
    }


    print3f("check1.dat", v, is, ip, c); 

    cout << c; 

    int used = c; 

    for(int k=0; k<c ; k++){
        while((!ip[k] && !is[k]) && used > 0){
            used=delswap3(v,ip,is,used, k, &dimeff); 
        } 
    }
    
    cout << "I valori rimasti sono " << dimeff << endl; 


    
    print3f("check2.dat", v, is, ip, c); 
    

    file_out.open("risultati.dat"); 

    for (int k=0; k< dimeff; k++ ){
        if(ip[k]){
            file_out << v[k] << " | primo" << endl; 
        }else{
            file_out << v[k] << " | quadrato perfetto" << endl; 

        }
    }


    file_out.close();
    delete [] v; 
    v = NULL; 
    delete [] ip; 
    ip = NULL; 
    delete [] is; 
    is = NULL; 

    return 0; 
}


bool isprime (int n){ 
    for ( int b = 2; b < n; b++){
        if(n%b == 0){

            return false;
        }
    }
    return true; 
}


bool issquare(int n){

    float r= sqrt(n); 

    if(pow((int)r,2) == n){
        return true; 
    }

    return false; 
}


int delswap3(int v[], bool ip [], bool is[], int used,  int where, int * dimeff) { 

ofstream file_check; 
file_check.open("delswap3_output.txt", ios::app); 


if(file_check.fail()){
    return -1; 
}

if (where < 0 || where >= used){
    *dimeff = used; 
    return -1; 
}

file_check << "ho eliminato il numero : " << v[where]; 
if(!ip[where]){
    file_check << " non primo, ";
}
if(!is[where]){
    file_check << " non un quadrato perfetto";
}
file_check << " in posizione " << where << endl; 

v[where]=v[used -1]; 
ip[where]= ip[used - 1];
is[where]= is[used -1]; 

file_check << "ora in posizione" << where << " c'è " << v[where]; 
if(ip[where]){
    file_check << " primo, ";
}
if(is[where]){
    file_check << " un quadrato perfetto";
}
file_check << endl;  
file_check << "Il mio array ha ora " << used -1 << " valori" << endl; 

    file_check.close(); 
    return used -1; 
}


void print3f (char nomefile[],int v[], bool is[], bool ip[], int used) { //stampa array sapendo quanti valori ci sono

    ofstream file_out; 
    file_out.open(nomefile); 
    
    file_out <<"numero | s | p | " << endl; 

    for (int c=0; c < used; c++ ){
        file_out << v[c] << "       | " << is[c] << " | " << ip[c] << endl; 
    }

    file_out.close(); 
}

