#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

using namespace std;

// EJERCICIO 6: CONTAR SUBCADENA
int contar_subcadena(const char *cadena, const char *subcadena) {
    string c(cadena);
    string s(subcadena);
    int contador = 0;
    size_t pos = c.find(s, 0);
    while (pos != string::npos) {
        contador++;
        pos = c.find(s, pos + 1);
    }
    return contador;
}

// EJERCICIO 7: PUNTEROS A FUNCION (CALLBACKS)
int doble(int x) {
    return x * 2;
}

int cuadrado(int x) {
    return x * x;
}

void aplicar(int *a, size_t n, int (*op)(int)) {
    for (size_t i = 0; i < n; ++i) {
        a[i] = op(a[i]);
    }
}

// EJERCICIO 8: ARCHIVO + ESTRUCTURAS (SIMULADO)
typedef struct {
    char prod[32];
    int unidades;
    double precio;
} Venta;

vector<Venta> cargar_ventas_simuladas() {
    return {
        {"Pantalon", 10, 25.50},
        {"Camisa", 25, 15.00},
        {"Pantalon", 5, 25.50},
        {"Corbata", 50, 5.00},
        {"Camisa", 10, 15.00},
        {"Corbata", 20, 5.00}
    };
}

void procesar_ventas(const vector<Venta>& ventas) {
    if (ventas.empty()) return;

    double total_vendido = 0;
    int num_transacciones = ventas.size();
    map<string, int> unidades_por_producto;

    for (const auto& v : ventas) {
        double venta_total_item = v.unidades * v.precio;
        total_vendido += venta_total_item;
        unidades_por_producto[v.prod] += v.unidades;
    }

    string producto_mas_vendido = "";
    int max_unidades = -1;

    for (const auto& par : unidades_por_producto) {
        if (par.second > max_unidades) {
            max_unidades = par.second;
            producto_mas_vendido = par.first;
        }
    }

    double ticket_promedio = total_vendido / num_transacciones;

    cout << "\n8. ESTADISTICAS DE VENTAS:\n";
    cout << "Total vendido: $" << fixed << setprecision(2) << total_vendido << "\n";
    cout << "Producto mas vendido: " << producto_mas_vendido << " (" << max_unidades << " unidades)\n";
    cout << "Ticket promedio: $" << fixed << setprecision(2) << ticket_promedio << "\n";
}

int main() {
    cout << "--- EJECUCION DE LOS EJERCICIOS RESTANTES (6, 7, 8) ---\n\n";

    // --- EJERCICIO 6: CONTAR SUBCADENA ---
    cout << "6. CONTAR SUBCADENA:\n";
    const char *texto = "banana";
    const char *sub = "ana";
    int ocurrencias = contar_subcadena(texto, sub);
    cout << "Cadena: " << texto << ", Subcadena: " << sub << "\n";
    cout << "Ocurrencias: " << ocurrencias << "\n\n";

    // --- EJERCICIO 7: PUNTEROS A FUNCION (CALLBACKS) ---
    cout << "7. PUNTEROS A FUNCION (CALLBACKS):\n";
    int arreglo_c[] = {1, 2, 3, 4, 5};
    size_t n_c = 5;
    cout << "Arreglo inicial: ";
    for (size_t i = 0; i < n_c; ++i) cout << arreglo_c[i] << " ";
    cout << "\n";

    aplicar(arreglo_c, n_c, doble);
    cout << "Aplicar doble: ";
    for (size_t i = 0; i < n_c; ++i) cout << arreglo_c[i] << " ";
    cout << "\n";

    aplicar(arreglo_c, n_c, cuadrado);
    cout << "Aplicar cuadrado: ";
    for (size_t i = 0; i < n_c; ++i) cout << arreglo_c[i] << " ";
    cout << "\n\n";

    // --- EJERCICIO 8: ARCHIVO + ESTRUCTURAS (SIMULADO) ---
    vector<Venta> ventas = cargar_ventas_simuladas();
    procesar_ventas(ventas);

    return 0;
}
