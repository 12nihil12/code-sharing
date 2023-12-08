#include <iostream>
#include<cmath>
#include "../Librerie/libCaso.C"
#include "../Librerie/libreriaArray.C"
#include "../Librerie/libreria.C"


#define M 50


using namespace std;

struct puntoR2{
    double x;
    double y;
};
struct myArrayR2{ 
    int size; //Dimensione dell'array 
    int used; //Numero elementi array usati 
    puntoR2 *raw; //Indirizzo di inizio dell'array 
};


//const puntoR2 centro = {0.0, 0.0};

double randUniforme(double min, double max);
bool insideCircle(puntoR2, double);
double dist(puntoR2, double);
int countWithin(int, double );
double rilev(int n, double r);


int main(){

    double pi;

    pi = rilev(10000 , 100.); // scegliere numero di numeri generati per ogni rilevazione e il raggio del cerchio

    cout<<endl<<"pi = "<<pi;
    
    return 0;
}


bool insideCircle(puntoR2 p, double r){
    double distan = dist(p, 0.);
    if(distan <= r){ //per sapere se il punto e' all'interno del cerchio devo conoscre la sua distanza dal centro  //cosa cambia da < a <= ?
        return true;
    }
    else {
        return false;
    }
}

double dist(puntoR2 p, double n){
    double d;
    d = sqrt(pow(p.x ,2) + pow(p.y , 2));
    return d;
}

int countWithin(int n, double r)
{
    int num = 0;


    myArrayR2 v;
    v.used =0;
    v.size = 0;
    v.raw = NULL;

    v.raw = new puntoR2[n];
    if(v.raw == NULL){
        cout<<endl<<"errore assegnazione array";
        return -1;
    }
    v.size = n;


    //errore da qui in poi

    //creo i punti in maniera casuale
    for(int i=0; i<v.size; i++){
        v.raw[i].x = randUniforme(r,0.);
        v.raw[i].y = randUniforme(r,0.); 
        v.used++;
        if(insideCircle(v.raw[i], r)){//conto il num di punti all'interno del cerchio
            num++;
        }
    }
    


    delete []v.raw;
    v.used = 0;
    v.size= 0;

    return num;
}

double rilev(int n, double r){
    impostaSeme();//srand(time(NULL));

    double med, varianza , rile;

    myArrayInt conta;
    conta.size = conta.used = 0; conta.raw = NULL;

    conta.raw = new int[M];
    if(conta.raw == NULL){
        return -2;
    }
    conta.size = M;




    for(int i=0; i<M; i++){
        conta.raw[i] = countWithin(n, r); //conto solo i numeri all'interno del cerchio
        conta.used++;
    }

    med = media(conta.raw, conta.used);  //media del numero di punti all'interno del cerchio
    varianza = pow(2, devstdMed(conta.raw, conta.used, med));// deviazione standard conoscendo la media alla 2
    


    cout<<endl<<"varianza = "<<varianza;


    delete []conta.raw;
    conta.size = 0;
    conta.used = 0;

    rile = 4*((double)med/n); //rilevazione di pi

    return rile;
}
