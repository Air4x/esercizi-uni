/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 4 novembre 2022, 17:25
 */

#include <iostream>

using namespace std;

/*
 *
 */

int max2numeri(int, int);

int main(int argc, char** argv) {
  int v1 = 0;
  int v2 = 0;
  cout << "Inserire il primo valore: ";
  cin >> v1;
  cout << "Inserire il secondo valore: ";
  cin >> v2;
  
  int max = max2numeri(v1,v2);
  cout << "Il valore massimo è: " << max << endl;
  return 0;
}

int max2numeri(int a, int b){
  int max = 0;
  if(a > b){
    max = a;
  }else{
    max = b;
  }
  return max;
}
