/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on 17 ottobre 2022, 15:14
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int a,b;
    cout << "Inserire il primo addendo: ";
    cin >> a;
    cout << "Inserire il secondo addendo: ";
    cin >> b;
    int s = a + b;
    cout << "La somma è: " << s << endl;
    return 0;
}

