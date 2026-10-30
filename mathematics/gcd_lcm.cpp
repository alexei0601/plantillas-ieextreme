
/*
    ==========================================
              GCD AND LCM
    ==========================================

    DESCRIPCION:
        Calcula el maximo comun divisor (GCD)
        y el minimo comun multiplo (LCM).

    COMPLEJIDAD:
        GCD: O(log(min(a, b)))
        LCM: O(log(min(a, b)))

    CUANDO UTILIZAR:
        - Problemas de divisibilidad.
        - Simplificacion de fracciones.
        - Periodos y multiplos comunes.

    OBSERVACIONES:
        - LCM puede producir overflow.
        - Se utiliza long long.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;

    return (a / gcd(a, b)) * b;
}

int main() {
    ll a = 24;
    ll b = 36;

    cout << "GCD: " << gcd(a, b) << '\n';
    cout << "LCM: " << lcm(a, b) << '\n';

    // Alternativa de C++17:
    cout << "std::gcd: " << std::gcd(a, b) << '\n';

    return 0;
}
