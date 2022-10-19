/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 19 ottobre 2022, 12:40
 */

#include <iostream>

using namespace std;

#define NUMERO_MAGICO 2791

/*
 * 
 */
int main(int argc, char** argv) {
  int risposta = 0;
  do {
    cout << "Inserisci la tua risposta: ";
    cin >> risposta;
    if(risposta < NUMERO_MAGICO){
      cout << "Sfortunato !!" << endl;
      cout << risposta << " è minore del numero da indovinare" << endl;
    } else if (risposta > NUMERO_MAGICO) {
      cout << "Sfortunato !!" << endl;
      cout << risposta << " è maggiore del numero da indovinare" << endl;
    }
  } while (risposta != NUMERO_MAGICO);
  cout << "Hai indovinato !!" << endl;
  return 0;
}

