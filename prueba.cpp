#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
    char nombre[40];
    int edad;
    double promedio;
} Estudiante;

void min_max_prom(const int *a, size_t n, int *minv, int *maxv, double *prom) {
    if (n == 0) return;

    *minv = *a;
    *maxv = *a;
    long long suma = 0;

    for (size_t i = 0; i < n; ++i) {
        int valor = a[i];

        suma += valor;
        if (valor < *minv) *minv = valor;
        if (valor > *maxv) *maxv = valor;
    }

    *prom = (double)suma / n;
}

void reverse(int *a, size_t i, size_t j) {
    while (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

void rotar_derecha(int *a, size_t n, size_t k) {
    if (n == 0 || (k % n) == 0) return;
    k %= n;

    reverse(a, 0, n - k - 1);
    reverse(a, n - k, n - 1);
    reverse(a, 0, n - 1);
}

size_t normalizar_espacios(const char *in, char *out, size_t outcap) {
    const char *src = in;
    char *dst = out;
    bool en_palabra = false;

    while (*src == ' ') { src++; }

    while (*src != '\0' && (size_t)(dst - out) < outcap - 1) {
        if (*src != ' ') {
            *dst++ = *src;
            en_palabra = true;
        } else {
            if (en_palabra) {
                *dst++ = ' ';
                en_palabra = false;
            }
        }
        src++;
    }

    if (dst > out && *(dst - 1) == ' ') { dst--; }

    *dst = '\0';
    return (size_t)(dst - out);
}

int **mat_crear(size_t m, size_t n) {
    int **A = new int *[m];
    if (A == nullptr) return nullptr;

    for (size_t i = 0; i < m; ++i) {
        A[i] = new int[n];
        if (A[i] == nullptr) {
            for (size_t j = 0; j < i; ++j) delete[] A[j];
            delete[] A;
            return nullptr;
        }
    }
    return A;
}

void mat_destruir(int **A, size_t m) {
    if (A == nullptr) return;
    for (size_t i = 0; i < m; ++i) delete[] A[i];
    delete[] A;
}

void mat_sumas(int **A, size_t m, size_t n, int *sumF, int *sumC) {
    for (size_t j = 0; j < n; ++j) sumC[j] = 0;

    for (size_t i = 0; i < m; ++i) {
        int suma_fila = 0;
        for (size_t j = 0; j < n; ++j) {
            int valor = A[i][j];
            suma_fila += valor;
            sumC[j] += valor;
        }
        sumF[i] = suma_fila;
    }
}

bool cmp_prom_desc_cpp(const Estudiante &a, const Estudiante &b) {
    return a.promedio > b.promedio;
}


int main() {
    cout << "-5 EJERCICIOS ( ---\n\n";


    cout << "1. ESTADÍSTICAS:\n";
    int datos1[] = {10, 5, 20, 15, 30};
    size_t n1 = 5;
    int min_val, max_val;
    double promedio_val;

    min_max_prom(datos1, n1, &min_val, &max_val, &promedio_val);

    cout << "Salida: min = " << min_val
         << ", max = " << max_val
         << ", prom = " << fixed << setprecision(2) << promedio_val << "\n\n";


    // --- 2. ROTACIÓN CIRCULAR ---
    cout << "2. Rotacion c\n";
    int arr2[] = {1, 2, 3, 4, 5};
    size_t n2 = 5;
    size_t k = 2;

    rotar_derecha(arr2, n2, k);

    cout << "Rotado (k=2): ";
    for (size_t i = 0; i < n2; ++i) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";


    // --- 3. Normalizar cadenas ---
    cout << "3. Normalizar cadenas :\n";
    const char *entrada3 = "  hola   mundo  c  ";
    char salida3[101];

    normalizar_espacios(entrada3, salida3, 101);
    cout << "Entrada: \"" << entrada3 << "\"\n";
    cout << "Salida:  \"" << salida3 << "\"\n\n";


    // --- 4. MATRIZ SUMA ---
    cout << "4. matriz suma:\n";
    size_t m = 3, n = 4;
    int **matriz4 = mat_crear(m, n);

    if (matriz4) {
        int datos_fijos[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}};
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                matriz4[i][j] = datos_fijos[i][j];
            }
        }

        int *sumF = new int[m];
        int *sumC = new int[n];
        if (sumF != nullptr && sumC != nullptr) {

            mat_sumas(matriz4, m, n, sumF, sumC);

            cout << "Sumas de Fila: ";
            for (size_t i = 0; i < m; ++i) cout << sumF[i] << " ";
            cout << "\n";

            cout << "Sumas de Columna: ";
            for (size_t i = 0; i < n; ++i) cout << sumC[i] << " ";
            cout << "\n\n";

            delete[] sumF;
            delete[] sumC;
        }

        mat_destruir(matriz4, m);
    }


    // --- 5. STRUCT + ESTUDIANTES ---
    cout << "5. struct + estudiantes :\n";
    Estudiante lista5[] = {
        {"Juan", 20, 8.5},
        {"Ana", 22, 9.8},
        {"Carlos", 19, 7.9},
        {"Maria", 21, 9.2}
    };
    size_t n5 = 4;

    sort(lista5, lista5 + n5, cmp_prom_desc_cpp);

    cout << "Lista ordenada (Top 3):\n";
    for (size_t i = 0; i < n5 && i < 3; ++i) {
        cout << "  " << i + 1 << ". " << lista5[i].nombre
             << " (" << fixed << setprecision(1) << lista5[i].promedio << ")\n";
    }

    return 0;
}
