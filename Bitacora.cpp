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

// Ordenar por fecha
void Bitacora::ordenar() {
    sort(logs.begin(), logs.end(), [](const Log& a, const Log& b) {
        return a.dateNum < b.dateNum;
        });
}

// Guardar en archivo
void Bitacora::guardarArchivo(const string& nameFile) {
    ofstream salida(nameFile);
    if (!salida) {
        cout << "No se pudo crear el archivo: " << nameFile << endl;
        return;
    }
    for (const auto& l : logs) {
        salida << l.month << " " << l.day << " " << l.time << " " << l.ip << l.motive << "\n";
    }
    salida.close();
}

// Mostrar todo
void Bitacora::showAll() {
    for (const auto& l : logs) {
        l.show();
    }
}

void Bitacora::mostrarAccesosPorIPDesc() const {
    vector<string> ips;
    ips.reserve(logs.size());
    for (size_t i = 0; i < logs.size(); ++i) {
        ips.push_back(logs[i].ip);
    }

    sort(ips.begin(), ips.end()); // agrupa iguales

    vector<pair<string, int> > ranking;
    ranking.reserve(ips.size());

    // contar rachas
    for (size_t i = 0; i < ips.size(); ) {
        size_t j = i + 1;
        while (j < ips.size() && ips[j] == ips[i]) ++j;
        ranking.push_back(make_pair(ips[i], static_cast<int>(j - i)));
        i = j;
    }

    // ordenar por conteo desc, empate por IP asc
    sort(ranking.begin(), ranking.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) return a.second > b.second; // desc
            return a.first < b.first; // empate: IP asc
        });

    cout << "\n=== Accesos por IP (desc) ===\n";
    for (size_t k = 0; k < ranking.size(); ++k) {
        const pair<string, int>& p = ranking[k];
        cout << p.first << " -> " << p.second << '\n';
    }
}


// Buscar por rango
void Bitacora::buscarPorRango(const string& monthI, unsigned int dayI, const string& timeI,
    const string& monthF, unsigned int dayF, const string& timeF) const {
    long long date_I = Log::change2date(monthI, dayI, timeI);
    long long date_F = Log::change2date(monthF, dayF, timeF);

    cout << "\n=== Registros en el rango ===\n";
    for (const auto& l : logs) {
        if (l.dateNum >= date_I && l.dateNum <= date_F) {
            l.show();
        }
    }
}
