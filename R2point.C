#include "R2point.h"

void hello (){
    cout << "hello world" << endl; 
}

bool load_point (ifstream& file_in, R2point & p){

    R2point rex; //appoggio 

    file_in >> rex.x >> rex.y; //carico su appoggio

    if(file_in.eof() || file_in.fail()){
      return false; // il dato non è stato caricato
   }else {
    p = rex; //copio su var a cui p si riferisce 
    return true; // il dato è stato caricato 
   }


}

void print_point_file (ofstream& file_out, char nomefile[], R2point p){ //print on file

    //file_out.open(nomefile, ios_base::app); 

    file_out << p.x << setw(12) << p.y << endl; 

    return; 

}
