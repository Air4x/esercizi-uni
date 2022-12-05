#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

//1. lettura dati da file. La prima riga è il riemp del vettore statico di
//   cardinalità massima 100
//2. stampa dei robot all'interno del vettore
//3. Evidenziazione dei robot a temperatura massima
//4. cancellazione dei robot il cui nome inizia con un carattere tra a e d e stampa vettore modificato

typedef struct {
	char identificativo[6];
	float velocita;
	float temperatura;
} Robot;

#define MAXDIM 100
#define IFILE "robot.txt"

bool letturaBracci(char [], Robot [], int&);
void echoRobot(Robot);
void stampaVettore(Robot [], int);
float max(Robot [], int);
void evidenziaRobot(Robot [], int, float);
void rimozioneElem(Robot [], int&, int);
int rimozioneRobot(Robot [], int&);

int main() {
	int riemp;
	float max_temp;
	Robot bracci_meccanici[MAXDIM];
	// Punto 1
	if(!letturaBracci(IFILE, bracci_meccanici, riemp)){
		cout << "Impossibile leggere dati da file" << endl;
		return -1;
	}
	
	// Punto 2
	cout << "Vettpre letto da file" << endl;
	stampaVettore(bracci_meccanici, riemp);
	cout << endl;
	// Punto 3
	cout << "Vettore evidenziato" << endl;
	max_temp = max(bracci_meccanici, riemp);
	evidenziaRobot(bracci_meccanici, riemp, max_temp);
	stampaVettore(bracci_meccanici, riemp);
	// Punto 4
	if(rimozioneRobot(bracci_meccanici, riemp) != 0){
		cout << "Impossibile rimuovere i bracci meccanici" << endl;
		return -1;
	}
	cout << "Vettore modificato" << endl;
	stampaVettore(bracci_meccanici, riemp);
	cout << "Programma terminato" << endl;
	return 0;
}

bool letturaBracci(char file[], Robot vec[], int& riemp){
	fstream f;
	f.open(file, ios::in);
	if (!f){
		return false;
	}
	f >> riemp;
	for(int i = 0; i < riemp; ++i){
		f >> vec[i].identificativo;
		f >> vec[i].velocita;
		f >> vec[i].temperatura;
	}
	return true;
}


void echoRobot(Robot bob){
	cout << "\tId: " << bob.identificativo << endl;
	cout << "\tVelocità di rotazione: " << bob.velocita << endl;
	cout << "\tTemperatura: " << bob.temperatura << endl;
}

void stampaVettore(Robot vec[], int riemp){
	for(int i = 0; i<riemp; ++i){
		cout << "Robot in posizione " << i << endl;
		echoRobot(vec[i]);
	}
}


float max(Robot vec[], int riemp){
	float max = vec[0].temperatura;
	for(int i = 1; i<riemp; ++i){
		if(max < vec[i].temperatura)
			max = vec[i].temperatura;
	}
	return max;
}

void evidenziaRobot(Robot vec[], int riemp, float max_temp){
	for(int i = 0; i < riemp; ++i){
		if(vec[i].temperatura == max_temp){
			vec[i].identificativo[0] = (char) toupper(vec[i].identificativo[0]);
		}
	}
}

void rimozioneElem(Robot vec[], int& riemp, int pos){
	for(int i=pos; i<riemp-1; i++) {
            vec[i]=vec[i+1];
        }
	riemp--;
}

bool daEliminare(char a){
	char inf = 'a';
	char sup = 'd';

	if( (tolower(a) >= (int) inf) && (tolower(a) <= (int) sup) )
		return true;
	return false;
}

int rimozioneRobot(Robot vec[], int& riemp){
	int pos[riemp];
	int pos_indx = 0;
	int pos_riemp = 0;
	// robot il cui nome inizia con una lettera tra a e d
	// considero a e d comprese nell'intervallo
	// Creazione array con le posizioni dei robot da eliminare
	for(int i = 0; i < riemp; ++i){
		if(daEliminare(vec[i].identificativo[0])){
			pos[pos_indx] = i;
			pos_indx++;
			pos_riemp++;
		}
	}
	if(pos_riemp == 0) { return -1; }
	// eliminazione robot
	for(int i = 0; i<pos_riemp; ++i){
		rimozioneElem(vec, riemp, pos[i]);
	}
	return 0;
}
