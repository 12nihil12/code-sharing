#include "R2points_array.h"

points_array load_points_file (char nomefile[], int & errcode){

    ifstream file_in; 
        file_in.open(nomefile); 
        points_array p_arr; 

        p_arr.raw = NULL; 
        p_arr.size = p_arr.used = -1; // così se succedono stranezze me ne accorgo (spero)

        if(file_in.fail()){
            errcode = -1; //problemi con lo stream
            return p_arr; 
        }

        int c = 0; //contatore
        R2point cody; //appoggio

        bool status = load_point(file_in, cody); 

        while(status){
            c++; //conto dati
            status = load_point(file_in,cody); //finchè questa non diventa falsa 
        }

        file_in.clear();
        file_in.seekg(0, ios::beg); //resetta stream 

        
        p_arr.raw = new R2point [c]; // c è la dimensione ora

        if(p_arr.raw == NULL){
            errcode = -2; //problemi con l'allocazione 
            return p_arr; 
        }

        p_arr.size = c; 
        p_arr.used = 0; 

             
        for(; p_arr.used < p_arr.size; p_arr.used++){
             
            load_point(file_in,p_arr.raw[p_arr.used]); //carica punto su array
        }

        file_in.close(); 

        errcode = 0; 

        return p_arr; 

   
}

void print_points_file(char nomefile[], R2point v[], int da, int a) { //stampa array da indice a indice 

    ofstream file_out; 

    cout << "Vuole riscrivere il file? [y/n]" << endl; 
    char check; 
    cin >> check; 
    if(check == 'y'){
        file_out.open(nomefile); 
    } else {
        file_out.open(nomefile,ios_base::app); 
    }


    //file_out << "Dati" << endl; 
    
    for (int c=da; c <= a; c++ ){
       print_point_file(file_out,nomefile,v[c]); 
    }

    file_out.close(); 
}


void retta(points_array & rv, double m, double q){ //dati m e q, calcola le y di un vettore di x 
    for (int i = 0; i < rv.used; i++){
        rv.raw[i].y = m*rv.raw[i].x + q; 
    }

    return; 
}


void baricentri (points_array v, double & x_m, double & y_m){ 
    double conta_x = 0; 
    double conta_y = 0; 
    for( int c= 0; c < v.used; c++){
        conta_x= conta_x + v.raw[c].x;
        conta_y= conta_y + v.raw[c].y;

    }

    x_m = conta_x / v.used; //baricentro x
    y_m = conta_y / v.used; // baricentro y 

}


double scarto_xy (points_array v,double x_m, double y_m){

    double ss = 0; //somma scarti 
    for(int i = 0; i < v.used; i++){
        ss = ss + (v.raw[i].x-x_m)*(v.raw[i].y-y_m); 
    }

    return ss; 
}

double scarto_2 (points_array v,double x_m, double y_m, bool which){ //calcola lo scarto al quadrato di x o y
    double ss = 0; //somma scarti 

    if(which){ //se which = true, calcola la somma degli scarti di x
        for(int i = 0; i < v.used; i++){
            ss = ss + pow((v.raw[i].x - x_m),2); 
        }
        return ss; 
    } else{
        for(int i = 0; i < v.used; i++){
            ss = ss + pow((v.raw[i].y - y_m),2); 
        }
        return ss; 
    }
}

