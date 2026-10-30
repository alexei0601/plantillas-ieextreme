
/*
    ==========================================
             PRIME FACTORIZATION
    ==========================================

    DESCRIPCION:
        Descompone un numero en sus factores
        primos y sus respectivos exponentes.

    COMPLEJIDAD:
        Tiempo: O(sqrt(N))
        Espacio: O(log N)

    CUANDO UTILIZAR:
        - Problemas de divisibilidad.
        - Calculo de divisores.
        - Teoria de numeros.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<pair<ll, int>> primeFactorization(ll n) {
    vector<pair<ll, int>> factors;

    if (n <= 0) return factors;

    for (ll p = 2; p <= n / p; p++) {
        if (n % p == 0) {
            int exponent = 0;

            while (n % p == 0) {
                n /= p;
                exponent++;
            }

            factors.push_back({p, exponent});
        }
    }

    if (n > 1) {
        factors.push_back({n, 1});
    }

    return factors;
}

int main() {
    ll n = 360;

    vector<pair<ll, int>> factors =
        primeFactorization(n);

    cout << n << " = ";

    for (int i = 0; i < (int)factors.size(); i++) {
        auto [prime, exponent] = factors[i];

        cout << prime << "^" << exponent;

        if (i + 1 < (int)factors.size()) {
            cout << " * ";
        }
    }

    cout << '\n';

    return 0;
}
