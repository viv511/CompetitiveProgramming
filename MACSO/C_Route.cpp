#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cities, roads;
    cin >> cities >> roads;

    //Bellman Ford
    vector<int> dist(cities+1, 1e9);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < roads; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    int startNode, endNode;
    cin >> startNode >> endNode;

    dist[startNode] = 0;
    for(int i = 1; i <= cities-1; i++) {
        for(auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a] + w);
        }
    }

    if(dist[endNode] == 1e9) {
        cout << "-1";
    } else {
        cout << dist[endNode];
    }

}
