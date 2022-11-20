/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 4 novembre 2022, 17:16
 */

#include <iostream>

using namespace std;

/*
 * 
 */


void stampa_msg_n(int);

int main(int argc, char** argv) {

  int num_volte = 0;
  cout << "Inserire il numero di volte che si desidera stampare il messaggio: ";
  cin >> num_volte;
  stampa_msg_n(num_volte);
  return 0;
}

void stampa_msg_n(int volte){
  for (int i = 0; i < volte; i++){
    cout << "la mia prima funzione" << endl;
  }
}
