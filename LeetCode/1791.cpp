#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    int n = edges.size() + 1;
    vector<int> count(n, 0);

    for(int i = 0; i < edges.size(); i++) {
        count[edges[i][0] - 1]++;
        count[edges[i][1] - 1]++;
    }       

    for(int i = 0; i < n; i++) {
        if(count[i] == n-1) {
            return i+1;
        }
    }


    // assert(impossible)
    return -1;
}