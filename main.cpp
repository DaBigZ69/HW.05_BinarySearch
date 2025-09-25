//Main HW.07
/*
Gerardo Alberto Mendoza Castillo A01666338
Fabian Lopez Perez A01661836
*/
#include "Bitacora.h"
#include <iostream>

using namespace std;

int main() {
    Bitacora bit;
    string file_name;
    cout << "Inserte el nombre del archivo: ";
    cin >> file_name;

    bit.leerArchivo(file_name);
    bit.ordenar();
    bit.guardarArchivo("bitacora_ordenada.txt");
    cout << "Archivo ordenado guardado como bitacora_ordenada.txt\n";

    string monthI, monthF, timeI, timeF;
    unsigned int dayI, dayF;
    cout << "Ingresa fecha de inicio (Mes Dia Hora hh:mm:ss): ";
    cin >> monthI >> dayI >> timeI;
    cout << "Ingresa fecha de fin (Mes Dia Hora hh:mm:ss): ";
    cin >> monthF >> dayF >> timeF;

    bit.buscarPorRango(monthI, dayI, timeI, monthF, dayF, timeF);

    return 0;
}