#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adjList, int start, int dest, vector<bool>& mark) {
    if(start == dest) return true;

    mark[start] = true;

    for(auto n : adjList[start]) {
        if(!mark[n]) {
            if(dfs(adjList, n, dest, mark)) {
                return true;
            }
        }
    }

    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    vector<vector<int>> adjList(n);

    //make adj list
    for(auto e : edges) {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }

    //dfs array
    vector<bool> mark(n, false);

    bool ans = dfs(adjList, source, destination, mark);
    return ans;
}