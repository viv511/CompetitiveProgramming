#include <vector>
#include <numeric>
using namespace std;

int missingNumber(vector<int>& nums) {
    int total = (nums.size())*(nums.size()+1)/2;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return total - sum;
}