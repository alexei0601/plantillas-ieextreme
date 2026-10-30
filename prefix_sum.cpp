
/*
    ==========================================
                   PREFIX SUM
    ==========================================

    DESCRIPCION:
        Almacena sumas acumuladas.

    COMPLEJIDAD:
        Construccion: O(n)
        Consulta: O(1)
        Espacio: O(n)

    APLICACIONES:
        - Sumas de rangos.
        - Consultas repetidas.
        - Subarreglos.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> buildPrefix(const vector<int>& v) {

    int n = v.size();

    vector<ll> pref(n + 1, 0);

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + v[i];

    return pref;
}

// Suma del intervalo [l, r]
ll rangeSum(const vector<ll>& pref, int l, int r) {

    return pref[r + 1] - pref[l];
}

int main() {

    vector<int> v = {2, 4, 6, 8, 10};

    vector<ll> pref = buildPrefix(v);

    // Suma de posiciones 1 a 3
    cout << rangeSum(pref, 1, 3) << '\n';

    // Suma de todo el arreglo
    cout << rangeSum(pref, 0, 4) << '\n';

    return 0;
}
