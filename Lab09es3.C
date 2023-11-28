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
    file_in>>a;
    while(!file_in.eof()){
        file_in>>a >> b;
        quanti++;
    }
    file = new sfera[quanti];
    file_in.close();
    file_in.open(nomefile);
    for(int i=0; i<quanti; i++){
        file_in>> file[i].diam >> file[i].colore;
    }
    file_in.close();




    return file;
}

int main(){
    int count = 0;
    sfera* v = NULL;


    char nome[] = "interi.dat";
    v = caricaInteriFile(nome, count);

    //stampa dati
    cout << endl<<"Numero dati: "<<count;
    
    delete []v;
    v = NULL;
    count = 0;
    return 0;
}
