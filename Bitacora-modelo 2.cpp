//Bitacora.cpp Se definen las funciones de bitacora
#include "Bitacora.h"

using namespace std;

// Leer archivo
void Bitacora::leerArchivo(const string& nameFile) {
    ifstream file(nameFile);
    if (!file) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string month, time, ip, motive;
    unsigned int day;

    while (file >> month >> day >> time >> ip) {
        getline(file, motive);
        logs.push_back(Log(month, day, time, ip, motive));
    }

    file.close();
}
void Bitacora::ordenar() {
    sort(logs.begin(), logs.end(), [](const Log& a, const Log& b) {
        return a.ip < b.ip;
        });
}


// Mostrar todo
void Bitacora::showAll() {
    for (const auto& l : logs) {
        l.show();
    }
}



