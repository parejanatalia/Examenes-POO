#include <iostream>

using namespace std;

/*
Sección A

1) B) int x = 10;
    // Declaro una variable entera y le asigno el valor 10 directamente.

2) B) 3 3.5
    // 7/2 es división entera que da 3, 7/2.0 es división con decimal que da 3.5.

3) B) 0 1 1
    // a&&b es falso (0), a||b es verdadero (1), !b es verdadero (1).

4) C) Entra al else porque if (x=0) asigna 0 y eso es falso.

5) B) El do-while siempre ejecuta al menos una vez antes de evaluar.

6) C) cin >> a >> b; lee dos enteros separados por espacio.

7) A) 11
    // Multiplica primero b*3=6 y suma a=5, total 11.

8) B) void f(int& n);
    // El parámetro con & pasa la variable por referencia.

9) B) continue salta a la siguiente iteración del ciclo.

10) A) (3 == 3) && !(2 > 5)
    // 3==3 es verdadero y 2>5 es falso, negado es verdadero, todo es true.
*/

int max3(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int sumaRango(int a, int b) {
    int suma = 0;
    for (int i = a; i <= b; i++) {
        suma += i;
    }
    return suma;
}

bool contieneDigito(int n, int d) {
    if (n == 0 && d == 0) return true;

    while (n > 0) {
        int digito = n % 10;
        if (digito == d) {
            return true;
        }
        n /= 10;
    }
    return false;
}



void tablaMultiplicar(int n) {
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
}

int main() {
    // Sección B
    // 1)
    int a1 = 5, b1 = 2;
    cout << a1 + b1 * 3 << endl;// Resultado: 11

    // 2)
    int n2 = 0;
    while (n2 < 3) {
        cout << n2 << " ";
        n2++;  // Resultado: 0 1 2
    }
    cout << endl;

    // 3)
    int x3 = 10;
    if (x3 % 2 == 0)
        cout << "par" << endl;
    else
        cout << "impar" << endl;   // Resultado: par

    // 4)
    int i4 = 3;
    do {
        cout << i4--;
    } while (i4 > 0);
    cout << endl;    // Resultado: 321

    // 5)
    int a5 = 1;
    int b5 = (a5++ > 1) ? 100 : 200;
    cout << a5 << " " << b5 << endl;       // Resultado: 2 200






    // Pruebas Sección C
    cout << "--- Pruebas de la Seccion C ---" << endl;
    cout << "max3(5, 9, 3) = " << max3(5, 9, 3) << endl;
    cout << "max3(10, 2, 7) = " << max3(10, 2, 7) << endl;
    cout << "max3(1, 1, 1) = " << max3(1, 1, 1) << endl;
    cout << "max3(-5, -2, -8) = " << max3(-5, -2, -8) << endl;
    cout << endl;



    cout << "sumaRango(1, 5) = " << sumaRango(1, 5) << endl;
    cout << "sumaRango(10, 10) = " << sumaRango(10, 10) << endl;
    cout << "sumaRango(0, 0) = " << sumaRango(0, 0) << endl;
    cout << "sumaRango(-2, 2) = " << sumaRango(-2, 2) << endl;
    cout << endl;


    cout << "contieneDigito(12345, 3) = " << (contieneDigito(12345, 3) ? "true" : "false") << endl;
    cout << "contieneDigito(987, 0) = " << (contieneDigito(987, 0) ? "true" : "false") << endl;
    cout << "contieneDigito(111, 1) = " << (contieneDigito(111, 1) ? "true" : "false") << endl;
    cout << "contieneDigito(0, 0) = " << (contieneDigito(0, 0) ? "true" : "false") << endl;
    cout << "contieneDigito(502, 5) = " << (contieneDigito(502, 5) ? "true" : "false") << endl;
    cout << endl;


    {

    }
    cout << "Tabla de multiplicar del 7:" << endl;
    tablaMultiplicar(7);
    cout << endl;

    cout << "Tabla de multiplicar del 12:" << endl;
    tablaMultiplicar(12);
    cout << endl;

    return 0;
}

