#include <iostream>
#include <fstream>
#include <cmath>
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/libArray.h" 

using namespace std; 

int * filldatafile (char nomefile[], int& size);  //carico valori int su array da file di tipo uniforme , restituisco numero effettivo


int main (){

    char nomefile[]= "/home/studenti/elisa.frigerio5/informatica_lab_23_24/LabInfo_2023_24/Lab09/interi.dat"; 
    int ndati=0; 
    int * v = NULL; 

    v = filldatafile(nomefile, ndati); 

    cout << "dimensione: " << ndati << endl; 

    //for (int k=0; k < ndati; k++){
      //  cout << v[k];
    //}

    paf("copia.dat", v,ndati);

    delete [] v; 
    v = NULL; 
    return 0; 
}


int * filldatafile (char nomefile[], int& size){ //carico valori int su array da file di tipo uniforme , restituisco numero effettivo
    int c = 0;  
    int * rv = NULL;
    ifstream file_in; 

    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR: FILE NOT FOUND (not a system error. Check the path)" << endl; 
        size = -1; 
        return rv; 
    }

    int appo; 

    file_in >>  appo; 
    while (!file_in.eof() ){ 
        c++; 
        file_in >>  appo;  
        
    }

    file_in.close(); 

   size = c; 

    rv = new int [size]; 

    c=0; 

    file_in.open(nomefile); 


    file_in >>  appo; 
    while (!file_in.eof() && c < size){
        rv[c] = appo; 
        c++; 
        file_in >>  appo;  
        
    }

    file_in.close(); 

    return rv; //used
}

