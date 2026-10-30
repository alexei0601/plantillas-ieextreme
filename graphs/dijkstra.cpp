
/*
    ==========================================
               DIJKSTRA'S ALGORITHM
    ==========================================

    DESCRIPCION:
        Encuentra las distancias minimas desde un
        vertice de origen hacia los demas vertices
        de un grafo ponderado.

    COMPLEJIDAD:
        Tiempo: O((V + E) log V)
        Espacio: O(V + E)

    CUANDO UTILIZAR:
        - Caminos minimos en grafos ponderados.
        - Redes de transporte.
        - Problemas de rutas y distancias.

    REQUISITOS:
        - Lista de adyacencia ponderada.
        - Cola de prioridad.
        - Pesos no negativos.

    OBSERVACIONES:
        - No funciona correctamente con pesos negativos.
        - INF representa una distancia inalcanzable.
        - Utiliza long long para las distancias.
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = LLONG_MAX;

vector<ll> dijkstra(
    int start,
    const vector<vector<pair<int, int>>>& adj
) {
    int n = adj.size();

    vector<ll> dist(n, INF);

    // Min-heap: {distancia, vertice}
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // Ignorar estados obsoletos
        if (d != dist[u]) {
            continue;
        }

        for (auto [v, w] : adj[u]) {
            if (dist[u] <= INF - w &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;

    // {destino, peso}
    vector<vector<pair<int, int>>> adj(n);

    // Grafo no dirigido ponderado
    adj[0].push_back({1, 4});
    adj[0].push_back({3, 2});

    adj[1].push_back({0, 4});
    adj[1].push_back({2, 3});
    adj[1].push_back({4, 10});

    adj[2].push_back({1, 3});
    adj[2].push_back({4, 5});

    adj[3].push_back({0, 2});
    adj[3].push_back({4, 6});

    adj[4].push_back({1, 10});
    adj[4].push_back({2, 5});
    adj[4].push_back({3, 6});

    vector<ll> dist = dijkstra(0, adj);

    cout << "Distancias minimas desde el vertice 0:\n";

    for (int i = 0; i < n; i++) {
        cout << "Vertice " << i << ": ";

        if (dist[i] == INF) {
            cout << "INALCANZABLE\n";
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}
