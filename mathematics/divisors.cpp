
/*
    ==========================================
                  DIVISORS
    ==========================================

    DESCRIPCION:
        Encuentra todos los divisores positivos
        de un numero entero.

    COMPLEJIDAD:
        Tiempo: O(sqrt(N) + D log D)
        Espacio: O(D)

    CUANDO UTILIZAR:
        - Problemas de divisibilidad.
        - Conteo de divisores.
        - Teoria de numeros.

    OBSERVACIONES:
        - Solo acepta enteros positivos.
        - Los divisores se devuelven ordenados.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> getDivisors(ll n) {
    vector<ll> divisors;

    if (n <= 0) return divisors;

    for (ll i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }

    sort(divisors.begin(), divisors.end());

    return divisors;
}

int main() {
    ll n = 36;

    vector<ll> divisors = getDivisors(n);

    cout << "Divisores de " << n << ":\n";

    for (ll d : divisors) {
        cout << d << " ";
    }

    cout << "\nCantidad: " << divisors.size() << '\n';

    return 0;
}
