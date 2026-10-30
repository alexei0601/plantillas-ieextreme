
/*
    ==========================================
                    C++ STL
    ==========================================

    DESCRIPCION:
        Biblioteca estandar de plantillas de C++.

    CONTENIDO:
        - vector
        - pair
        - map / unordered_map
        - set / unordered_set
        - stack
        - queue
        - priority_queue
        - deque

    COMPLEJIDAD:
        Depende de la estructura y operacion.

    APLICACIONES:
        - Almacenamiento y manipulacion de datos.
        - Conteo de frecuencias.
        - Busqueda y ordenamiento.
        - Implementacion de algoritmos.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // VECTOR: arreglo dinamico
    vector<int> v = {4, 2, 8, 1};

    v.push_back(10);
    v.emplace_back(12);

    cout << "Vector: ";
    for (int x : v)
        cout << x << " ";
    cout << '\n';


    // PAIR: pareja de valores
    pair<int, string> p = {1, "Alex"};

    cout << p.first << " " << p.second << '\n';


    // MAP: clave-valor ordenado
    map<string, int> frequency;

    frequency["apple"]++;
    frequency["apple"]++;
    frequency["banana"]++;

    cout << "Frecuencia apple: "
         << frequency["apple"] << '\n';


    // SET: elementos unicos ordenados
    set<int> s = {4, 2, 2, 1};

    s.insert(8);

    cout << "Set: ";
    for (int x : s)
        cout << x << " ";
    cout << '\n';


    // STACK: LIFO
    stack<int> st;

    st.push(10);
    st.push(20);

    cout << "Stack top: " << st.top() << '\n';
    st.pop();


    // QUEUE: FIFO
    queue<int> q;

    q.push(10);
    q.push(20);

    cout << "Queue front: " << q.front() << '\n';
    q.pop();


    // PRIORITY QUEUE: Max heap
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Max heap: " << pq.top() << '\n';


    // UNORDERED MAP: tabla hash
    unordered_map<int, string> um;

    um[1] = "uno";
    um[2] = "dos";

    cout << um[1] << '\n';

    return 0;
}
