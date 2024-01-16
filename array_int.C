
#include "array_int.h"

//funzioni specifiche al tipo di dato

bool readdata(ifstream& file_in, int &rdato){
   
   
   int appo; // appoggio

   file_in >> appo;

   if(file_in.eof() || file_in.fail()){
      return false; //non ho potuto leggere il dato
   }
   else{
      
      rdato = appo; // carico il dato su "dato" tramite un riferimento a dato 
      
      return true;//il dato è stato caricato
   }


}

bool confronto(int a,int b){ 
    if (a >= b){
        return true; 
    }

    return false; 
}

bool chiave(int el, int key){
    if(el == key){
        return true; 
    }
    return false; 
}

void printdata(ofstream& file_out, int rdato){
    file_out << rdato << endl;  
}

void printdata(int rdato){
    cout << rdato << endl;  
}

//funzioni di supporto

void merge(int v[], int low, int mid, int high) { //(per mergesort)

    int l,r,i,k; 
    l = low; //indicizza l'array di sinistra
    r = mid +1; // indicizza l'array di destra
    i = 0; //indicizza l'array d'appoggio
    // k indicizza i residui
    
    int * app; //array di appoggio

    app = new int [high - low + 1]; 

    while (l <= mid && r <= high){ //non ho esaurito nessuno dei sottovettori
        if(confronto(v[l],v[r])){  //WARNING: confronto è settata per decrescente
            app[i]=v[l]; 
            l++; 
        } else {
            app[i]=v[r]; 
            r++; 
        }
        i++; 
    }
    if(l > mid){ //ho finito l'array di sinistra
        for(k = r; k <= high; k++ ){
            app[i] = v[k]; 
            i++; 
        }
    } // ho finito l'array di destra 
    else{
        for(k = l; k <= mid; k++ ){
            app[i] = v[k]; 
            i++; 
        }
    }
    
    memcpy((void *)( v + low), (const void *) app, (high - low + 1)*sizeof(int));
    

    delete [] app; 
    app = NULL;  
}

int resize (arr_int * v, int newdim){

    int * appo; //appoggio

    if(newdim == v->size){
        cout << "No need to perform operation. New declared size matches original size" << endl;
        return 0;  
    }else if(newdim < v->used){ //restringo array
        v->used = newdim; //mi servono solo questi
    } //else: allargo array 

    //paf("data_backup.dat", v.raw, v.size); //crea un backup dei dati su file

    v->size = newdim; 
    
    appo = new int [newdim]; //alloco un array di appoggio

    if(appo == NULL){
        cout << "Errore in allocazione."; 
        return -1; 
    }

    
    memcpy(appo, v->raw, sizeof(int)*v->used); // copia v.used membri di v sull'appoggio

    //paf("data.backup.dat",appo, newdim); //crea un backup dei dati su file



    delete [] v->raw; 
    v->raw = appo; // ora v.raw è un alias di appo 

    return 0; 

}


//inizializzazione


void initialize (arr_int * v){
    v-> size = 0; 
    v -> used = 0; 
    v-> raw = NULL; 

    return; 
}

void initialize (arr_int * v,int d){
    v-> size = d; 
    v -> used = 0; 
    v-> raw = new int [d]; 

    return; 
}

int initialize(char nomefile [], arr_int * v){

    ifstream file_in; 
    
    bool status = true; 
    int appo; 
    int errcode; 
    
    file_in.open(nomefile); 
    
    if (file_in.fail()){
        return -1; //errore di apertura file
    }

    v->raw = new int[dim0]; 
    if (v->raw == NULL){
        return -2; // errore di allocazione
    }
    v->used =0; 
    v->size = dim0; 
 
    status = readdata(file_in,appo); //carica, se c'è, il dato
    while (status == true){
        if(v->used == v->size) {
            errcode = resize(v,v->size + incr); 
            if (errcode != 0){
                return -1; //errore di allocazione 
            }
        }
        v->raw[v->used] = appo; 
        status = readdata(file_in,appo); 
        v->used++; 
    }
    
    resize(v,v->used); 
    return 0; 
     
}

void initialize(int a [], int used, arr_int * v){ 
    v ->used = v->size = used; 
    v->raw = a; 
}
//stampa

void printarray(char nomefile[], arr_int v){
    ofstream file_out;
    char check; 
    cout << "Vuole riscrivere il file? [y/n]" << endl;
    cin >> check; 
    if(check == 'y' ){
        file_out.open(nomefile); 
    }else{
        file_out.open(nomefile, ios_base::app); 
    }
    for(int k=0; k < v.used; k++ ){
        printdata(file_out, v.raw[k]); 
    }
}

void printarray(arr_int v){
    for(int k=0; k < v.used; k++ ){
        printdata( v.raw[k]); 
    }
    return; 
}; 


void printstats (arr_int v){
    cout << "size " << v.size << endl; 
    cout << "used " << v.used << endl; 
    cout << "raw " << v.raw << endl; 

} 

void printstats(char filename[],arr_int v){
    ofstream file_out; 
    file_out.open(filename); 
    file_out << "size " << v.size << endl; 
    file_out << "used " << v.used << endl; 
    file_out << "raw " << v.raw << endl; 
}


//gestione elementi: 

//inserimento

void insert (arr_int * v, int el ){ //inserisce elemento in fondo
    if (v->used == v-> size){
        resize(v,v->size + incr); 
    }
    v->raw[v->used] = el; 
    v->used++; 
    return; 
}

void insert (arr_int * v, int el, int where){ //inserisce elemento in posizione where
    if(where < 0 || where >= v->used){
       cout << "(Operazione non possibile, indice fuori dal range)" << endl; 
         return; 
    }
    if (v->used == v-> size){
        resize(v,v->size + incr); 
    }
    for(int k=v->used; k > where; k--){
        v->raw[k]=v->raw[k-1]; 
    }
    v->raw[where] = el; 
    v->used++; 

    return; 
}

//sostituzione-scambio

void replace (arr_int *v, int el, int where){ //sostituisce un elemento con uno nuovo
    if(where < 0 || where >= v->size){
       cout << "(Operazione non possibile, indice fuori dal range)" << endl; 
         return; 
    }

    v->raw[where]=el;
    return; 
}

void swap(arr_int *v, int i1, int i2){//scambia due elementi
    if(i1 < 0 || i1 >= v->size || i2 < 0 || i2 >= v->size){
       cout << "(Operazione non possibile, indice fuori dal range)" << endl; 
         return; 
    }
    int appo; 
    appo = v->raw[i1]; 
    v->raw[i1]= v->raw[i2]; 
    v->raw[i2]=appo; 
    return; 
}

//eliminazione 

void delswap(arr_int * v, int where) { //elimina el array scambiandolo con l'ultimo
    if (where < 0 || where > (v->used - 1)){
            cout << "(Eliminazione non possibile, indice fuori dal range)" << endl; 
            return ; 
    }

    replace(v,v->raw[v->used -1],where); 
    v->used = v->used -1; 
    return ; 
}
void delshift(arr_int * v,  int where) { //elimina el array spostando tutto indietro di 1

     if (where < 0 || where >= (v->used - 1)){
        cout << "(Eliminazione non possibile, indice fuori dal range)" << endl;
     }
 
    for (int c = where; c < (v->used - 1) ; c++){
        v->raw[c]=v->raw[c+1]; 
    }

    v->used = v->used -1; 

}


//fusione di due array

void merge (arr_int a, arr_int b, arr_int * ab){
    ab->size = a.used + b.used; 
    ab->used = 0; 
    ab->raw = new int [ab->size]; 

    for(int k= 0; k < a.used; k++){
        ab->raw[k]= a.raw[k]; 
        (ab->used)++; 
    }
    for(int k=0; k < b.used; k++){
        ab->raw[a.used + k]= b.raw[k]; 
        ab->used++; 
    }

    return; 

}
//ricerca e ordinamento

int peek(arr_int *v, int where){ //restituisce elemento in posizione where 
    return v->raw[where]; 
}

int searchkey(arr_int * v, int key){ //ricerca elemento nell'array data una chiave

    for(int i = 0; i < v ->used; i++){
        if(chiave(v->raw[i], key)){ 
            return i; //ha trovato l'elemento, ora riporta la sua posizione
        }
    }

    return -1; //l'elemento non c'è 
}


void mergesort(int v [], int low, int high){//ordina array (settata per decrescente)
    int mid; 
    if (low < high){  
        mid = (high +low)/2; 
        mergesort(v,low, mid);
        mergesort(v,mid + 1, high);  
        merge(v,low, mid, high); 
    }
}

void mergesort(arr_int * v){ //chiama mergesort
    mergesort(v->raw,0, v->used - 1); 
}


//massimo e minimo 


int amax (arr_int v, int * p_max){
    int max; 
    max = v.raw[0]; 
    *p_max = 0; 


    for(int k = 1; k < v.used; k++){
        if(v.raw[k]> max){
            max = v.raw[k]; 
            *p_max = k; 
        }
    }

    return max; 
}

int amin (arr_int v, int * p_min){
    int min; 
    min = v.raw[0]; 
    *p_min = 0; 

    for(int k = 0; k < v.used; k++){
        if(v.raw[k]< min){
            min = v.raw[k]; 
            *p_min = k; 
        }

    }

    return min; 
}


//copia array

void deepcopy (arr_int v, arr_int * v_cp){

    v_cp->size = v.size;
    v_cp->used=v.used; 

    v_cp->raw = new int [v.size];
    if(v_cp->raw == NULL){
        v_cp->size = -1; //segnale di problemi
        return; 
    }
    
    memcpy(v_cp->raw,v.raw,v.used*sizeof(int)); 

    return; 
}


//eliminazione contenitore

void dispose(arr_int *v){
    delete [] v->raw; 
    v ->raw = NULL; 
}