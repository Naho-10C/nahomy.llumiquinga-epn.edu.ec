#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <color.h>
using namespace std;

// Constantes globales
const int EGCEDULA = 1719529438;
const string EGNOMBRE_COMPLETO = "Esteban David Gómez Rocha";

// Estructura para la coordenada
struct egCoordenada
{
    int egCapacidadBelica;
    string egGeoLocalizacion;
    string egdetalleArsenal;
    egCoordenada *egIzquierda;
    egCoordenada *egDerecha;
};

// Función para crear un nuevo nodo de coordenada
egCoordenada *egCrearCoordenada(int egCap, string egGeo, string egDet)
{
    egCoordenada *egNuevaCoordenada = new egCoordenada;
    egNuevaCoordenada->egCapacidadBelica = egCap;
    egNuevaCoordenada->egGeoLocalizacion = egGeo;
    egNuevaCoordenada->egdetalleArsenal = egDet;
    egNuevaCoordenada->egIzquierda = NULL;
    egNuevaCoordenada->egDerecha = NULL;
    return egNuevaCoordenada;
}

// Función para insertar una coordenada en el árbol binario de búsqueda
egCoordenada *egInsertarCoordenada(egCoordenada *egRaiz, egCoordenada *egNuevaCoordenada)
{
    // Si la raíz es NULL, se inserta la coordenada como la raíz
    if (egRaiz == NULL)
    {
        return nuevaCoordenada;
    }
    // Si la capacidad bélica de la nueva coordenada es menor que la raíz,
    // se inserta en el subárbol izquierdo
    if (egNuevaCoordenada->egCapacidadBelica < egRaiz->egCapacidadBelica)
    {
        egRaiz->egIzquierda = egInsertarCoordenada(egRaiz->egIzquierda, egNuevaCoordenada);
    }
    // Si la capacidad bélica de la nueva coordenada es mayor que la raíz,
    // se inserta en el subárbol derecho
    else if (egNuevaCoordenada->egCapacidadBelica > egRaiz->egCapacidadBelica)
    {
        egRaiz->egDerecha = egInsertarCoordenada(egRaiz->egDerecha, egNuevaCoordenada);
    }
    // Si la capacidad bélica es igual, se descarta la coordenada duplicada
    return egRaiz;
}

// Función para leer el egArchivo de coordenadas
void leerCoordenadas()
{
    ifstream egArchivo("egCoordenadas.txt");
    string egLinea;
    int egContador = 0;
    int egCapacidadTotal = 0;
    egCoordenada *egRaiz = NULL;
    while (getline(egArchivo, egLinea))
    {
        // Mostrar loading de carga
        cout << "Loading: " << egContador << "%" << endl;
        // Comprobar si la línea es una coordenada
        stringstream ss(egLinea);
        int egCap;
        string egGeo, egDet;
        if (!(ss >> egCap >> egGeo >> egDet))
            ;
        {
            // Si la línea no es una coordenada, se ignora
            continue;
        }
        // Crear una nueva coordenada
        egCoordenada *egNuevaCoordenada = egCrearCoordenada(egCap, egGeo, egDet);
        // Insertar la coordenada en el árbol binario de búsqueda
        egRaiz = egInsertarCoordenada(egRaiz, egNuevaCoordenada);
        // Actualizar la capacidad total
        egCapacidadTotal += egCap;
        egContador++;
    }
    // Mostrar la capacidad total y la cantidad de coordenadas
    cout << "Capacidad total: " << egCapacidadTotal << endl;
    cout << "Cantidad de coordenadas: " << egContador << endl;
}
// Mostrar el total de la capacidad y la cantidad de coordenadas
cout << "Capacidad total: " << egCapacidadTotal << endl;
cout << "Cantidad de coordenadas: " << egContador << endl;
// Cerrar el egArchivo
egArchivo.close();
}

// Función para mostrar la información adicional del árbol binario de búsqueda
void mostrarInformacion(egCoordenada *egRaiz)
{
    // Calcular la capacidad total del árbol binario de búsqueda
    int egCapacidadTotal = 0;
    egCalcularCapacidadTotal(egRaiz, &egCapacidadTotal);

    // Mostrar información del desarrollador
    cout << "Developer-Nombre: " << EGNOMBRE_COMPLETO << endl;
    cout << "Developer-Cedula: " << EGCEDULA << endl;
    cout << "Capacidad Bélica: " << egCapacidadTotal << endl;

    // Mostrar información de las coordenadas
    int egCantidadCoordenadas = 0;
    egCoordenada *egCoordenadas[MAX_COORDENADAS];
    egSecuenciaCargaCoordenadas(egRaiz, egCoordenadas, &egCantidadCoordenadas);
    cout << "Coordenada-Total: " << egCantidadCoordenadas << endl;

    // Mostrar la secuencia de carga de las coordenadas
    int egSumaSecuencia = 0;
    for (int i = 0; i < egCantidadCoordenadas; i++)
    {
        cout << "Coordenada-SecCarga[" << i << "]: " << egCoordenadas[i]->egCapacidadBelica << endl;
        egSumaSecuencia += egCoordenadas[i]->egCapacidadBelica;
    }

    // Validar que la suma de la secuencia de carga sea igual a la capacidad total
    if (egSumaSecuencia == egCapacidadTotal)
    {
        cout << "La suma de la secuencia de carga es igual a la capacidad total." << endl;
    }
    else
    {
        cout << "Error: La suma de la secuencia de carga no es igual a la capacidad total." << endl;
    }
}

// Función recursiva para calcular la capacidad total del árbol binario de búsqueda
void egCalcularCapacidadTotal(egCoordenada *egRaiz, int *egCapacidadTotal)
{
    if (egRaiz != NULL)
    {
        *egCapacidadTotal += egRaiz->egCapacidadBelica;
        egCalcularCapacidadTotal(egRaiz->egIzquierda, egCapacidadTotal);
        egCalcularCapacidadTotal(egRaiz->egDerecha, egCapacidadTotal);
    }
}
// Función recursiva para almacenar la secuencia de carga de las coordenadas en un arreglo
void egSecuenciaCargaCoordenadas(egCoordenada *egRaiz, egCoordenada *egCoordenadas[], int *egCantidadCoordenadas)
{
    if (egRaiz != NULL)
    {
        // Verificar que la coordenada no se encuentre en el arreglo
        bool egCoordenadaRepetida = false;
        for (int i = 0; i < *egCantidadCoordenadas; i++)
        {
            if (egRaiz == egCoordenadas[i])
            {
                egCoordenadaRepetida = true;
                break;
            }
        }

        if (!egCoordenadaRepetida)
        {
            egCoordenadas[*egCantidadCoordenadas] = egRaiz; // Almacenar la coordenada en el arreglo
            (*egCantidadCoordenadas)++;                     // Aumentar la cantidad de coordenadas almacenadas en el arreglo
        }

        // Llamar recursivamente la función para almacenar la secuencia de carga de las coordenadas en el arreglo
        egSecuenciaCargaCoordenadas(egRaiz->egIzquierda, egCoordenadas, egCantidadCoordenadas);
        egSecuenciaCargaCoordenadas(egRaiz->egDerecha, egCoordenadas, egCantidadCoordenadas);
    }

    int main()
    {
        // Verificar autorización
        int egCedulaAutorizada;
        string egNombreCompletoAutorizado;
        cout << "Ingrese su cédula: ";
        cin >> egCedulaAutorizada;
        cout << "Ingrese su nombre completo: ";
        cin.ignore();
        getline(cin, egNombreCompletoAutorizado);
        if (egCedulaAutorizada == EGCEDULA && egNombreCompletoAutorizado == EGNOMBRE_COMPLETO)
        {
            // Si está autorizado, leer el archivo de coordenadas
            leerCoordenadas();
        }
        else
        {
            cout << "No está autorizado para ejecutar este programa." << endl;
        }
        return 0;
    }
