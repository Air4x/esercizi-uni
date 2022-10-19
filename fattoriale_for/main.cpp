/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 19 ottobre 2022, 12:39
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  int n = 0;
  int risultato = 1;
  cout << "Programma per calcolare il fattoriale di n" << endl;
  cout << "Inserire n: ";
  cin >> n;
  if(n < 1){
    cout << "Impossibile calcolare il fattoriale, n deve essere ≥ 1" << endl;
  } else {
    for(int i = 1; i <= n; i++){
      risultato = risultato * i;
    }
    cout << "Il fattoriale di n è: " << risultato << endl;
  }
  return 0;
}

