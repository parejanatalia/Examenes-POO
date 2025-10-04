#include <iostream>

using namespace std;

int main() {

    // --- Pregunta 1.1: Tipos de Datos Básicos


    int edad = 21;
    int numero = 12;


    float altura = 1.75f;
    float pi = 3.14f; // float: para números con decimales (la f es necesaria).


    char inicial_nombre  = 'J';
    char inicial_apellido = 'P'; // char: para un solo carácter.


    cout << "--- 1.1 Tipos de Datos ---\n";


    cout << "Entero (edad): " << edad << "    " << "numero: " << numero << endl;


    cout << "Flotante (altura): " << altura << " " << " Numero de pi: " << pi << endl;

    cout << "Carácter o inicial de su nombre :" << inicial_nombre << "    "  << "inicial de su apellido :" << inicial_apellido << endl;

    // P1.2: Diferencias de tipos
    /*
    int: Enteros.  para contar, edades, índices.
    float: Decimales. Recomendable para mediciones no tan "exactas" (poca prescion media) double es para mayor precision.
    char: Un solo carácter. Recomendable para letras o símbolos.
    */

    // -----------------------------------------------


    int num1, num2;
    cout << "\n 2.1 Operadores Aritméticos \n";
    cout << "Ingresa dos números enteros:\n";
    cout << "Número 1: ";
    cin >> num1;
    cout << "Número 2: ";
    cin >> num2;

    cout << "Suma: " << num1 + num2 << endl;
    cout << "Resta: " << num1 - num2 << endl;
    cout << "Multiplicación: " << num1 * num2 << endl;


    if (num2 != 0) {
        // Conversión a float    para obtener decimales en la división
        cout << "División: " << (float)num1 / num2 << endl;
        cout << "Módulo: " << num1 % num2 << endl;
    } else {
        cout << "División y Módulo: Error (división por cero).\n";

    }

    // P2.2: Operadores de Comparación
    /*
    == : Revisa si dos valores son IGUALES.
    (Ej: 5 == 5 -> true).
    != : Revisa si dos valores son DIFERENTES.
     (Ej: 5 != 10 -> true).
    */




    //P2.3: Operadores Lógicos
    /*
    && (AND): Es true si AMBAS condiciones son true.

     (Ej: edad > 18 && saldo > 0)

    || (OR): true si AL MENOS UNA condición es true.

     (Ej: dia == 'S' || dia == 'D'), depemdiendo tambien del caracteer


    ! (NOT): Invierte el valor booleano (true pasa a false). (Ej: !esAdmin) si no lo es
    */

    // --------------------------------------------


    cout << "\n  3.1 Estructura if-else \n";
    cout << "Ingresa tu edad para verificar mayoría de edad: ";
    cin >> edad; // volvi a utilizar la variable edad

    if (edad >= 18) {


        cout << "Eres mayor de edad \n";
    } else {
        cout << "Eres menor de edad. \n";
    }



    // P3.2: Estructura else if
    /*

    else if: Se usa para verificar varias condiciones , solo si las
    anteriores fueron falsas.
    Se evalúa segun la secuencia, y solo se ejecuta un bloque.

    Ejemplo (Clasificación de Notas):
    if (nota >= 90) { .. }
    else if (nota >= 80) { .... } // Solo se revisa si nota < 90
    else { ... }
    */

    // --------------------------------------------------------------


    cout << "\n--- 4.1 Bucle for (1 a 10) ---\n";
    // (Inicialización; Condición; Incremento)
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }

    cout << endl;


    // 4.2: Bucle while (10 a 1)
    cout << "\n- 4.2 Bucle while (10 a 1) --\n";
    int contador = 10; // Inicialización

    while (contador >= 1) { // Condición....

        cout << contador << " ";
        contador--; // "Decremento"
    }
    cout << endl;

    //      4.3:  Bucle do-while (Pares entre 1 y 20)

    cout << "\n  4.3 Bucle do-while (Pares 1-20)  \n";
    int par = 2;
    do {
        cout << par << " ";
        par += 2; // Incrementar de 2 en 2
    } while (par <= 20); // La condición se evalúa al final, y se ejecuta al menos una sola vez
    cout << endl;

    // ======================================
    // 2: Estructuras de Datos (Arrays)
    // ===============================================

    // 5.1: Array Unidimensional

    const int TAMAÑO_ARRAY = 5;

    int arrayUnid[TAMAÑO_ARRAY]; // Declaración de array de 5 enteros

    cout << "\n--- 5.1 Array Unidimensional ---\n";

    cout << "Ingresa " << TAMAÑO_ARRAY << " números para el array:\n";

    // Llenar el array
    for (int i = 0; i < TAMAÑO_ARRAY; i++) {

        cout << "Elemento " << i << ": ";

        cin >> arrayUnid[i];
    }


    cout << "Valores ingresados: ";
    for (int i = 0; i < TAMAÑO_ARRAY; i++) {
        cout << arrayUnid[i] << (i == TAMAÑO_ARRAY - 1 ? "" : ", ");
    }
    cout << endl;



    // P5.2: Array Bidimensional
    /*


    Array Bidimensional: Es una matriz ( otabla) de filas y columnas.
    Se accede con dos índices: [fila][columna].


    Ejemplo:
    int matriz2x3[2][3];

    int valor = matriz2x3[0][1]; // Va a la Fila 0, Columna 1
    */

    // 5.3: Suma de Array Bidimensional 3x3
    int matriz3x3[3][3] = { // Array 3x3 inicialisado
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int sumaTotal = 0;

    cout << "\n    5.3 Suma de Array Bidimensional    \n";
    cout << "Matriz inicialisada:\n";

    // Bucle para recorrer Filas (i) y Columnas (j)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumaTotal += matriz3x3[i][j]; // Sumar el elemento actual
            cout << matriz3x3[i][j] << " ";
        }
        cout << endl;

    }

    cout << "La suma de todos los elementos es: " << sumaTotal << endl; // Debe  de ser 45


    return 0;
}}
