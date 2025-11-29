//https://leetcode.com/problems/greatest-sum-divisible-by-three/

#include <vector>
#include <algorithm>
using namespace std;

int maxSumDivThree(vector<int>& nums) {     
    sort(nums.begin(), nums.end());   
    vector<int> ones;
    vector<int> twos;
    int sum = 0;
    for(auto i : nums) {
        if(i % 3 == 1) ones.push_back(i);
        if(i % 3 == 2) twos.push_back(i);
        sum += i;
    }

    //ones, twos sorted by creation

    if(sum % 3 == 0) {
        return sum;
    }
    else if(sum % 3 == 1) {
        if(twos.size() >= 2) {
            if(ones.empty()) return (sum - twos[0] - twos[1]);
            else {
                return max((sum - ones[0]), (sum - twos[0] - twos[1]));
            }
        }
        else if(!ones.empty()){
            return sum - ones[0];
        }
        else {
            return 0;
        }
    }
    else {
        if(ones.size() >= 2) {
            if(twos.empty()) return (sum - ones[0] - ones[1]);
            else {
                return max((sum - twos[0]), (sum - ones[0] - ones[1]));
            }
        }
        else if(!twos.empty()){
            return sum - twos[0];
        }
        else {
            return 0;
        }
    }
}