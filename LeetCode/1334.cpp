#include <vector>
#include <climits>
using namespace std;

#define ll long long
const ll INF = LLONG_MAX;
const int MOD = 1e9 + 7;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (auto& e : edges) {
        int u = e[0];
        int v = e[1];
        ll w = e[2];

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            if (dist[u][k] == INF) continue;
            
            for (int v = 0; v < n; v++) {
                if (dist[k][v] == INF) continue;

                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    int minCityIndex = 0;
    ll minCityCount = INF;

    for (int i = n - 1; i >= 0; i--) {
        int satisfied = 0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            if (dist[i][j] <= distanceThreshold) satisfied++;
        }

        if (satisfied < minCityCount) {
            minCityIndex = i;
            minCityCount = satisfied;
        }
    }

    return minCityIndex;
}
