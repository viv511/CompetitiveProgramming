//https://leetcode.com/problems/course-schedule/description/
#include <vector>
using namespace std;


bool dfs(vector<vector<int>>& a, int u, vector<bool>& v, vector<bool>& s) {
    //Mark
    v[u] = true;
    s[u] = true;

    for(int n : a[u]) {
        if(!v[n]) {
            if(dfs(a, n, v, s)) return true;
        }
        else if(s[n]) {
            return true;
        }
    }

    s[u] = false; 
    return false;
}

//https://www.geeksforgeeks.org/dsa/detect-cycle-in-a-graph/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);

    for(auto a : prerequisites) {
        adjList[a[1]].push_back(a[0]);
    }

    vector<bool> visited(numCourses, false);
    vector<bool> recStack(numCourses, false);

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i] && dfs(adjList, i, visited, recStack))
            return false;
    }

    return true;
}