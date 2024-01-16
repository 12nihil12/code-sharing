#include <iostream> 
#include <fstream> 
#include "bersaglio.h"
#include "colpi.h"
#include <cmath>

using namespace std; 

float distanza (bersaglio b, colpo c); 
void esercitazione( arr_ber & b, arr_colpi &c, float & acc, int & contasgn, int & cdistr); 

int main(){

    arr_ber b; 
    arr_colpi c; 

    ofstream file_out; 

    file_out.open("results.dat"); 


    caricabersaglio("bersagli.dat", &b); 

    cout << "Bersagli caricati: " << b.used << endl; 
    file_out << "Bersagli caricati: " << b.used << endl; 


    int distr0 = 0; 

    for(int k = 0; k < b.used; k++){
        if(b.raw[k].distr){
            distr0 ++; 
        }
    }

    cout << "Bersagli distrutti: " << distr0 << " e non: " << b.used - distr0 << endl; 
    file_out << "Bersagli distrutti: " << distr0 << " e non: " << b.used - distr0 << endl; 
    
    int d =0;
    int nd = 0; 

    for(int k = 0; k < b.used; k++){
        if(nd < 3){
            if(!b.raw[k].distr){
                printbersaglio(b.raw[k]); 
                nd++; 
            }
        }
         if(d < 3){
            if(b.raw[k].distr){
                printbersaglio(b.raw[k]); 
                d++; 
            }
        }
    }
    stampaarrber(b,"output.dat");

    caricacolpo("alzo_angolo.dat",&c); 

    cout << "Colpi sparati: " << c.used << endl; 

    file_out << "Colpi sparati: " << c.used << endl; 

     for(int k = 0; k < 3; k++){
       printcolpo(c.raw[k]); 
    }
    for(int k = c.used -  3; k < c.used; k++){
       printcolpo(c.raw[k]); 
    }

    stampaarrcolpi(c,"output2.dat");

    float dist; 

    //ofstream file_out; 
    //file_out.open("check.txt"); 

   // ofstream file2; 
    //file2.open("check3.txt"); 

    int contasgn= 0; 
    float acc=0; // conta il danno totale
    int cdistr= 0; // conta quanti beragli distrutti

    /* 
    for(int k = 0; k < b.used; k++){
        //file_out << endl << k << endl;
        for(int j =0; j < c.used; j++){
            dist= distanza(b.raw[k],c.raw[j]); 
            //file_out << j << " | " <<  dist; 
            if(dist < 10){
                if(!c.raw[j].hit){
                    contasgn++; 
                }
                c.raw[j].hit = true; 
            } else{
                c.raw[j].hit = false; 

            }
            //segno(c.raw[j],dist); 
            //file_out << " | " << c.raw[j].hit<< endl; 
            //file2 << endl << " segno " << c.raw[j].hit; 

            //file2 << " " << b.raw[k].c << " | "; 

            if(c.raw[j].hit){
                colpito(b.raw[k],dist,acc); 
                //file2 << b.raw[k].c << endl; 
            }
        }
        if(b.raw[k].c < 0){
            b.raw[k].distr = true; 
            cdistr++; 
            //cout << cdistr << endl; 
        }


    }
 */
    esercitazione(b,c,acc,contasgn,cdistr); 
    
    cout << "Colpi a segno: " << contasgn << " e danno totale: " << acc <<  endl; 
    file_out << "Colpi a segno: " << contasgn << " e danno totale: " << acc <<  endl; 

    cout << "Bersagli distrutti: " << cdistr - distr0 << endl;
    file_out << "Bersagli distrutti: " << cdistr - distr0 << endl;

    bersaglio ca; 
    ca.x = 0; 
    ca.y = 0; 

    float distanze [c.used]; 
    for (int j = 0; j <= c.used; j++){
        distanze[j]= distanza(ca,c.raw[j]); 
        cout << distanze[j] << endl; 
    }


    int cmax, cmin; 

    cmax = posmax(distanze,0,c.used); 
    cmin = posmin(distanze,0,c.used); 

    cout << "Colpo a distanza massima: " << endl; 
    file_out << "Colpo a distanza massima: " << endl; 

    printcolpo(c.raw[cmax]); 
    printcolpo(file_out, c.raw[cmax]); 


    cout << endl << "Colpo a distanza minima: " << endl; 
    file_out << endl << "Colpo a distanza minima: " << endl; 


    printcolpo(c.raw[cmin]); 
    printcolpo(file_out, c.raw[cmin]); 


    return 0; 


}

float distanza (bersaglio b, colpo c){
    float d2 = pow(b.x-c.xf,2) + pow(b.y - c.yf,2); 

    return sqrt(d2); 
}

void esercitazione( arr_ber & b, arr_colpi & c, float & acc, int & contasgn,int & cdistr){
    
    float dist; 

    //ofstream file_out; 
    //file_out.open("check.txt"); 

   // ofstream file2; 
    //file2.open("check3.txt"); 

 

    for(int k = 0; k < b.used; k++){
        //file_out << endl << k << endl;
        for(int j =0; j < c.used; j++){
            dist= distanza(b.raw[k],c.raw[j]); 
            //file_out << j << " | " <<  dist; 
            if(dist < 10){
                if(!c.raw[j].hit){
                    contasgn++; 
                }
                c.raw[j].hit = true; 
            } else{
                c.raw[j].hit = false; 

            }
            //segno(c.raw[j],dist); 
            //file_out << " | " << c.raw[j].hit<< endl; 
            //file2 << endl << " segno " << c.raw[j].hit; 

            //file2 << " " << b.raw[k].c << " | "; 

            if(c.raw[j].hit){
                colpito(b.raw[k],dist,acc); 
                //file2 << b.raw[k].c << endl; 
            }
        }
        if(b.raw[k].c < 0){
            b.raw[k].distr = true; 
            cdistr++; 
            //cout << cdistr << endl; 
        }

    }

}

