#include <iostream> 
#include <fstream> 
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/libArray.h"
#include "/home/studenti/elisa.frigerio5/informatica_lab_23_24/code-sharing/libstat.h"

using namespace std; 


struct sfera{
    float diam; 
    char col; 
}; 

void printsfere(char nomefile[], sfera * rs, int da, int a);

int readdb (char nomefile[], sfera rs [], int size  );  //carico valori int su array da file di tipo uniforme , restituisco numero effettivo

int main (){

    float nc;// appoggio diam
    char cc;  // appoggio colore
    int c=0; // contatore 
    sfera * rs; // puntatore per array sfere

    
    char nomefile[]= "/home/studenti/elisa.frigerio5/informatica_lab_23_24/LabInfo_2023_24/Lab09/sfere.dat";
    ifstream file_in; 

    file_in.open(nomefile);
    if(file_in.fail()){
        cout << "ERROR. FILE NOT FOUND. :-( " << endl; 
        return -1; 
    }

    file_in >> nc; //appoggio diametro
    file_in >> cc; //appoggio colore

    while (!(file_in.eof())){ 
    c++; 
    file_in >> nc; 
    file_in >> cc; 

    }

    cout << "Il numero di dati e': " << c << endl; 

    rs = new sfera [c]; 

    file_in.close(); 

    readdb(nomefile, rs , c);     

    cout << " Ci sono " << c << " sfere" << endl; 

    printsfere("output.dat", rs, 0,2); 
    printsfere("output.dat", rs, c-3,c-1); 


    return 0; 
}


void printsfere(char nomefile[], sfera * rs, int da, int a) {
    ofstream file_out; 
    file_out.open(nomefile,ios_base::app);
    for(int k =da; k <= a; k++){
        file_out << rs[k].diam << " | " <<  rs[k].col << endl; 
    }

}



int readdb (char nomefile[], sfera * rs, int size  ){ //carico valori int su array da file di tipo uniforme , restituisco numero effettivo
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