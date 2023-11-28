#include <iostream> 
#include "libArray.h"

using namespace std; 


struct arrint {
int size; //dimensione array
int used; //numero elementi usati
int * raw; //array
};


arrint caricaintfile (char nomefile[],int& errcode); 

int main() {

arrint vect; 
int errore = -1; 

vect.raw = NULL; 
vect.size = vect.used = 0; 

vect = caricaintfile ("interi.dat", errore); 

if(errore == 1){
    cout << "Problemi con lo stream. Controlla dove hai messo il file" << endl; 
    return 0; 
} else if (errore == 2){
    cout << "Mah, non so proprio che sia successo" << endl; 
    return 0; 
} else if (errore != 0) {
    cout << "Il programma non va. Fantastico" << endl; 
    return 0; 
}

cout << vect.raw << endl; 
cout << vect.size << endl; 
cout << vect.used << endl; 

paf("copy.dat", vect.raw, vect.used); // output di controllo 



delete [] vect.raw; 
vect.raw = NULL; 
vect.size = vect.used = 0; 

return 0; 


}

arrint caricaintfile (char nomefile[],int& errcode){ 
        ifstream file_in; 
        file_in.open(nomefile); 
        arrint rarr; 

        rarr.raw = NULL; 
        rarr.size = rarr.used = -1; 

        if(file_in.fail()){
            errcode = 1; //problemi con lo stream
            return rarr; 
        }

        int appo; 
        int c = 0; 

        file_in >> appo; 

        while (!file_in.eof())
        {
            c++; 
            file_in >> appo; 
            
        }

        file_in.close(); 

        rarr.size = rarr.used = c; 
        c=0; 


        //cout << "ndati = " << rarr.size << endl; 

        rarr.raw = new (nothrow) int [c]; 
        if (rarr.raw == NULL){
            errcode = 2; // problemi con l'allocazione
        }

        file_in.open(nomefile); 

        file_in >> appo; 

        while (!file_in.eof() )
        {
            rarr.raw[c] = appo;  
            //cout << c << " | " << rarr.raw[c] << endl; 
            c++; 
            file_in >> appo; 
            
        }

         

        file_in.close(); 

        errcode = 0; 

        cout << "end"; 
    return rarr; 

}
