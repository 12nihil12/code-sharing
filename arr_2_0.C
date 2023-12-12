#include "arr_2_0.h"


int resize_arr (arr_int & myA, int newdim){

    int * appo; //appoggio

    if(newdim == myA.size){
        cout << "No need to perform operation. New declared size matches original size" << endl;
        return -1;  
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

bool leggiDato(ifstream& file, int &rdato){
   
   //Variabile di appoggio
   int appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo;

   //Controllo stato dello stream: se in fail() o lo stream è in eof, restituisco false
   //in questo modo il programma chiamante potrà accorgersi che il dato manca.
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      //Il dato effettivamente c'e`. Lo salvo nella variabile "che esporta il valore dalla funzione"
      rdato = appo;
      //Tutto a posto: il dato c'e`: restutuisco true
      return true;
   }


} 


int up_file (char nomefile [], arr_int& myA){

    ifstream file_in; 
    
    bool status = true; 
    int appo; 
    int c = 0;
    int dim0 = 20; 
    int incr = 10; 
    //int * v; 

    
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
 
    status = leggiDato(file_in,appo);  
    while (status == true)
    {
        if(myA.used == myA.size) {
            resize_arr(myA,myA.size + incr); 
        }
        myA.raw[myA.used] = appo; 
        //cout << "c: " << myA.used << " value " << appo << endl; 
        status = leggiDato(file_in,appo); 
        myA.used++; 
    }
    
    return 0; 
     
}