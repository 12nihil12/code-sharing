#include "libstat.h"

//MEDIA

float media (int v[], int ndt){

    int conta = 0; 

    for( int c= 0; c < ndt; c++){
        conta= conta + v[c];
    }

    float media = (float)conta / ndt; 
    return media; 
}

float media (float v[], int ndt){

    double conta = 0; 





    for( int c= 0; c < ndt; c++){
        conta= conta + v[c];
    }

    float media = conta / ndt; 
    return media; 
}

//DV. STD 

float devstd (int v[], int ndt) {

    float scarto = 0;
    float x = media(v, ndt); 

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    float devstd = sqrt(scarto/ (ndt -1)); 

    return devstd; 
}
float devstd (float v[], int ndt) {


    float scarto = 0;
    float x = media(v, ndt); 

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    float devstd = sqrt(scarto/ (ndt -1)); 

    return devstd; 
}
float devstd (int v[], int ndt, float x) { // devstd (avendo gia` la media)

    float scarto = 0;

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    float devstd = sqrt(scarto/ (ndt -1)); 

    return devstd; 
}
float devstd (float v[], int ndt, float x) { // devstd (avendo gia` la media)

    float scarto = 0;

     for( int c= 0; c < ndt; c++){
        scarto = scarto + pow((x - v[c]), 2); 
    }


    float devstd = sqrt(scarto/ (ndt -1)); 

    return devstd; 
}


//MEDIANA 
float mediana (int v[], int size){

order(v, size); 
    
 if(size%2==0){
        return (float)(v[size/2 -1 ]+v[size/2 ])/2;
    } else {
        return (float)v[(size+1)/2 -1]; 
    }
}
float mediana (float v[], int size){

    order(v, size); 
    
 if(size%2==0){
        return (float)(v[size/2 -1 ]+v[size/2 ])/2;
    } else {
        return (float)v[(size+1)/2 -1]; 
    }
}