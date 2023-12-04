#include "random.h"


double randunif (double min, double max){ //valore random, probab. uniforme

    double c = (double)rand()/RAND_MAX; 
    double v =  min + c*(max-min); 
    
    return c; 
}


double randgauss (double media, double stdv){ //valore random su gaussiana 
double u1,u2, z1,z2; 
u1 = (double) rand()/RAND_MAX; 
u2 = (double) rand()/RAND_MAX;
z1 = sqrt(-2*log(u1))*cos(2*PI*u2); 
z2 = sqrt(-2*log(u1))*sin(2*PI*u2); 

return media + z1*stdv; 

}

void seedset (){ //resetta seme 

    char check; 

    cout << "Resettare il seed? [y] [n]" << endl; 
    cin >> check; 

    if(check == 'n'){
        cout << "Seed non resettato. Attenzione, ritroverà gli stessi valori casuali della precedente implementazione" << endl; 
        return; 
    }

    srand(time(NULL)); 

    cout << "Seed resettato con successo" << endl; 

    return; 
}





