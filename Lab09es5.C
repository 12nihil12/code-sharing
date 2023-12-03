// funziona ma i dati non sono nello stesso ordine rispetto al file di origine

#include <iostream>
#include <fstream>

using namespace std;


struct sfera{ 
    float diam;
    char colore; 
 };

sfera* caricaInteriFile(char nomefile[], int& quanti){
    sfera* file = NULL;
    float a;
    char b;
    ifstream file_in;
    file_in.open(nomefile);
    if(file_in.fail()){
        quanti = -1;
        return NULL;
    }
    
    file_in>>a >>b;
    while(!file_in.eof()){
        quanti++;
        file_in>>a >> b;

    }
    file_in.close();

    file = new sfera[quanti];
    if(!file){
        quanti = -2;
        return NULL;
    }

    file_in.open(nomefile);
    if(file_in.fail()){
        quanti = -3;
        return NULL;
    }
    
    for(int i=0; i<quanti; i++){
        file_in>> file[i].diam >> file[i].colore;
    }
    file_in.close();




    return file;
};


void scremaSfera(sfera dati[], int dim, int& nuovadim);
void eliminaSwap(sfera v[], int pos, int ndati);

int main(){
    int count = 0;
    sfera* v = NULL;
    int newdim = 0;


    char nome[] = "sfere.dat";
    v = caricaInteriFile(nome, count);

    cout << endl<<"Numero dati: "<<count;
    

    scremaSfera(v, count, newdim);
    cout<<endl<<newdim;
    for(int i=0; i<newdim; i++){
        cout<<endl<< v[i].diam <<v[i].colore;
    }
    
    delete []v;
    v = NULL;
    count = 0;
    return 0;
}

void scremaSfera(sfera dati[], int dim, int& nuovadim){
    char lettera;
    nuovadim = dim;
    for(int i=0; i<nuovadim; i++){
        lettera = dati[i].colore;
        while(dati[nuovadim-1].colore == 'g'){
            nuovadim--;
        } 
        if(dati[i].colore == 'g'){
            eliminaSwap(dati, i, nuovadim);
            nuovadim--;

        }
    }
}


void eliminaSwap(sfera v[], int pos, int ndati){

   if(pos >=0 and pos < ndati){

      v[pos] = v[ndati-1];

   }
   else{
      cout << endl << "Eliminaswap: posizione fuori range!\n:  "<<pos;  
   }
}
