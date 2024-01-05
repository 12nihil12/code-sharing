#ifndef array_int_h
#define array_int_h

#include <iostream>
#include <fstream>
#include <cstring>

// per caricamento dati da file su array: dimensione di partenza e incremento
#define dim0 20 
#define incr 1

using namespace std; 

struct arr_int {
    int size; //dimensione array
    int used; //indice del primo posto disponibile
    int* raw; //puntatore ad array 
}; 

//funzioni specifiche al tipo di dato

bool readdata(ifstream& file_in, int &rdato); 
bool confronto(int a,int b); //settato su a>= b 

bool chiave(int el, int key); 
void printdata(ofstream& file_out, int rdato); 
void printdata(int rdato); 

//funzioni di supporto
void paf(char nomefile [], int v[], int high);

void merge(int v[], int low, int mid, int high); //NOW WORKING 

int resize(arr_int * v, int newdim); // resizes array to newdim #


//

//inizializzazione 

void initialize (arr_int * v); //inizializza una struttura array vuota #
void initialize (arr_int * v,int d); //inizializza un array di dimensione d e lo alloca in memoria #
int initialize (char nomefile [], arr_int * v); //carica dati da file in array #
void initialize(int a [], int used, arr_int * v); //inizializza una struttura arr_int e la collega ad un array esistente


//stampa array 
void printarray(char nomefile[], arr_int v); //stampa array su file #
void printarray(arr_int v); //stampa array su terminal #

void printstats (arr_int v); //stampa raw, size e used di v #
void printstats (char nomefile[], arr_int v); // stampa raw, size, used su file #


// GESTIONE ELEMENTI: 

//inserimento

void insert (arr_int * v, int el ); //inserisce elemento in fondo #
void insert (arr_int * v, int el, int where);//inserisce elemento in posizione where #

//sostituzione

void replace(arr_int *v, int el, int where); //sostituisce un elemento con uno nuovo #
void swap(arr_int *v, int i1, int i2); //scambia due elementi #

//eliminazione

void delswap(arr_int * v, int where);  //elimina el array scambiandolo con l'ultimo
void delshift(arr_int * v,  int where); //elimina el array spostando tutto indietro di 1

//fusione array

void merge (arr_int a, arr_int b, arr_int * ab); 

//ricerca e ordinamento 

int peek(arr_int * v,int where); //restituisce il valore di un elemento ad una data posizione #
int searchkey(arr_int * v, int key); //ricerca elemento nell'array data una chiave #

void mergesort(int v [] , int low, int high); //NOT WORKING
void mergesort(arr_int * v); //chiama mergesort sull'intero array

//massimo e minimo

int amax (arr_int v, int * p_max); 
int amin (arr_int v, int * p_min);


//copia


void deepcopy (arr_int v, arr_int * cp); //copia #


void dispose (arr_int *v); //cancella array #


#endif