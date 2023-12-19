#include "arr_int_2_0.h"

//libreria di funzioni più complesse relative a array di interi




int resize_arr (arr_int & myA, int newdim){

    int * appo; //appoggio

    if(newdim == myA.size){
        cout << "No need to perform operation. New declared size matches original size" << endl;
        return 0;  
    }else if(newdim < myA.used){ //restringo array
        myA.used = newdim; //mi servono solo questi
    } //else: allargo array 

    paf("data_backup.dat", myA.raw, myA.size); //crea un backup dei dati su file

    myA.size = newdim; 
    
    appo = new int [newdim]; //alloco un array di appoggio



    if(appo == NULL){
        cout << "Errore in allocazione."; 
        return -1; 
    }


    memcpy(appo, myA.raw, 4*myA.used); // copia myA.used membri di myA sull'appoggio

    //paf("data.backup.dat",appo, newdim); //crea un backup dei dati su file



    delete [] myA.raw; 
    myA.raw = appo; // ora myA.raw è un alias di appo 

    return 0; 

}

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


int up_file (char nomefile [], arr_int& myA){

    ifstream file_in; 
    
    bool status = true; 
    int appo; 
    int errcode; 
    
    file_in.open(nomefile); 
    
    if (file_in.fail()){
        return -1; //errore di apertura file
    }

    myA.raw = new int[dim0]; 
    if (myA.raw == NULL){
        return -2; // errore di allocazione
    }
    myA.used =0; 
    myA.size = dim0; 
 
    status = readdata(file_in,appo); //carica, se c'è, il dato
    while (status == true){
        if(myA.used == myA.size) {
            errcode = resize_arr(myA,myA.size + incr); 
            if (errcode != 0){
                return -1; //errore di allocazione 
            }
        }
        myA.raw[myA.used] = appo; 
        status = readdata(file_in,appo); 
        myA.used++; 
    }
    
    return 0; 
     
}

int searchkey(arr_int & myA, int key){ //ricerca elemento nell'array data una chiave

    for(int i = 0; i < myA.used; i++){
        if(myA.raw[i] == key){
            return i; //ha trovato l'elemento, ora riporta la sua posizione
        }
    }

    return -1; //l'elemento non c'è 
}



void merge(int v[], int low, int mid, int high) {

    int l = low; //indicizza l'array di sinistra
    int r = mid +1; // indicizza l'array di destra
    int i = 0; //indicizza l'array d'appoggio
    int k; // indicizza i residui
    
    int * app; 

    app = new int [high - low + 1]; 

    while (l <= mid, r <= high){ // l'elemento di destra e` maggiore di quello di sinistra
        if(v[l]>= v[r]){
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
            app[i] = v[r]; 
            r++; 
        }
    } // ho finito l'array di destra 
    else{
        for(k = l; k <= mid; k++ ){
            app[i] = v[l]; 
            l++; 
        }
    }
    


    memcpy(v + low, (const void *) app, (high - low + 1)*sizeof(int)); 

    delete [] app; 
    app = NULL;  
}

void mergesort(int v [] , int low, int high){
    if (low < high){
        
        int mid = (high +low)/2; 
        mergesort(v,low, mid);
        mergesort(v,mid + 1, high);  
        merge(v,low, mid, high); 
    }
}