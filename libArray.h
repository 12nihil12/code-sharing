
#include <iostream>
#include <fstream> 

using namespace std; 

//STAMPA: 

void paf(int [], int); //stampa array su file
void paf(float [], int); //stampa array su file
void paf(char[], int); //stampa array su file

void print(int [], int); //stampa array
void print(float [], int); //stampa array
void print(char[], int); //stampa array


//RIEMPIMENTO 

void fill0(int v[],int size);  //inizializza un contatore array a 0

void fill (int [], int); //riempio array int
void fill (float [], int); //riempio array float
void fill (char [], int); //riempio array char

int load (int [], int ); //carico valori int su array, restituisco numero effettivo
int load (float [], int ); //carico valori float su array, restituisco numero effettivo
int load (char [], int ); //carico valori char su array, restituisco numero effettivo

int fff (char nomefile[], int arr[], int  ); //carico valori int su array da file di tipo uniforme , restituisco numero effettivo
int fff (char nomefile[], float arr[], int ); //carico valori float su array da file , restituisco numero effettivo
int fff (char nomefile[], char arr[], int ); //carico valori float su array da file , restituisco numero effettivo


//MINIMO E MASSIMO 

int posmin (int v[], int i, int size); //restituisce posizione elemento minimo array di (size) elementi a partire da i
int posmin (float v[], int i, int size); //restituisce posizione elemento minimo array di (size) elementi a partire da i
int posmin (char v[], int i, int size); //restituisce posizione elemento minimo array di (size) elementi a partire da i

int posmax (int v[], int i, int size); //restituisce posizione elemento massimo array di (size) elementi a partire da i
int posmax (float v[], int i, int size); //restituisce posizione elemento massimo array di (size) elementi a partire da i
int posmax (char v[], int i, int size); //restituisce posizione elemento massimo array di (size) elementi a partire da i



//RIORDINAMENTO

void swap(int v[], int i, int j, int size); // swap elementi int 
void swap(float v[], int i, int j, int size); // swap elementi float
void swap(char v[], int i, int j, int size); // swap elementi float


void order(int v[], int size); // ordinamento array
void order(float v[], int size); //ordinamento array
void order(char v[], int size); //ordinamento array


//ELIMINAZIONE ELEMENTO

int delswap(int v[], int  used, int where); //elimina el array scambiandolo con l'ultimo
int delswap(float v[], int used,  int where ); //elimina el array scambiandolo con l'ultimo
int delswap(char v[], int used,   int where); //elimina el array scambiandolo con l'ultimo


int delshift(int v[], int used,   int where ); //elimina el array spostando tutto indietro di 1
int delshift(float v[], int used,   int where ); //elimina el array spostando tutto indietro di 1
int delshift(char v[], int used,   int where ); //elimina el array spostando tutto indietro di 1


