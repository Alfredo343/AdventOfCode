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
//clase de la tabla Hash rolls
class RollsHash {
    private:
        static const size_t TABLE_SIZE = 100003;//damos un tamanyo inicial a la tabla
        vector<vector<Key>> table;//creamos la tabla usando el struct key
        Hasher hasher; //creamos el hasher usando el struct

    public:
        //inicializamos
        RollsHash() : table(TABLE_SIZE) {}

        //funcion insertar al final de la tabla
        void insert(const Key& k) {
            size_t idx = hasher(k) % TABLE_SIZE;
            for (const auto& e : table[idx]) {
                if (e == k) return; // ya existe
            }
            table[idx].push_back(k);
        }
        //comprobamos si clave existe o no
        bool count(const Key& k) const {
            size_t idx = hasher(k) % TABLE_SIZE;
            for (const auto& e : table[idx]) {
                if (e == k) return true;
            }
            return false;
        }
        //borra
        void erase(const Key& k) {
            size_t idx = hasher(k) % TABLE_SIZE;
            auto& bucket = table[idx];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (*it == k) {
                    bucket.erase(it);
                    return;
                }
            }
        }
        //Devuleve todos los elementos del vector (se usa para no tener que crear iteradores)
        vector<Key> getAll() const {
            vector<Key> result;
            for (const auto& bucket : table) {
                for (const auto& e : bucket) {
                    result.push_back(e);
                }
            }
            return result;
        }
};


int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);
    //creamos tabla hash nueva
    RollsHash rolls;

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
    //posiciones alrededor de un rollo
    const int dx[8] = {-1,-1,-1, 0,0, 1,1,1};
    const int dy[8] = {-1, 0, 1,-1,1,-1,0,1};

    int total_borrados = 0;

    while (true) {
        //creamos vector para almacenar posiciones a borrar
        vector<Key> remove;
        //creamos vector de los rollos que hay
        vector<Key> todos_rollos = rolls.getAll();

        // Buscar rollos accesibles en esta iteracion
        for (auto const& k : todos_rollos) {
            int cont = 0;
            for (int d = 0; d < 8; d++) {
                Key clave = {k.x + dx[d], k.y + dy[d]};
                if (rolls.count(clave)) {
                    cont++;
                }
            }
            if (cont < 4) {
                remove.push_back(k); //anyade al final del vector remove la coordenada
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