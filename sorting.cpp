
/*
    ==========================================
                    SORTING
    ==========================================

    DESCRIPCION:
        Organiza elementos segun un criterio.

    ALGORITMOS:
        - std::sort
        - std::stable_sort
        - Bubble Sort
        - Selection Sort
        - Insertion Sort
        - Merge Sort

    COMPLEJIDAD:
        std::sort: O(n log n)
        stable_sort: O(n log n)
        Bubble Sort: O(n^2)
        Selection Sort: O(n^2)
        Insertion Sort: O(n^2)
        Merge Sort: O(n log n)

    APLICACIONES:
        - Ordenamiento de datos.
        - Busqueda binaria.
        - Ordenamiento personalizado.
*/

#include <bits/stdc++.h>
using namespace std;

// Bubble Sort
void bubbleSort(vector<int>& v) {

    int n = v.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

// Selection Sort
void selectionSort(vector<int>& v) {

    int n = v.size();

    for (int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < n; j++) {

            if (v[j] < v[minIndex])
                minIndex = j;
        }

        swap(v[i], v[minIndex]);
    }
}

// Insertion Sort
void insertionSort(vector<int>& v) {

    int n = v.size();

    for (int i = 1; i < n; i++) {

        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

void printVector(const vector<int>& v) {

    for (int x : v)
        cout << x << " ";

    cout << '\n';
}

int main() {

    vector<int> v = {8, 3, 5, 1, 9, 2};

    sort(v.begin(), v.end());
    printVector(v);

    sort(v.begin(), v.end(), greater<int>());
    printVector(v);

    stable_sort(v.begin(), v.end());

    vector<int> a = {8, 3, 5, 1, 9, 2};

    bubbleSort(a);
    printVector(a);

    vector<int> b = {8, 3, 5, 1, 9, 2};

    selectionSort(b);
    printVector(b);

    vector<int> c = {8, 3, 5, 1, 9, 2};

    insertionSort(c);
    printVector(c);

    return 0;
}
