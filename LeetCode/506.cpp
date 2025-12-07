#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < score.size(); i++) {
        pq.push({score[i], i});
    }

    vector<string> ans(score.size());
    int i = 1;

    while(!pq.empty()) {
        auto [s, idx] = pq.top();
        pq.pop(); 

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

        i++;
    }

    return ans;
}