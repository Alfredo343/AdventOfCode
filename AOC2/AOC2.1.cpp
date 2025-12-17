#include <iostream>      
#include <sstream>      
#include <cstring>       
#include <cstdlib>      
using namespace std;

char* numToStr(long long n) {
    long long tmp = n;      
    int len;

    if (n == 0)              
        len = 1;
    else {
        len = 0;
        while (tmp) {        
            tmp /= 10;
            len++;
        }
    }

    char* s = new char[len + 1];  
    s[len] = '\0';               

    for (int i = len - 1; i >= 0; --i) {
        s[i] = '0' + (n % 10);   
        n /= 10;
    }

    return s;                    
}

bool Invalido(long long n) {
    char* s = numToStr(n);      
    int L = strlen(s);          

    if (L % 2 != 0) {             
        delete[] s;
        return false;
    }

    int half = L / 2;            

    char* bloque = new char[half + 1];
    strncpy(bloque, s, half);     
    bloque[half] = '\0';          

    bool esInvalido = (strncmp(s + half, bloque, half) == 0);

    delete[] bloque;              
    delete[] s;

    return esInvalido;            
}

int main() {
    string entrada;
    getline(cin, entrada);       

    stringstream ss(entrada);     
    string rango;

    unsigned long long suma = 0;  

   
    while (getline(ss, rango, ',')) {

        size_t pos = rango.find('-');    
        if (pos == string::npos)        
            continue;

        long long inicio = atoll(rango.substr(0, pos).c_str());
        long long fin    = atoll(rango.substr(pos + 1).c_str());

        if (inicio > fin) swap(inicio, fin); 

       
        for (long long i = inicio; i <= fin; ++i) {
            if (Invalido(i))
                suma += i;
        }
    }

    cout << suma << "\n";   
    return 0;
}
