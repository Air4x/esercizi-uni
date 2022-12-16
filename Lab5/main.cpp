#include <iostream>
#include <fstream>
using namespace std;

typedef struct{
    float l1;
    float l2;
    float l3;
    float l4;
} Quadrilatero;


Quadrilatero* lettura(int&, bool&);
void stampaQuadrilateri(Quadrilatero*, int);
void echoQuadrilatero(Quadrilatero);
bool equilatero(Quadrilatero);
float perimetro(Quadrilatero);
float massimoEquilatero(Quadrilatero*, int, bool&);
int nonEquilatero(Quadrilatero*, int, bool&);

int main() {
	int dim;
	bool esito;
	Quadrilatero* vet;
	float perimetro_max;
	int idx_equilatero;
    	vet = lettura(dim, esito);
	stampaQuadrilateri(vet, dim);
	perimetro_max = massimoEquilatero(vet, dim, esito);
	if(esito){
		cout << "Il perimetro massimo è: " << perimetro_max<< endl;
	}
	idx_equilatero = nonEquilatero(vet, dim, esito);
	if(esito){
		cout << "Il primo non equilatero è" << endl;
		echoQuadrilatero(*(vet+idx_equilatero));
	} else {
		cout << "Il vettore contiene solo quadrilateri equilateri" << endl;
	}
    	return 0;
}


Quadrilatero* lettura(int& riemp, bool& esito){
	fstream f;
	Quadrilatero* pvet;
	f.open("quadrilateri.txt", ios::in);
	if(!f){
		esito = false;
		return NULL;
	}
	f>> riemp;
	pvet = new Quadrilatero[riemp];
	for(int i = 0; i<riemp; ++i){
		f >> (pvet+i)->l1;
     		f >> (pvet+i)->l2;
     		f >> (pvet+i)->l3;
     		f >> (pvet+i)->l4;
	}
	return pvet;
}

void echoQuadrilatero(Quadrilatero bob){
	cout << "\t" << bob.l1 << endl;
	cout << "\t" << bob.l2 << endl;
	cout << "\t"<< bob.l3 << endl;
	cout << "\t" << bob.l4 << endl;
}

void stampaQuadrilateri(Quadrilatero* vet, int dim){
	for(int i=0; i<dim; ++i){
		echoQuadrilatero(*(vet+i));
	}
}

bool equilatero(Quadrilatero bob){
	if(bob.l1 != bob.l2 || bob.l1 != bob.l3 || bob.l1 != bob.l4){
		return false;
	}
	return true;
}


float perimetro(Quadrilatero bob){
	return bob.l1+bob.l2+bob.l3+bob.l4;
}

float massimoEquilatero(Quadrilatero* vet, int dim, bool& esito){
	float max = 0;
	esito = false;
	for(int i=0; i< dim; ++i){
		if(equilatero(*(vet+i))){
			if(max < perimetro(*(vet+i))){
				max = perimetro(*(vet+i));
			}
			esito = true;
		}
	}
	return max;
}

int nonEquilatero(Quadrilatero* vet, int dim, bool& esito){
	int idx;
	for(idx = 0; idx<dim; idx++){
		if(!equilatero(*(vet+idx))){
			esito = true;
			return idx;
		}
	}
	return -1;
}

