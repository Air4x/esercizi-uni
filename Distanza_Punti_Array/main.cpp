#include <iostream>
#include <math.h>
using namespace std;

// Un punto cartesiano a due dimensioni
struct Punto {
  double x;
  double y;
};

#define LEN 15

double distanza(Punto, Punto);

int main() {
  Punto vettore[LEN];
  Punto p_utente;
  double d_min = 0;
  double d_max = 0;

  // Inserimento punti all'interno dell'array da parte
  // dell'utente
  for(int i = 0; i < LEN; i++){
    cout << "Inserisci l'ascissa del punto " << i+1 <<": ";
    cin >> vettore[i].x;
    cout << "Inserisci l'ordinata del punto " << i+1 << ": ";
    cin >> vettore[i].y;
  }

  cout << "Inserire p_utente" << endl;
  cout << "x: ";
  cin >> p_utente.x;
  cout << "y: ";
  cin >> p_utente.y;

  // calcolo distanza massima e minima
  double d = 0;
  d_max = distanza(vettore[0], p_utente);
  d_min = distanza(vettore[0], p_utente);
  for(int i = 0; i < LEN; i++){
    d = distanza(vettore[i], p_utente);
    
    if (d_max < d){
      d_max = d;
    }
    
    if (d_min > d){
      d_min = d;
    }
  }

  cout << "La distanza minima è: " << d_min << endl;
  cout << "La distanza massuma è: " << d_max << endl;
  return 0;
}

double distanza(Punto a, Punto b){
  return sqrt(pow((b.x - a.x) ,2.0)+(pow((b.y - a.y),2.0)));
}

