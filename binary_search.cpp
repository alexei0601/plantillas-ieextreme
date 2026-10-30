
/*
    ==========================================
                 BINARY SEARCH
    ==========================================

    DESCRIPCION:
        Busca elementos en un rango ordenado.

    ALGORITMOS:
        - Binary Search
        - lower_bound
        - upper_bound
        - binary_search

    COMPLEJIDAD:
        Tiempo: O(log n)
        Espacio: O(1) iterativo.

    REQUISITOS:
        El rango debe estar ordenado.

    APLICACIONES:
        - Buscar elementos.
        - Encontrar posiciones.
        - Buscar respuestas optimas.
*/

#include <bits/stdc++.h>
using namespace std;

// Binary Search manual
int binarySearch(const vector<int>& v, int target) {

    int left = 0;
    int right = (int)v.size() - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (v[mid] == target)
            return mid;

        if (v[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main() {

    vector<int> v = {1, 3, 5, 7, 9, 11, 13};

    int target = 7;

    // Busqueda manual
    cout << binarySearch(v, target) << '\n';

    // Comprobar existencia
    cout << binary_search(v.begin(), v.end(), target) << '\n';

    // Primer elemento >= target
    auto lb = lower_bound(v.begin(), v.end(), target);

    cout << "lower_bound: "
         << (lb - v.begin()) << '\n';

    // Primer elemento > target
    auto ub = upper_bound(v.begin(), v.end(), target);

    cout << "upper_bound: "
         << (ub - v.begin()) << '\n';

    return 0;
}
