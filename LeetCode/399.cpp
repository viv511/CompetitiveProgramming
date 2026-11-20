#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, int> map;

    // just increases vertex count from 0 to whtv as we see new variables
    for (auto& e : equations) {
        for (int i = 0; i < 2; i++) {
            if (map.count(e[i]) == 0) {
                int curSize = map.size();
                map[e[i]] = curSize;
            }
        }
    }

    int n = map.size();

    vector<vector<double>> dist(n, vector<double>(n, -1));
    for (int i = 0; i < n; i++) dist[i][i] = 1;

    for (int i = 0; i < values.size(); i++) {
        vector<string>& e = equations[i];
        double val = values[i];

        int u = map[e[0]];
        int v = map[e[1]];

        dist[u][v] = val;
        dist[v][u] = 1 / val;
    }

    // use an equation a / b = k as a directed graph with forward edge weight k and backwards 1/k
    // then multiply to store ans instead of using dist

    // floyd warshall might be what we want since its any pair of verices here
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            if (dist[u][k] == -1) continue;
            for (int v = 0; v < n; v++) {
                if (dist[k][v] == -1) continue;

                // we're assuming no contradictions from problem, so just need to do it once
                if (dist[u][v] == -1) dist[u][v] = dist[u][k] * dist[k][v];
            }
        }
    }

    vector<double> ans;
    for (auto& q : queries) {
        if (map.count(q[0]) == 0 || map.count(q[1]) == 0) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(dist[map[q[0]]][map[q[1]]]);
        }
    }

    return ans;
}