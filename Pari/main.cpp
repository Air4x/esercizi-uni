/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 17 ottobre 2022, 15:18
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  int a = 0;
  cout << "programma per la valutazione di un numero" << endl;
  cout << "Inserire il numero da valutare: ";
  cin >> a;
  if(a%2 == 0){
    cout << "Il nuemero " << a << " è pari" << endl;
  } else {
    cout << "Il nuemro " << a << " è dispari" << endl;
  }
  return 0;
}

