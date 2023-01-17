/*Scrivere un programma per la gestione di copie di libri posizionati su
uno scaffale. Lo scaffale può essere modellato come un array di copie
di un libro. Ogni copia è descritta da un valore reale che rappresenta
il prezzo del libro e dal titolo, stringa di 15 caratteri.*/

/*Il programma deve fornire le funzionalità descritte di seguito,
tenendo presente che i primi tre requisiti sono precondizioni per
l’esecuzione dei rimanenti. Il programma deve essere strutturato
utilizzando i prototipi di funzione.*/


//Lettura delle copie da file 
//Stampa a video delle copie dei libri sullo scaffale. Il programma
///mostra a video i le copie dei libri dello scaffale.

//Inversione dell’ordine dei libri sullo scaffale dopo una certa
//posizione inserita dall’utente. Il programma chiede all’utente di
//inserire l’indice della posizione dello scaffale. Il programma
//inverte l’ordine dei libri che hanno indice maggiore uguale di
//quello inserito dall’utente. Se l’utente inserisce un valore non
//valido allora il programma mostra un opportuno messaggio di errore

//Rimozione delle copie a prezzo massimo. Il programma rimuove dallo
//scaffale tutte le copie dei libri a prezzo massimo. Il programma
//mostra a video le copie rimaste sullo scaffale.

#include <iostream>
#include <fstream>
using namespace std;

typedef struct {
  float prezzo;
  char titolo[16];
} Libro;

bool letturaFile(Libro [], int&);
void stampaScaffale(Libro [], int);
void inversione(Libro [], int, int);
float max(Libro [], int);
bool rimozione(Libro [], int&, int);
bool rimozioneMassimi(Libro [], int&);


int main(){
  Libro scaffale[20];
  int riemp;
  int indice = -1;
  if(!letturaFile(scaffale, riemp)){
    cout << "Impossibile leggere i dati da file" << endl;
    return -1;
  }
  stampaScaffale(scaffale, riemp);

  while(indice<1 || indice>riemp){
    cout << "Inserire la posizione da cui invertire: ";
    cin >> indice;
    if(indice<1 || indice>riemp){
      cout << "Posizione non valida" << endl;
      cout << "L'indice deve essere compreso in [1," << riemp << "]" << endl;
    }
  }
  cout << "Scaffale dopo l'inversione: " << endl;
  inversione(scaffale, riemp, indice);
  stampaScaffale(scaffale, riemp);
  
  if(!rimozioneMassimi(scaffale, riemp)){
    cout << "Impossibile rimuovere libri dallo scaffale" << endl;
    return -1;
  }
  cout << "Array dopo la rimozione delle copie a prezzo massimo:" << endl;
  stampaScaffale(scaffale, riemp);
  
  return 0;
}

bool letturaFile(Libro scaffale[], int& riemp){
  fstream file;
  file.open("input.txt", ios::in);
  if(!file){
    return false;
  }
  file >> riemp;
  if(riemp < 1 || riemp > 20){
    return false;
  }

  for(int i = 0; i < riemp; ++i){
    file >> scaffale[i].prezzo;
    file >> scaffale[i].titolo;
  }
  return true;
}

void stampaScaffale(Libro scaffale[], int riemp){
  for(int i = 0; i<riemp; ++i){
    cout << "Libro in posizione " << i << endl;
    cout << "\t" << "Titolo: " << scaffale[i].titolo << endl;
    cout << "\t" << "Prezzo: " << scaffale[i].prezzo << endl;
  }
}

// La funzione da per scontato che indice sia valido
void inversione(Libro scaffale[], int riemp, int indice){
  Libro temp[riemp];
  int temp_riemp = 0;
  int idx = 0;
  for(int i = 0; i <= indice+1; ++i){
    temp[i] = scaffale[riemp - 1 - i];
    temp_riemp++;
  }
  for(int i = indice; i < riemp; ++i){
    scaffale[i] = temp[idx];
    idx++;
  }
}

float max(Libro scaffale[], int riemp){
  float massimo = scaffale[0].prezzo;
  for(int i = 1; i<riemp; ++i){
    if(scaffale[i].prezzo > massimo){
      massimo = scaffale[i].prezzo;
    }
  }
  return massimo;
}

bool rimozione(Libro vet[], int& riemp, int pos){
  if(pos > riemp || pos < 0){
    return false;
  }
  for(int i = pos; i < riemp-1; i++){
    vet[i] =  vet[i+1];
  }
  riemp--;
  return true;
}

bool rimozioneMassimi(Libro scaffale[], int& riemp){
  int occorrenze[riemp];
  int n_occorrenze = 0;
  float massimo = max(scaffale, riemp);
  int idx = 0;
  for(int i = 0; i<riemp;++i){
    if(scaffale[i].prezzo == massimo){
      occorrenze[idx] = i;
      idx++;
      n_occorrenze++;
    }
  }
  for(int i = 0; i< n_occorrenze; ++i){
    if( !rimozione(scaffale, riemp, occorrenze[n_occorrenze-1-i]) ){
      return false;
    }
  }
  return true;
}
