
/*
    ==========================================
             FAST EXPONENTIATION
    ==========================================

    DESCRIPCION:
        Calcula a^b mediante exponenciacion binaria.

    COMPLEJIDAD:
        Tiempo: O(log B)
        Espacio: O(1) iterativa.

    CUANDO UTILIZAR:
        - Calculo de potencias grandes.
        - Aritmetica modular.
        - Recurrencias y problemas matematicos.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fastPow(ll base, ll exp) {
    ll result = 1;

    while (exp > 0) {
        if (exp & 1) {
            result *= base;
        }

        base *= base;
        exp >>= 1;
    }

    return result;
}

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1 % mod;
    base %= mod;

    while (exp > 0) {
        if (exp & 1) {
            result = (__int128)result * base % mod;
        }

        base = (__int128)base * base % mod;
        exp >>= 1;
    }

    return result;
}

int main() {
    cout << "2^10 = " << fastPow(2, 10) << '\n';

    cout << "2^100 mod 1000000007 = "
         << modPow(2, 100, 1'000'000'007LL) << '\n';

    return 0;
}
