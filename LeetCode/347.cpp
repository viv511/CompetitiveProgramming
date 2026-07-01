#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()

vector<int> topKFrequent(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::unordered_map<int, int> freq;

    size_t n = nums.size();
    for(size_t i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    vector<pi> distrib;

    for(auto num : freq) {
        distrib.push_back(make_pair(num.second, num.first));
    }

    sort(all(distrib), greater<pi>());

    vector<int> ans;

    for(size_t i = 0; i < k; i++) {
        ans.push_back(distrib[i].second);
    }

    return ans;
}