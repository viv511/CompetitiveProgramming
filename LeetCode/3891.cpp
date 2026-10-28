#include <vector>
using namespace std;

long long minIncrease(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2) return 0;

    vector<long long> increases(n, 0);

    for (int i = 1; i < n-1; i++) {
        if (nums[i] <= nums[i-1] || nums[i] <= nums[i+1]) {
            increases[i] = (long long)max(nums[i-1], nums[i+1]) + 1 - nums[i];
        }
    }

    if (n % 2 == 1) {
        long long res = 0;

        for (int i = 1; i < n; i+=2) {
            res += increases[i];  
        }

        return res;
    }
    else {
        // all odds
        // iterate the nth odd number that u make an even one

        int expected = (n - 2) / 2;

        vector<long long> prefix(expected + 1, 0);
        for (int i = 1; i <= expected; i++) {
            prefix[i] = prefix[i-1] + increases[2*i - 1];
        }

        vector<long long> suffix(expected + 1, 0);
        for (int i = expected - 1; i >= 0; i--) {
            suffix[i] = suffix[i+1] + increases[2*(i+1)];
        }

        long long res = LLONG_MAX;
        for (int i = 0; i <= expected; i++) {
            res = min(res, prefix[i] + suffix[i]);
        }

        // toy example:
        // x o _ o _ o _ x
        // x o _ _ o _ o x
        // x o _ o _ _ o x
        // x _ o _ o _ o x

        // where circles are tracked

        return res;
    }
}