
/*
    ==========================================
          DEPTH-FIRST SEARCH (DFS)
    ==========================================

    DESCRIPCION:
        Recorre un grafo explorando tan profundamente
        como sea posible antes de retroceder.

    COMPLEJIDAD:
        Tiempo: O(V + E)
        Espacio: O(V)

    CUANDO UTILIZAR:
        - Encontrar componentes conexas.
        - Detectar ciclos (con modificaciones).
        - Explorar grafos.
        - Resolver problemas de conectividad.

    REQUISITOS:
        - Lista de adyacencia.
        - Vector visited.

    OBSERVACIONES:
        - Esta implementacion es recursiva.
        - Solo visita vertices alcanzables desde el origen.
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj,
         vector<bool>& visited) {

    visited[u] = true;

    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
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

    vector<bool> visited(n, false);

    cout << "DFS desde el vertice 0:\n";
    dfs(0, adj, visited);

    cout << '\n';

    return 0;
}
