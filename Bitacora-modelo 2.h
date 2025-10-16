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
    void showAll();
    void ordenar();
};
