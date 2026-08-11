#include <vector>
using namespace std;

vector<vector<int>> ans;
vector<int> path;

void dfs(vector<int>& n, int t, int start) {
    if (t == 0) {
        ans.push_back(path);
        return;
    }

    for (int i = start; i < n.size(); i++) {
        if(n[i] > t) break;

        path.push_back(n[i]);

        dfs(n, t - n[i], i); //enable dups so we pass in i, otherwise i+1

        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, target, 0);

    return ans;
}