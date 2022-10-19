/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 17 ottobre 2022, 15:26
 */

#include <iostream>

using namespace std;

const float pi = 3.14;

/*
 * 
 */
int main(int argc, char** argv) {
  float r = 0;
  // circonferenza 2pir
  // area r^2pi
  float perimetro;
  float area;
  cout << "Programma per il calcolo dell'area e del perimetro di un cerchio" << endl;
  cout << "inserie il raggio: ";
  cin >> r;

  perimetro = 2 * pi * r;
  area = (r*r)*pi;

  cout << "Il perimetro è: " << perimetro << endl;
  cout << "L'area è: " << area << endl;
  return 0;
}

