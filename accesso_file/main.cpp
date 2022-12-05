#include <iostream>
#include <fstream>
using namespace std;


#define IFILE "array.txt"
#define OFILE "risultati.txt"
#define MAXDIM 100

int massimo(int [], int);
int prodotto(int [], int);
int somma(int [], int);


int main() {
	int riemp, max, prod, sum;
	int vec[MAXDIM];
	fstream file;
	file.open(IFILE, ios::in);
        if(!file)
		return -1;
	
	file >> riemp;
	for(int i = 0; i<riemp; ++i)
		file >> vec[i];

	file.close();
	for(int i =0; i<riemp; ++i){
		cout << vec[i]<< endl;
	}
	max = massimo(vec, riemp);
	prod = prodotto(vec, riemp);
	sum = somma(vec, riemp);

	file.open(OFILE, ios::app);
	file << "Il massimo è: " << max << endl;
	file << "Il prodotto è: " << prod << endl;
	file << "La somma è: " << sum << endl;
	file.close();
	return 0;
}

int massimo(int vec[], int riemp){
	int max = vec[0];
	for(int i = 0; i<riemp; ++i){
		if(max < vec[i]){
			max = vec[i];
		}
	}
	return max;
}

int prodotto(int vec[], int riemp){
	int prod = 1;
	for(int i = 0; i<riemp; ++i) 
		prod *= vec[i];
	return prod;
}

int somma(int vec[], int riemp){
	int sum = 0;
	for(int i = 0; i<riemp; ++i){
		sum += vec[i];
	}
	return sum;
}
