#include <iostream>
#include "../R2points_array.h"
#include "../stat_adv.h"

using namespace std; 

int main (){

    points_array oss;  
    points_array exp; 

    int error; 
    double m, q; 
    double media_y_exp; 
    double app; //appoggio, non mi serve a nulla, ma la funzione ha bisogno di un altro parametro
    oss = load_points_file("rilevazioni.dat", error); 


    retta_min_quad(oss,m,q); 

    exp = oss; 

    retta(exp,m,q); 

    baricentri(exp,app,media_y_exp); 

    cout << "Media y attese: " << media_y_exp << endl; 

    double ss = 0; 

    for(int i = 0; i < oss.used; i++){

        ss = pow((oss.raw[i].y - exp.raw[i].y),2); 
    }

    cout << "Scarto quadratico medio: " << ss/v.used << endl; 


    return 0; 
}