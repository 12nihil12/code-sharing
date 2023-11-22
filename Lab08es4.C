#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

bool isPrime(int n);
bool isPerfectSquare(int n);

int main(){
    int leggi;
    int*v_interi = NULL; bool* Prime = NULL; bool* Square = NULL;
    int conta =0;
    ifstream file_in;
    ofstream file_out;
    file_in.open("interi.dat");
    if(file_in.fail()){
        return -1;
    
    }

    file_in>>leggi;    
    while(!file_in.eof()){
        conta++;
        file_in>>leggi;

    }
    //creazione array 
    v_interi = new int[conta];
    Prime = new bool[conta];
    Square = new bool[conta];

    file_in.close();
    file_in.open("interi.dat");
    for(int i=0; i<conta; i++){
        file_in>>v_interi[i];
    }
    file_in.close();//ho finito di prendere i file da interi.dat e li ho inseriti in v_interi



    //inizializzo i bool a true
    for(int i=0; i<conta; i++){
        Prime[i] = true;
        Square[i] = true;
    }


    int p;
    for(int i=0; i<conta; i++){

            p = v_interi[i];
            Prime[i] = isPrime(p);
            Square[i] = isPerfectSquare(p);

            if(Square[i] == false){
                if(Prime[i] == false){
                    v_interi[i] = false;
                }

            }

            
          
    }
    file_out.open("risultati.dat");
    if(file_out.fail()){
        return -2;
    }


    for(int i=0; i<conta; i++){
        if(v_interi[i]){
            file_out<<v_interi[i];
            if(Prime[i] == true){
                file_out<<"  primo"<<endl;
            }
            else if(Square[i] == true){
                file_out<<"  quadrato perfetto"<<endl;
            }
        }
    }

    file_out.close();
    //funzione ffff

    delete []Square;
    delete []Prime;
    delete []v_interi;
    return 0;
}

bool isPrime(int n){
    bool Prime = true;
    int resto;
    for(int i=2; i<(n-1);i++) {
        resto = n%i;
        if(resto == 0) {
            Prime = false;
        }
    }
    
    return Prime;
}

void ffff(int N_max, int valori[]){
    
}
bool isPerfectSquare(int n){
    bool isPsquare = false;
    int square;
    square = sqrt(n);
    square = pow(square, 2);
    if(square == n){
        isPsquare = true;
    }
    return isPsquare;

}