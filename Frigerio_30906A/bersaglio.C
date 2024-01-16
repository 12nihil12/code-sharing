#include "bersaglio.h"


void colpito (bersaglio & appo, float d, float & acc){
    float h; 

    h=2*(1-(d/10)); 

    acc = acc + h; 
 
    appo.c = appo.c - h; 



}




bool readbersaglio(ifstream &file, bersaglio & appo){
    
    if(file.eof() || file.fail()){
        return false; 
    }

    file >> appo.x;
    file >> appo.y;
    file >> appo.c; 

    if(appo.c>=0){
        appo.distr = false;
    } else{
        appo.distr = true; 
    }

    return true; 
}



int caricabersaglio(char nomefile[], arr_ber* pMyArray){

  //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   bersaglio appo;
   //Gestore flusso da file
   ifstream filein;

   //Variabile per controllare status stream
   bool status = true;

   //Pignoleria/igiene
   // (*pMyArray).size  = 0;
   pMyArray->size = 0;
   pMyArray->used = 0;
   pMyArray->raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }
   //NOTA: la funzione non gestisce l'errore: si limita a segnalarlo in uscita.

   status = readbersaglio(filein,appo);

   while(status == true){
      conta++;
      status = readbersaglio(filein,appo);
   }


   
   filein.close();
   filein.open(nomefile);


   
   pMyArray->raw = new bersaglio[conta];

   if(pMyArray->raw == NULL){

      return -2;

   }
   //NOTA: anche qui non gestiamo l'eccezione, ci limitiamo a segnalarla...

   pMyArray->size = conta;
   
   //N.B.: uso direttamente used per indicizzare l'array
   //quindi: non ho bisogno di inizializzare (gia` fatto sopra)

   for( ; pMyArray->used < conta - 1; pMyArray->used++){

      readbersaglio(filein, pMyArray->raw[pMyArray->used]);
      //NOTA: ignoro il valore restituito...
   }

   filein.close();

   //Dati caricati correttamente nella variabile esterna
   return 0;

}



bool printbersaglio(ofstream &file, bersaglio appo){
    file << appo.x << " " << appo.y << "  | " << appo.c ;
    if(appo.c>=0){
        file << " non distrutto" << endl; 
    } else{
        file << " distrutto" << endl; 

    }


}

bool printbersaglio(bersaglio appo){
    cout << appo.x << " " << appo.y << "  | " << appo.c ;
    if(appo.c>=0){
        cout << " non distrutto" << endl; 
    } else{
        cout << " distrutto" << endl; 

    }


}

void stampaarrber(arr_ber v, char nomefile []){

    ofstream file; 
    file.open(nomefile); 

   for(int i=0; i<v.used; i++)
      printbersaglio(file,v.raw[i]);

}
