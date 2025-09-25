//Bitacora.h aqui se crea la clase bitacora que lee el documento usando la información buscada por los registros
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Log.h"

using namespace std;

class Bitacora {
private:
    vector<Log> logs;

public:
    void leerArchivo(const string& nameFile);
    void ordenar();
    void guardarArchivo(const string& nameFile);
    void showAll();
    void mostrarAccesosPorIPDesc() const;
    void buscarPorRango(const string& monthI, unsigned int dayI, const string& timeI,
        const string& monthF, unsigned int dayF, const string& timeF) const;
};
