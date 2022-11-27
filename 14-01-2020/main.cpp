#include <iostream>

struct Immagine {
	int id;
	float dimX;
	float dimY;
	long int bytes;
};

using namespace std;

// 1. inserimento numero immagini [1-20]
// 2. inserimento delle immagini
// 3. stampa array di immagini
// 4. rotazione immagine più grande
// 5. duplicazione array 

int inserisciRiempimento();
void inserisciImmagini(Immagine [], int);
void stampaImmagini(Immagine [], int);
int posMax(Immagine [], int);
void ruotaImmagine(Immagine [], int);
void duplicazioneImmagini(Immagine [], int&);

int main(){
	Immagine immagini[40];
	int riemp;
	riemp = inserisciRiempimento();
	inserisciImmagini(immagini, riemp);
	cout << "Stampa dell'array" << endl;
	stampaImmagini(immagini, riemp);
	cout << "Ruotazione immagine di dimensione massima"  << endl;
	ruotaImmagine(immagini, riemp);
	cout << "Duplicazione immagini e stampa dell'array" << endl;
	duplicazioneImmagini(immagini, riemp);
	stampaImmagini(immagini, riemp);
	return 0;
}


int inserisciRiempimento(){
	int riemp;
	do{
		cout << "inserire numero immagini: ";
		cin >> riemp;
		if (riemp < 1 || riemp > 20){
			cout << "Il numero di immagini deve essere compreso tra 1 e 20" << endl;
		}
	} while(riemp < 1 || riemp > 20);
	return riemp;
}

void inserisciImmagini(Immagine v[], int riemp){
	for(int i = 0; i < riemp; i++){
		cout << "Inseririe immagine all'indice " << i << " " << endl;
		cout << "Id: ";
		cin >> v[i].id;
		cout << "dimX: ";
		cin >> v[i].dimX;
		cout << "dimY: ";
		cin >> v[i].dimY;
		cout << "bytes: ";
		cin >> v[i].bytes;
	}
}

void stampaImmagini(Immagine v[], int riemp){
	for(int i = 0; i < riemp; i++){
		cout << "(" << v[i].id << "," << v[i].dimX << "," << v[i].dimY << "," << v[i].bytes << ")" << endl; 
	}
}

int posMax(Immagine v[], int riemp){
	long int max = v[0].bytes;
	int pos = 0;
	for(int i = 0; i < riemp; i++){
		if(v[i].bytes > max){
			max = v[i].bytes;
			pos = i;
		}
	}
	return pos;
}

void ruotaImmagine(Immagine v[], int riemp){
	int pos = posMax(v, riemp);
	int temp;
	temp = v[pos].dimX;
	v[pos].dimX = v[pos].dimY;
	v[pos].dimY = temp;
	cout << "Id immagine ruotata: " << v[pos].id << endl;
	stampaImmagini(v, riemp);
}

void duplicazioneImmagini(Immagine v[], int& riemp){
	for(int i = 0; i < riemp; i++){
		v[i+riemp] = v[i];
	}
	riemp *= 2;
}
