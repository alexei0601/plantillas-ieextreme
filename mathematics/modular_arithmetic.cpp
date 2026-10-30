
/*
    ==========================================
              MODULAR ARITHMETIC
    ==========================================

    DESCRIPCION:
        Realiza operaciones aritmeticas bajo
        un modulo determinado.

    COMPLEJIDAD:
        Tiempo: O(1) por operacion.
        Espacio: O(1)

    CUANDO UTILIZAR:
        - Resultados demasiado grandes.
        - Conteo de combinaciones.
        - Problemas de teoria de numeros.

    OBSERVACIONES:
        - MOD debe ser positivo.
        - Las operaciones normalizan los operandos.
        - La multiplicacion requiere que el producto
          quepa en long long.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1'000'000'007LL;

ll normalize(ll x) {
    return (x % MOD + MOD) % MOD;
}

ll modAdd(ll a, ll b) {
    return (normalize(a) + normalize(b)) % MOD;
}

ll modSub(ll a, ll b) {
    return (normalize(a) - normalize(b) + MOD) % MOD;
}

ll modMul(ll a, ll b) {
    return (normalize(a) * normalize(b)) % MOD;
}

int main() {
    ll a = 1'000'000'000;
    ll b = 900'000'000;

    cout << "Suma: " << modAdd(a, b) << '\n';
    cout << "Resta: " << modSub(a, b) << '\n';
    cout << "Multiplicacion: " << modMul(a, b) << '\n';

    return 0;
}
