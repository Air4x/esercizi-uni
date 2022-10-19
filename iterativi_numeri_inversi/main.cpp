/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 17 ottobre 2022, 14:06
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  int n = 0;
  cout << "inserire il numero n: ";
  cin >> n;
  cout << "I numeri interi appartenenti all'intervallo [0, "<<n<<"] sono" << endl;
  for(int i = n; i >= 0; i--){
    cout << i << endl;
  }
  return 0;
}

