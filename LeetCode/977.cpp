#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> res(n, 0);

    while(l <= r) {
        if(abs(nums[l]) > abs(nums[r])) {
            res[r - l] = nums[l] * nums[l];
            l++; 
        }
        else {
            res[r - l] = nums[r] * nums[r];
            r--;
        }
    }
    return res;
}