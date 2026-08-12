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
        if (i > start && n[i] == n[i-1])
            continue;
        
        if (n[i] > t)
            break;

        path.push_back(n[i]);

        dfs(n, t - n[i], i + 1);

        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    ans.clear();
    path.clear();

    dfs(candidates, target, 0);

    return ans;
}
