
#include "libArray.h" 

//STAMPA: 

void paf(int v[], int used) { //stampa array sapendo quanti valori ci sono

    ofstream file_out; 
    file_out.open("output.txt"); 
    
    for (int c=0; c < used; c++ ){
        file_out << v[c]<< endl;
    }

    file_out.close(); 
}

void paf(float v[], int used) { //stampa array sapendo quanti valori ci sono

    ofstream file_out; 
    file_out.open("output.txt"); 

    for (int c=0; c < used; c++ ){
        file_out << v[c]<< endl;
    }

    file_out.close(); 
}

void paf(char v[], int used) { //stampa array sapendo quanti valori ci sono

    ofstream file_out; 
    file_out.open("output.txt"); 
    
    for (int c=0; c < used; c++ ){
        file_out << v[c]<< endl;
    }

    file_out.close(); 
}

void print (int v[], int used) { //stampa array sapendo quanti valori ci sono

    for (int c=0; c < used; c++ ){
        cout << v[c]<< endl;;
    }
}
void print (float v[], int used) { //stampa array sapendo quanti valori ci sono

    for (int c=0; c < used; c++ ){
        cout << v[c]<< endl;
    }
}
void print (char v[], int used) { //stampa array sapendo quanti valori ci sono

    for (int c=0; c < used; c++ ){
        cout << v[c]<< endl;
    }
}


//RIEMPIMENTO

void fill0(int v[],int size){ //inizializza un contatore array a 0
    for (int c = 0; c < size; c++){
    v[c] = 0; 
    }
}

void fill (int v[], int size){ //rempio array int
    for (int c = 0; c < size; c++){
    cin >> v[c]; 
    }
    return; 
}
void fill (float v[], int size){ //rempio array float
    for (int c = 0; c < size; c++){
    cin >> v[c]; 
    }
    return; 
}
void fill (char v[], int size){ //rempio array char
    for (int c = 0; c < size; c++){
    cin >> v[c]; 
    }
    return; 
}

int load (int v[], int size){ //carico valori int su array, restituisco numero effettivo
    bool check = 1;
    int used=0., c=0;  
    cout << "Prema 1 se vuole inserire un dato, 0 altrimenti.";
    while (check && c < size){
        cin >> v[c]; 
        c++; 
        used++; 
    }
    
    return used; 
}
int load (float v[], int size){ //carico valori float su array, restituisco numero effettivo
    bool check = 1;
    int used=0., c=0;  
    cout << "Prema 1 se vuole inserire un dato, 0 altrimenti.";
    while (check && c < size){
        cin >> v[c]; 
        c++; 
        used++; 
    }
    
    return used; 
}
int load (char v[], int size){ //carico valori char su array, restituisco numero effettivo
    bool check = 1;
    int used=0., c=0;  
    cout << "Prema 1 se vuole inserire un dato, 0 altrimenti.";
    while (check && c < size){
        cin >> v[c]; 
        c++; 
        used++; 
    }    

    
    return used; 
}

int fff (char nomefile[], int arr[], int size  ){ //carico valori int su array da file di tipo uniforme , restituisco numero effettivo
    int c = 0;  

    ifstream file_in; 

    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR: FILE NOT FOUND (not a system error. Check the path)" << endl; 
        return -1; 
    }

    int appo; 

    file_in >>  appo; 
    while (!file_in.eof() && c < size){
        arr[c] = appo; 
        c++; 
        file_in >>  appo;  
        
    }

    file_in.close(); 

    return c; //used
}

int fff (char nomefile[], float arr[], int size  ){ //carico valori float su array da file di tipo uniforme , restituisco numero effettivo
    int c = 0;  

    ifstream file_in; 

    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR: FILE NOT FOUND (not a system error. Check the path)" << endl; 
        return -1; 
    }

    float appo; 

    file_in >>  appo; 
    while (!file_in.eof() && c < size){
        //cout << "c" << c; 
        arr[c] = appo; 
        //cout << " | " << arr[c] << endl; 
        c++; 
        file_in >>  appo;  
        //cout << "c" << c << "appo" << appo; 
        
    }

    //cout << "c =" << c    << endl; 

    file_in.close(); 
    return c ; //used
}

int fff (char nomefile[], char arr[], int size  ){ //carico valori int su array da file di tipo uniforme , restituisco numero effettivo
    int c = 0;  

    ifstream file_in; 

    file_in.open(nomefile); 

    if(file_in.fail()){
        cout << "ERROR: FILE NOT FOUND (not a system error. Check the path)" << endl; 
        return -1; 
    }

    char appo; 

    file_in >>  appo; 
    while (!file_in.eof() && c < size){
        arr[c] = appo; 
        c++; 
        file_in >>  appo;  
        
    }


    file_in.close(); 
    return c; //used
}

//MINIMO E MASSIMO

int posmin (int v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int min = i;   // i indica da che posizione cerco il minimo
    for (int c=i; c < size; c++){
        if(v[c] < v[min]){
            min = c; 
        }
    }
    
    return min; 
}
int posmin (float v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int min = i;   
    for (int c=i; c < size; c++){
        if(v[c] < v[min]){
            min = c; 
        }




    }
    
    return min; 
}
int posmin (char v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int min = i;   
    for (int c=i; c < size; c++){
        if((int)v[c] < (int)v[min]){
            min = c; 
        }




    }
    
    return min; 
}

int posmax (int v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int max= i;   
    for (int c=i; c < size; c++){
        if(v[c] > v[max]){
            max = c; 
        }
    }
    
    return max



; 
}
int posmax (float v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int max= i;   
    for (int c=i; c < size; c++){
        if(v[c] > v[max]){
            max = c; 
        }
    }
    
    return max; 
}
int posmax (char v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int max= i;   
    for (int c=i; c < size; c++){
        if((int)v[c] > (int)v[max]){
            max = c; 
        }
    }
    
    return max; 
}

//ORDINAMENTO

void swap(int v[], int i, int j, int size){ // swap elementi int
    if (i < 0 || i > size || j < 0 || j > size){
        cout << "Indici fuori range" << endl; 
        return; 
    }
    int jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}
void swap(float v[], int i, int j, int size){ // swap elementi float
    if (i < 0 || i > size || j < 0 || j > size){
        cout << "Indici fuori range" << endl; 
        return; 
    }
    float jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}
void swap(char v[], int i, int j, int size){ // swap elementi char
    if (i < 0 || i > size || j < 0 || j > size){
        cout << "Indici fuori range" << endl; 
        return; 
    }
    float jolly = v[i]; 
    v[i]= v[j]; 
    v[j]= jolly; 
    
    return; 
}


void order(int v[], int size){ // ordinamento array int 
    for (int k = 0; k < size -1; k++){
        //cout << "k=" << k; 
        int min = posmin(v, k, size );
        //cout << "min: " << A[j]; 
        swap(v, k, min, size);
        //cout << "scambio " << A[k] <<endl; 
    }
    
}
void order(float v[], int size){ //ordinamento array float
    for (int k = 0; k < size -1; k++){
        //cout << "k=" << k; 
        int min = posmin(v, k, size);
        //cout << "min: " << A[j]; 
        swap(v, k, min, size);
        //cout << "scambio " << A[k] <<endl; 
    }
    
}
void order(char v[], int size){ //ordinamento array char
    for (int k = 0; k < size -1; k++){
        //cout << "k=" << k; 
        int min = posmin(v, k, size);
        //cout << "min: " << A[j]; 
        swap(v, k, min, size);
        //cout << "scambio " << A[k] <<endl; 
    }
    
}


// ELIMINAZIONE ELEMENTO

int delswap(int v[], int used,  int where) { //elimina el array scambiandolo con l'ultimo
if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
}

v[where]=v[used -1]; 

    return used -1; 
}
int delswap(float v[],  int used,  int where) { //elimina el array scambiandolo con l'ultimo
if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
}

v[where]=v[used -1]; 

    return used -1; 
}
int delswap(char v[], int used,  int where) { //elimina el array scambiandolo con l'ultimo
if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
}

v[where]=v[used -1]; 

    return used -1; 
}


int delshift(int v[],  int used,  int where) { //elimina el array spostando tutto indietro di 1

     if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
     }
 
    for (int c = where; c < (used - 1) ; c++){
        v[c]=v[c+1]; 
    }

     return used - 1; 

}
int delshift(float v[], int used,  int where) { // elimina el raay spostando tutto indietro di 1

     if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
     }
 
    for (int c = where; c < (used - 1) ; c++){
        v[c]=v[c+1]; 
    }

     return used - 1; 

}
int delshift(char v[],  int used,  int where) { // elimina el raay spostando tutto indietro di 1

     if (where < 0 || where >= (used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
        return used; 
     }
 
    for (int c = where; c < (used - 1) ; c++){
        v[c]=v[c+1]; 
    }

     return used - 1; 

}
