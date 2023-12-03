//controllo output errore con switch

#include <iostream>
#include <fstream>

using namespace std;

struct myArrayInt{ 
    int size; //Dimensione dell'array 
    int used; //Numero elementi array usati 
    int *raw; //Indirizzo di inizio dell'array 
    };


myArrayInt caricaInteriFile(char nomefile[], int& errore){
    myArrayInt file;
    //inizzializzo l'array
    file.used = 0;
    file.size = 0;
    file.raw = NULL;
    int a;

    ifstream file_in;
    file_in.open(nomefile);//apertura file 1
    if(file_in.fail()){
        errore = -1;
    }
    
    file_in>>a;
    while(!file_in.eof()){
        file.size++;
        file_in>>a;

    }
    file_in.close();

    file.raw = new int[file.size];//assegnazione array 1
    if(!file.raw){
        errore = -2;
    }

    file_in.open(nomefile);//apertura file 2
    if(file_in.fail()){
        errore = -3;
    }
    
    for(int i=0; i<file.size; i++){
        file_in>> file.raw[i];
        file.used++;
    }
    file_in.close();

    return file;
};



int main(){
    int errore = 0;

    myArrayInt v;
    v.used = 0;
    v.size = 0;
    v.raw = NULL;


    char nome[] = "interi.dat";
    v = caricaInteriFile(nome, errore);


    //output errore
    switch(errore){
        case 0:  cout<<endl<<"tutto ok"; break;
        case -1: cout<<endl<<"errore apertura file 1"; break;
        case -2: cout<<endl<<"errore assegnazione array 1"; break;
        case -3: cout<<endl<<"errore apertura file 2"; break;
    }

    //stampa dati
    cout << endl<<"Numero dati: "<<v.used;
    for(int i=0; i<v.used; i++){
        cout<< endl<<v.raw[i];
    }

    delete []v.raw;
    v.raw = NULL;
    v.used = 0;
    v.size = 0;
    errore = 0;
    return 0;
}
