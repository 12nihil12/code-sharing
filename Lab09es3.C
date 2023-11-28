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

int main(){
    int count = 0;
    sfera* v = NULL;


    char nome[] = "sfere.dat";
    v = caricaInteriFile(nome, count);

    //stampa dati: numero dati, i primi e ultimi tre
    cout << endl<<"Numero dati: "<<count;
    for(int i=0; i<3; i++){
        cout<<endl<< v[i].diam <<v[i].colore;
    }
    for(int i=(count - 3); i<count; i++){
        cout<<endl<< v[i].diam <<v[i].colore;
    }
    
    delete []v;
    v = NULL;
    count = 0;
    return 0;
}
