//https://leetcode.com/problems/build-array-from-permutation/description/

#include <iostream>
#include <vector>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> ans;
    for(int i=0; i<nums.size(); i++) {
        ans.push_back(nums[nums[i]]);
    }
    return ans;
}