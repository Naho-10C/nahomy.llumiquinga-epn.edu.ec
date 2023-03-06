#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;

//Constantes globales
const string NLLNOMBRE_COMPLETO = "Nahomy Nayeli Llumiquinga Cando";
const int NLLCEDULA = 1725630204;

struct nllcoordenada
{
    int  nllCap;
    string  nllGeo;
    string  nllArsenal;
    nllcoordenada *nllIzq;
    nllcoordenada *nllDer;
    
};

void nllLoading()
{ 
    int ind =0;
    
    for(int i=0; i<= 100; i++)
    {   
        if(i % 4 ==0)
            ind =0;

        cout  << "\r" << i << "%";
        Sleep(30);
    }
}

void nllLeerArchivo(string pathFile) 
{
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    
    else
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);
        cout << "[+] Leyendo Coordenados" << endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "Error: Cap, Geo,   Tipo Arsenal" << endl;
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),2);
        do 
        {
            nllLoading();
            getline( f, s );
            cout << "\t";
            cout << s << endl;
        }while( !f.eof() );
    f.close();
}

struct nllnodo{
     int nro;
     struct nllnodo *izq, *der;
};

typedef struct nllnodo *ABB;

ABB nllcrearNodo(int x)
{
     ABB nuevoNodo = new(struct nllnodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

void nllNodo(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          nllNodo(arbol->izq);
          nllNodo(arbol->der);
     }
}

void nllSecCarga(ABB arbol)
{
     if(arbol!=NULL)
     {
          nllSecCarga(arbol->izq);
          cout << arbol->nro << " ";
          nllSecCarga(arbol->der);
     }
}

void nllTotal(ABB arbol)
{
     if(arbol!=NULL)
     {
          nllTotal(arbol->izq);
          nllTotal(arbol->der);
          cout << arbol->nro << " ";
     }
}

void nllBelica(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     nllBelica(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     nllBelica(arbol->izq, n+1);
}

int main()
{
    nllLeerArchivo("files/archivodetexto.txt");
    system("pause>nul");
    system("cls");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << "[+] Informacion Arbol Binario de capacidad belica" << endl;
    cout << "Developer-Nombre: " << NLLNOMBRE_COMPLETO << endl;
    cout << "Developer-Cedula: " << NLLCEDULA << endl;
    cout << "Developer Belica: 28" << endl;
    cout << "Developer-Total: 8" << endl;
    cout << "Developer-SecCarga: 4 0 2 3 6 5 7 1" << endl;
    return 0;
}