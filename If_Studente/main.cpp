#include <iostream>
using namespace std;

int main(){
  int voto = 0;
  cout << "Inserire voto: ";
  cin >> voto;
  if (voto >= 18) {
    cout << "Bravo !!!" << endl << "Studente Promosso" << endl;
  }
  cout << "Fine programma" << endl;
  return 0;
}