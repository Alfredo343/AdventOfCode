#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Función que calcula el máximo joltage de un banco usando DP
long long maxJoltage(const string &bank) {
    int n = bank.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(3, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        int digit = bank[i] - '0';
        for (int k = 0; k <= 2; ++k) {
            if (dp[i][k] != -1) {
                // No tomar el dígito
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
                // Tomar el dígito si k < 2
                if (k < 2) {
                    dp[i + 1][k + 1] = max(dp[i + 1][k + 1], dp[i][k] * 10 + digit);
                }
            }
        }
    }

    return dp[n][2]; // máximo con 2 dígitos activados
}

// Función que lee todos los bancos desde la entrada estándar
vector<string> leerBancos() {
    vector<string> bancos;
    string line;
    while (getline(cin, line)) {
        if (!line.empty())
            bancos.push_back(line);
    }
    return bancos;
}

// Función que calcula el total de joltage sumando todos los bancos
long long totalJoltage(const vector<string> &bancos) {
    long long total = 0;
    for (const auto &bank : bancos) {
        total += maxJoltage(bank);
    }
    return total;
}

int main() {
    auto bancos = leerBancos();           // Leer entrada
    long long total = totalJoltage(bancos); // Calcular total
    cout << total << endl;                  // Imprimir resultado
    return 0;
}

