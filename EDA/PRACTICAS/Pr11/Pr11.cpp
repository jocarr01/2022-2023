// Jonathan Alberto Carrera Santamaria
// V10


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
void resolver(int numPersonas) {
    int alturas[100000];
    bool dalton = true;

    for (int i = 0; i < numPersonas; i++)
        std::cin >> alturas[i];

    int j = 0;
    if (alturas[0] < alturas[1]) {
        while (dalton && j < numPersonas - 1) {
            if (alturas[j] < alturas[j + 1])
                j++;
            else
                dalton = false;
        }
    }
    else if (alturas[0] > alturas[1]) {
        while (dalton && j > numPersonas - 1) {
            if (alturas[j] > alturas[j + 1])
                j++;
            else
                dalton = false;
        }
    }

    if (dalton)
        std::cout << "DALTON" << "\n";
    else
        std::cout << "DESCONOCIDOS" << "\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPersonas = 0;
    std::cin >> numPersonas;

    if (numPersonas == 0)
        return false;
    else {
        resolver(numPersonas);
        return true;
    }
}

//#define DOMJUDGE

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
        std::ifstream in("datos.txt");
        auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    #endif 

        while (resuelveCaso()) { ; }
       


    // Para restablecer entrada. Comentar para acepta el reto
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
        std::cin.rdbuf(cinbuf);
        system("PAUSE");
    #endif

    return 0;
}