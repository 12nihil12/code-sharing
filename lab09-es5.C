#include <iostream> 
#include <fstream> 
#include "libArray.h"

using namespace std; 

struct sfera{
    float diam; 
    char col; 
}; 

void printsfere(char nomefile[], sfera * rs, int da, int a);
int readdb (char nomefile[], sfera * rs , int size  );  
sfera * loadsfere (char nomefile[], int& size);
int delswapsfere(sfera * rs, int used,  int where, int& dimeff); 
void screamasfere (sfera * rs, int ndati, int& newdim); //swappa le gialle e le mette in fondo



int main (){

    sfera * sfere; // puntatore per array sfere
    char nomefile[]= "sfere.dat"; 
    int ndati; 
    int newdim; 
    ofstream file_out; 
    

    sfere = loadsfere(nomefile, ndati); 


    cout << " Ci sono " << ndati << " sfere" << endl; 

    screamasfere(sfere, ndati, newdim); 

    printsfere("output.dat", sfere, 0, newdim -1); // gli passo gli indici da a cui leggere

    file_out.open("output.dat", ios_base::app); 
    file_out << endl << "E ora le gialle " << endl; 
    file_out.close(); 
    printsfere("output.dat", sfere, newdim, ndati -1); // gli passo gli indici da a cui leggere


    return 0; 
}


void printsfere(char nomefile[], sfera * rs, int da, int a) {
    ofstream file_out; 
    file_out.open(nomefile,ios_base::app);
    for(int k =da; k <= a; k++){
        file_out << rs[k].diam << " | " <<  rs[k].col << endl; 
    }

}

int readdb (char nomefile[], sfera * rs, int size  ){ //una volta sapute quante sono carica le sfere sul vettore


    int c = 0;  

    ifstream file_in; 

    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR: FILE NOT FOUND (not a system error. Check the path)" << endl; 
        return -1; 
    }
    if(file_in.eof()){
        cout << "Empty file" << endl; 
        return 0; 
    }

    float apponum;
    char appocol; 

    file_in >>  apponum; 
    file_in >>  appocol; 
    while (!file_in.eof() && c < size){
        rs[c].diam = apponum; 
        rs[c].col = appocol; 

        c++; 
        file_in >>  apponum;  
        file_in >>  appocol;
    }


    file_in.close(); 
    return c ; //used
}


sfera * loadsfere (char nomefile[], int& size){

    float nc;// appoggio diam
    char cc;  // appoggio colore
    int c=0; // contatore 
    sfera * rs; // puntatore per array sfere
    ifstream file_in;

    file_in.open(nomefile);

    if(file_in.fail()){
        cout << "ERROR. FILE NOT FOUND. :-( " << endl; 
        size = -1; 
        return NULL; 
    }

    file_in >> nc; //appoggio diametro
    file_in >> cc; //appoggio colore

    while (!(file_in.eof())){ 
    c++; 
    file_in >> nc; 
    file_in >> cc; 

    }

    size = c; 

    cout << "Il numero di dati e': " << size << endl; 

    rs = new sfera [size]; 

    file_in.close(); 

    readdb(nomefile, rs, size ); 

    return rs; 
}



int delswapsfere(sfera * rs, int used,  int where, int& dimeff) { 

if (where < 0 || where >= used){
    dimeff = used; 
    return -1; 
}


    sfera appo; 
    appo = rs[where]; 
    rs[where]= rs[used -1];
    rs[used -1]=appo; 

    return used -1; 
}

void screamasfere (sfera * rs, int ndati, int& newdim){ //swappa le gialle e le mette in fondo
    int used = ndati; 
    for(int k= 0; k < ndati; k++){
        while(rs[k].col == 'g' && used > 0){
            used = delswapsfere(rs,used,k, newdim); 
        }
    }
    return; 
}


