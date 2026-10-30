
/*
    ==========================================
                 COMBINATORICS
    ==========================================

    DESCRIPCION:
        Calcula coeficientes binomiales C(n, k)
        utilizando factoriales e inversos modulares.

    COMPLEJIDAD:
        Preprocesamiento: O(N)
        Consulta: O(1)
        Espacio: O(N)

    CUANDO UTILIZAR:
        - Problemas de conteo.
        - Permutaciones y combinaciones.
        - Conteo de subconjuntos.

    REQUISITOS:
        - MOD debe ser primo.
        - N debe ser menor que MOD.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007LL;
const int MAXN = 1'000'000;

ll fact[MAXN + 1];
ll invFact[MAXN + 1];

ll modPow(ll base, ll exp) {
    ll result = 1;

    while (exp > 0) {
        if (exp & 1) {
            result = result * base % MOD;
        }

        base = base * base % MOD;
        exp >>= 1;
    }

    return result;
}

void precompute() {
    fact[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[MAXN] = modPow(fact[MAXN], MOD - 2);

    for (int i = MAXN; i >= 1; i--) {
        invFact[i - 1] = invFact[i] * i % MOD;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n || n > MAXN) {
        return 0;
    }

    return fact[n] * invFact[r] % MOD
           * invFact[n - r] % MOD;
}

int main() {
    precompute();

    cout << "C(5, 2) = " << nCr(5, 2) << '\n';
    cout << "C(10, 3) = " << nCr(10, 3) << '\n';
    cout << "C(100, 50) = " << nCr(100, 50) << '\n';

    return 0;
}
