#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> grid;
    string linea;

    while (cin >> linea) {
        grid.push_back(linea);
    }

    int filas = grid.size();
    int columnas = grid[0].size();

    int resultado = 0;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            if (grid[i][j] != '@') continue;

            int vecinos = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {

                    if (di == 0 && dj == 0) continue;

                    int ni = i + di;
                    int nj = j + dj;

                    if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas) {
                        if (grid[ni][nj] == '@') vecinos++;
                    }
                }
            }

            if (vecinos < 4) resultado++;
        }
    }

    cout << resultado<<endl;
}