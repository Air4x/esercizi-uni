#include <iostream>

using namespace std;

// 1. Inserimento del numero di rettangoli
// 2. Inserimento delle dimensioni dei rettangoli all'interno del vettore
// 3. Stampa dei rettangoli all'interno dei vettori
// 4. Generazione vettore pivot, vettore dinamico con rettangoli la cui area è minore
//    di quella data.
// 5. Verifica ordinameto crescente (per area) del vettore di rettangoli


struct Rettangolo {
	float altezza;
	float base;
};

int inserimentoNRettangoli();
void inserisciRettangoli(Rettangolo* , int);
void echoRettangolo(Rettangolo);
void stampaRettangoli(Rettangolo*, int);
float areaRettangolo(Rettangolo);
int numPivot(Rettangolo*, int, float);
float inserisciArea();
void arrayPivot(float, Rettangolo*, int, Rettangolo*, int);
bool verificaOrdinamento(Rettangolo*, int);

int main(){
	int nRettangoli;
	Rettangolo* vec;
	int nPivot;
	Rettangolo* pivot;
	float area;
	// punto 1
	nRettangoli = inserimentoNRettangoli();
	vec = new (nothrow) Rettangolo[nRettangoli]; 
	if(!vec){
		cout << "[ERRORE] Memoria non disponibile" << endl;
		return -1;
	}
	// punto 2
	cout << "Inserire le dimensione dei rettangoli" << endl;
	inserisciRettangoli(vec, nRettangoli);	
	// punto 3
	stampaRettangoli(vec, nRettangoli);
	//punto 4
	area = inserisciArea();
	nPivot = numPivot(vec, nRettangoli, area);
	if(nPivot == 0){
		cout << "[WARN] Non ci sono rettangolo con area minore a " << area << endl;
	} else {
		pivot = new Rettangolo[nPivot];
		arrayPivot(area, vec, nRettangoli, pivot, nPivot);
		stampaRettangoli(pivot, nPivot);
	}
	// punto 5
	if(verificaOrdinamento(vec, nRettangoli)){
		cout << "Il vettore è ordinato in ordine crescente" << endl;
	} else {
		cout << "Il vettore non è ordinato" << endl;
	}
	cout << "[LOG] Programma terminato" << endl;
	return 0;
}


int inserimentoNRettangoli(){
	int input;
	do{
		cout << "Inserire il numero di rettangoli: ";
		cin >> input;
		if (input <=0){
			cout << "[ERRORE] l'array non può essere vuoto" << endl;
		}
	} while (input <= 0);
	return input;
}

void inserisciRettangoli(Rettangolo* vec, int size){
	for(int i = 0; i < size; i++){
		cout << "Altezza: ";
		cin >> (*(vec + i)).altezza;
		cout << "Base: ";
		cin >> (*(vec + i)).base;
	}
}

void echoRettangolo(Rettangolo a){
	cout << "\tAltezza: " << a.altezza << endl;
	cout << "\tBase: " << a.base << endl;
}

void stampaRettangoli(Rettangolo* vec, int size){
	for(int i = 0; i < size; i++){
		cout << "Rettangolo all'indice " << i << ":" << endl;
		echoRettangolo(*(vec+i));
	}
}

float areaRettangolo(Rettangolo a){
	return a.base * a.altezza;
}

int numPivot(Rettangolo* vec, int size, float area){
	int num = 0;
	for(int i = 0; i < size; i++){
		if(areaRettangolo(*(vec+i)) < area)
			num++;
	}
	return num;
}

float inserisciArea(){
	float area;
	cout << "Inserire l'area del pivot: ";
	cin >> area;
	return area;
}

void arrayPivot(float area, Rettangolo* vec0, int size0, Rettangolo* punt, int size_punt){
	int j = 0; // indice di punt
	for(int i = 0; i<size0; i++){
		if(areaRettangolo(*(vec0+i)) < area){
			*(punt+j) = *(vec0+i);
			j++;
		}
	}
}

// ordinamente crescente delle basi
bool verificaOrdinamento(Rettangolo* vec, int size){
	for(int i = 1; i < size; i++){
		if(!((vec+i-1)->base < (vec+i)->base))
			return false;
	}
	return true;
}
