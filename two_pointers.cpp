
/*
    ==========================================
                  TWO POINTERS
    ==========================================

    DESCRIPCION:
        Utiliza dos indices para recorrer
        una secuencia eficientemente.

    COMPLEJIDAD:
        Generalmente O(n).
        Espacio: O(1) adicional.

    APLICACIONES:
        - Encontrar pares con suma objetivo.
        - Eliminar duplicados.
        - Subarreglos.
        - Sliding Window.
*/

#include <bits/stdc++.h>
using namespace std;

// Encontrar dos elementos cuya suma sea target.
// Requiere arreglo ordenado.
bool twoSum(const vector<int>& v, int target) {

    int left = 0;
    int right = (int)v.size() - 1;

    while (left < right) {

        int sum = v[left] + v[right];

        if (sum == target)
            return true;

        if (sum < target)
            left++;

        else
            right--;
    }

    return false;
}

// Longitud maxima de una ventana con suma <= target.
// Requiere elementos no negativos.
int maxWindow(const vector<int>& v, int target) {

    int left = 0;
    int sum = 0;
    int best = 0;

    for (int right = 0; right < (int)v.size(); right++) {

        sum += v[right];

        while (sum > target) {
            sum -= v[left];
            left++;
        }

        best = max(best, right - left + 1);
    }

    return best;
}

int main() {

    vector<int> v = {1, 2, 3, 4, 6};

    cout << twoSum(v, 10) << '\n';

    vector<int> a = {2, 1, 3, 2, 1};

    cout << maxWindow(a, 5) << '\n';

    return 0;
}
