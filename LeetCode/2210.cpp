//https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/?

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int lhs = 0;
        int z = 0;

        for(int i=1; i < nums.size()-1; i++) {
            if(nums[i] != nums[i+1]) {
                if((nums[i] > nums[lhs]) && (nums[i] > nums[i+1])) {
                    z++;
                }
                else if((nums[i] < nums[lhs]) && (nums[i] < nums[i+1])) {
                    z++;
                }
                lhs = i;
            }
        }

        return z;
    }
};