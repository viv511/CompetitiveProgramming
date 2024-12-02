//https://leetcode.com/problems/contains-duplicate/description/

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> count;

        for(int i=0; i<nums.size(); i++) {
            if(count[nums[i]] > 0) {
                return true;
            }
            count[nums[i]]++;
        }

        return false;
    }
};