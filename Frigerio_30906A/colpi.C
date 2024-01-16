#include "colpi.h"


int posmax (float v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int max= i;   
    for (int c=i; c < size; c++){
        if(v[c] > v[max]){
            max = c; 
        }
    }
    
    return max; 
}

int posmin (float v[], int i, int size){ //restituisce posizione elemento minimo array di (size) elementi a partire da i
    int min = i;   
    for (int c=i; c < size; c++){
        if(v[c] < v[min]){
            min = c; 
        }




    }    return 0; 

    
    return min; 
}

void segno(colpo & appo, float d){
    ofstream file_out; 
    file_out.open("check2.txt"); 
    if(d < 10){
        appo.hit = true; 
        file_out << "si" << endl; 
    } 
}

bool readcolpo(ifstream &file, colpo & appo){
    
    if(file.eof() || file.fail()){
        return false; 
    }

    file >> appo.theta >> appo.phi; 

    float G = (V*V)/9.81*sin(2*appo.theta); 

    appo.xf= G*cos(appo.phi); 
    appo.yf= G*sin(appo.phi); 

    appo.hit = false; 

    return true; 
}



int caricacolpo(char nomefile[], arr_colpi* pMyArray){

  //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   colpo appo;
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

   status = readcolpo(filein,appo);

   while(status == true){
      conta++;
      status = readcolpo(filein,appo);
   }


   
   filein.close();
   filein.open(nomefile);


   
   pMyArray->raw = new colpo[conta];

   if(pMyArray->raw == NULL){

      return -2;

   }
   //NOTA: anche qui non gestiamo l'eccezione, ci limitiamo a segnalarla...

   pMyArray->size = conta;
   
   //N.B.: uso direttamente used per indicizzare l'array
   //quindi: non ho bisogno di inizializzare (gia` fatto sopra)

   for( ; pMyArray->used < conta - 1; pMyArray->used++){

      readcolpo(filein, pMyArray->raw[pMyArray->used]);
      //NOTA: ignoro il valore restituito...
   }

   filein.close();

   //Dati caricati correttamente nella variabile esterna
   return 0;

}



bool printcolpo(ofstream &file, colpo appo){
    file << " theta " << appo.theta << " phi: " << appo.phi<< "  | x=" << appo.xf << " y=" << appo.yf<< endl;




}

bool printcolpo(colpo appo){
    cout << "theta: " <<  appo.theta << " phi:" << appo.phi<< "  | x=" << appo.xf << " y=" << appo.yf;
   if(appo.hit){
    cout << " a segno" << endl; 
   }else {
    cout << " non a segno" << endl; 
   }


}

void stampaarrcolpi(arr_colpi v, char nomefile []){

    ofstream file; 
    file.open(nomefile); 

   for(int i=0; i<v.used; i++)
      printcolpo(file,v.raw[i]);

}
