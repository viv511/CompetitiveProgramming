#include <vector>
#include <climits>
using namespace std;

#define ll long long

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<ll> dist(n, LLONG_MAX);
    dist[src] = 0;

    // bellman ford but we limit to k-hops
    for (int i = 0; i <= k; i++) {
        vector<ll> prevDist = dist;

        for (auto& f : flights) {   
            int u = f[0];
            int v = f[1];
            ll w = f[2];

            if (dist[u] == LLONG_MAX) continue;
            if (dist[u] + w < prevDist[v]) {
                prevDist[v] = dist[u] + w;
            }
        }

        dist = prevDist;
    }

    return (dist[dst] == LLONG_MAX) ? -1 : dist[dst];
}