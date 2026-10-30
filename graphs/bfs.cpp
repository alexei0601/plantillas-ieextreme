
/*
    ==========================================
         BREADTH-FIRST SEARCH (BFS)
    ==========================================

    DESCRIPCION:
        Recorre un grafo por niveles, visitando primero
        los vertices mas cercanos al origen.

    COMPLEJIDAD:
        Tiempo: O(V + E)
        Espacio: O(V)

    CUANDO UTILIZAR:
        - Encontrar caminos minimos sin pesos.
        - Calcular distancias desde un origen.
        - Encontrar componentes conexas.
        - Recorrer grafos por niveles.

    REQUISITOS:
        - Lista de adyacencia.
        - Cola (queue).
        - Vector visited.

    OBSERVACIONES:
        - BFS encuentra caminos minimos en grafos
          no ponderados.
        - Para grafos ponderados se necesitan
          otros algoritmos.
*/

#include <bits/stdc++.h>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();

    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

vector<int> bfsDistances(
    int start,
    const vector<vector<int>>& adj
) {
    int n = adj.size();

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;

    vector<vector<int>> adj(n);

    // Grafo no dirigido
    adj[0] = {1, 3};
    adj[1] = {0, 2, 4};
    adj[2] = {1};
    adj[3] = {0, 4};
    adj[4] = {1, 3};

    cout << "BFS desde el vertice 0:\n";
    bfs(0, adj);

    cout << "\n\nDistancias desde el vertice 0:\n";

    vector<int> dist = bfsDistances(0, adj);

    for (int i = 0; i < n; i++) {
        cout << "Vertice " << i << ": " << dist[i] << '\n';
    }

    return 0;
}
