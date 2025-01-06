//https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector< pair<int, int> > numsWithIndex;
    for(int i=0; i<nums.size(); i++) {
        numsWithIndex.push_back(make_pair(nums[i], i));
    }

    sort(numsWithIndex.begin(), numsWithIndex.end());

    int l = 0;
    int r = numsWithIndex.size()-1;

    while (l < r) {
        int sum = numsWithIndex[l].first + numsWithIndex[r].first;
        if(sum == target) {
            vector<int> ans(2);
            ans[0] = numsWithIndex[l].second;
            ans[1] = numsWithIndex[r].second;
            return ans;
        }
        else if(sum < target) {
            l++;
        }
        else {
            r--;
        }
    }

    return vector<int>();
}