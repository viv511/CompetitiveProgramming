#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums[i] += 100000;
                ans++;
            }
        }

        sort(nums.begin(), nums.end());
        
        return nums.size()-ans;
    }
};

