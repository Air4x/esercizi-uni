/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 14 ottobre 2022, 19:43
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  char colore = 'n';
  cout << "Inserire colore semaforo: ";
  cin >> colore;

  switch(colore){
  case 'r':
  case 'R':
    cout << "Semaforo rosso" << endl;
    cout << "Ferma !" << endl;
    break;
  case 'v':
  case 'V':
    cout << "Semaforo verde" << endl;
    cout << "Puoi passare !" << endl;
    break;
  case 'g':
  case 'G':
    cout << "Semaforo giallo" << endl;
    cout << "Fai attenzione !" << endl;
    break;
  default:
    cout << "Opzione non ammessa" << endl;
  }
  cout << "Programma terminato" << endl;
  return 0;
}

