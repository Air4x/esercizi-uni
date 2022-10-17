#include <iostream>
using namespace std;

int main(){
  // intervallo esterno  da verificare [-2,3[

  int input = 0;
  bool predicato = false;
  cout << "Inserire il valore di x: ";
  cin >> input;
  predicato = input < -2 || input >= 3;
  cout << "Il predicato logico vale: " << predicato;
  return 0;
}
