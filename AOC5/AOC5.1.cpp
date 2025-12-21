#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//Comprobamos si una cadena es un numero valido
bool isNumber(const string &s) {
    if (s.empty()) return false;//esta vacia = false
    for (char c : s) {
        if (!isdigit(c) && c != '-') return false;
    }
    return true;
}

// Lee los rangos desde la entrada estándar
vector<pair<long long, long long>> readRanges() {
    vector<pair<long long, long long>> ranges;
    string line;

    while (getline(cin, line)) {
        //leemos la linea
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        //si esta vacia paramos
        if (line.empty())
            break;
        //buscamos el guión
        size_t dash = line.find('-');
        if (dash == string::npos)
            continue;//noi guión = linea no valida
        //extraemos cada parte del rango
        string aStr = line.substr(0, dash);
        string bStr = line.substr(dash + 1);
        //¿son numeros?
        if (!isNumber(aStr) || !isNumber(bStr))
            continue;
        //pasamos de cadena a numero
        long long a = stoll(aStr);
        long long b = stoll(bStr);
        //aseguramos que esten en orden
        if (a > b) swap(a, b);
        ranges.emplace_back(a, b);
    }
    //ordenamos
    sort(ranges.begin(), ranges.end());
    return ranges;
}

// Fusiona rangos que se solapan
vector<pair<long long, long long>> mergeRanges(const vector<pair<long long, long long>> &ranges) {
    vector<pair<long long, long long>> merged;
    //recorremos rangos
    for (const auto &r : ranges) {
        //no rangos o no solape
        if (merged.empty() || r.first > merged.back().second + 1) {
            merged.push_back(r);//añadir
        //solapa
        } else {
            //fusionamos
            merged.back().second = max(merged.back().second, r.second);
        }
    }
    return merged;
}

// Cuenta los IDs que están dentro de los rangos fusionados
long long countFreshIDs(const vector<pair<long long, long long>> &merged) {
    long long freshCount = 0;
    string line;
    //leemos IDs
    while (getline(cin, line)) {
        if (line.empty())
            continue;
        //convertimos la liena a numero
        long long id = stoll(line);
        //buscamos de forma binaria para saber si el ID es algun rango
        int left = 0, right = (int)merged.size() - 1;
        bool fresh = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (id < merged[mid].first) {
                right = mid - 1;
            } else if (id > merged[mid].second) {
                left = mid + 1;
            } else {
                //ID dentro de rango
                fresh = true;
                break;
            }
        }
        //pertenece a un rango, le añadimos 1
        if (fresh)
            freshCount++;
    }

    return freshCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto ranges = readRanges(); //leemos rangoa que entran
    auto merged = mergeRanges(ranges); //guarda los rangos fusionados
    long long freshCount = countFreshIDs(merged); //guarda la cantidad de alimentos frescos

    cout << freshCount << "\n";

    return 0;
}

