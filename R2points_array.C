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

        p_arr.used--; 

        file_in.close(); 

        errcode = 0; 

        return p_arr; 

   
}




void print_points_file(char nomefile[], R2point v[], int da, int a) { //stampa array da indice a indice 

    ofstream file_out; 
    file_out.open(nomefile); 
    //file_out << "Dati" << endl; 
    
    for (int c=da; c <= a; c++ ){
       print_point_file(file_out,nomefile,v[c]); 
    }

    file_out.close(); 
}