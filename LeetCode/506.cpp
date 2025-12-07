#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<int> q;
    for(auto s : score) {
        q.push(s);
    }

    vector<string> ans(score.size());
    int i = 1;
    while(!q.empty()) {
        int a = q.top();
        auto it = std::find(score.begin(), score.end(), a);
        int idx = std::distance(score.begin(), it);

        if(i == 1) {
            ans[idx] = "Gold Medal";
        }
        else if(i == 2) {
            ans[idx] = "Silver Medal";
        }
        else if(i == 3) {
            ans[idx] = "Bronze Medal";
        }
        else {
            ans[idx] = to_string(i);
        }

        q.pop();
        i++;
    }

    return ans;
}