#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

struct Key {
    int x, y;
    bool operator==(Key const& o) const {
        return x == o.x && y == o.y;
    }
};

struct Hasher {
    size_t operator()(Key const& k) const {
        return ((long long)k.x << 32) ^ (long long)k.y;
    }
};

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<Key, Hasher> rolls;

    string line;
    int y = 0;
    while (getline(cin, line)) {
        for (int x = 0; x < (int)line.size(); x++) {
            if (line[x] == '@') {
                rolls.insert({x,y});
            }
        }
        y++;
    }

    const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    int total_borrados = 0;

    while (true) {
        vector<Key> remove;

        // Buscar rollos accesibles en esta iteración
        for (auto const& k : rolls) {
            int cont = 0;
            for (int d = 0; d < 8; d++) {
                Key clave = {k.x + dx[d], k.y + dy[d]};
                if (rolls.count(clave)) {
                    cont++;
                }
            }
            if (cont < 4) {
                remove.push_back(k); //añade al final del vector remove la coordenada
            }
        }

        if (remove.empty()){
            break; // no hay mas rollos accesibles
        }

        // Eliminar rollos accesibles
        for (auto const& k : remove) {
            rolls.erase(k); //recorre el vector remove y borra los rolls que hay en el vector del la matriz rolls
        }

        total_borrados += remove.size(); //almacena la cantidad de rollos borrados
    }

    cout << total_borrados << "\n";
}