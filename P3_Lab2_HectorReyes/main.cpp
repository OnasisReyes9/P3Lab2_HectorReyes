/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 23 de octubre de 2020, 03:28 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

/*
 * 
 */

double factorial(int);
double potencia(double, int);
double serie_de_taylor(double);
void factorizacion_de_potencias_de_numeros_primos(int);
void triangulo_de_pascal(int);

int main(int argc, char** argv) {
    bool continuar = true;
    int opcion = 0;
    while (continuar) {
        cout << "Menú" << endl
                << "0. Salir" << endl
                << "1. Ejercicio 1" << endl
                << "2. Serie de Taylor" << endl
                << "3. Triángulo de Pascal" << endl
                << "-> Seleccione el ejercicio que desea ejecutar: ";
        cin >> opcion;
        cout << "" << endl;
        switch (opcion) {
            case 1:
            {
                int numIngresado = 0;
                while (numIngresado <= 1) {
                    cout << "Ingrese un numero mayor que 1: ";
                    cin >> numIngresado;
                }
                cout << "" << endl;
                cout << numIngresado << " = ";
                factorizacion_de_potencias_de_numeros_primos(numIngresado);
                break;
            }
            case 2:
            {
                double valor_x;
                cout << "Ingrese x: ";
                cin >> valor_x;
                if (valor_x >= 0.0) {
                    cout << "e^" << valor_x << serie_de_taylor(valor_x) << endl;
                } else {
                    cout << "e^" << valor_x << " = " << 1 / serie_de_taylor(valor_x*-1.0) << endl;
                }//fin else
                break;
            }//fin case 2
            case 3:
            {
                int filas = 0;
                while (filas < 1) {
                    cout << "Ingrese número de filas: ";
                    cin >> filas;
                }
                triangulo_de_pascal(filas);
                break;
            }
            case 0:
            {
                cout << "La ejecución a finalizado." << endl;
                continuar = false;
                break;
            }
            default:
            {
                cout << "Opción inexistente." << endl << endl;
                break;
            }
        }//fin switch
    }//fin while
    return 0;
}//fin main

void factorizacion_de_potencias_de_numeros_primos(int numIngresado) {
    int numeroPotencia = 0;
    int size = 25;
    int numPrimos[size] = {2, 3, 5, 7, 11, 13, 17,
        19, 23, 29, 31, 37, 41,
        43, 47, 53, 59, 61, 67,
        71, 73, 73, 79, 83, 89, 97};
    for (int i = 0; 1 < numIngresado; i++) {
        numeroPotencia = 0;
        while (numIngresado % numPrimos[i] == 0) {
            numeroPotencia++;
            numIngresado /= numPrimos[i];
        }//fin while
        if (i == 0) {
            if (numeroPotencia != 0) {
                cout << numPrimos[i] << "^" << numeroPotencia;
            }
        } else {
            if (numeroPotencia != 0) {
                cout << " * " << numPrimos[i] << "^" << numeroPotencia;
            }//fin if
        }//fin else
    }//fin for
    cout << "" << endl << endl;
}//fin metodo

double serie_de_taylor(double valor_x) {
    double resultado = 0.0;
    for (int i = 0; i < 40; i++) {
        resultado +=
                potencia(valor_x, i) / factorial(i);
    }
    return resultado;
}

double factorial(int limite) {
    if (limite == 0) {
        return 1.0;
    } else {
        return limite * factorial(limite - 1);
    }
}

double potencia(double base, int exponente) {
    if (exponente == 0) {
        return 1.0;
    } else {
        return base * potencia(base, exponente - 1);
    }
}

void triangulo_de_pascal(int filas) {
    int arrTemp[filas];
    int arrTemp2[filas];
    for (int i = 0; i < filas; i++) {
        arrTemp[i] = 0;
        arrTemp2[i] = 0;
    }
    arrTemp[0] = 1;
    //cout << "1";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                arrTemp[i] = 1;
                cout << arrTemp[i];
                if (i == 0) {
                    cout << "" << endl;
                }
            } else if (j == i - 1) {
                arrTemp[i] = 1;
                cout << arrTemp[i] << endl;
            }
        }
    }
}