#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adjList(n);

    //make adj list
    for(auto e : edges) {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    vector<bool> mark(n, false);

    //bfs implementation
    queue<int> q;

    mark[source] = true;    
    q.push(source);

    while(!q.empty()) {
        int vertex = q.front();
        q.pop();

        if(vertex == destination) return true;

        for(auto adjacentNode : adjList[vertex]) {
            if(!mark[adjacentNode]) {
                mark[adjacentNode] = true;
                q.push(adjacentNode);
            }
        }
    }

    return false;
}