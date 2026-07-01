#include <vector>
using namespace std;

typedef long long ll;

vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();
    vector<ll> left(n, 1);
    vector<ll> right(n, 1);    
    
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            left[i] = nums[i];
            continue;
        }

        left[i] = ll(left[i-1]) * ll(nums[i]);
    }

    for(int j = n - 1; j >= 0; j--) {
        if(j == n-1) {
            right[j] = nums[j];   
            continue;
        }

        right[j] = ll(right[j+1]) * ll(nums[j]);
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        ll lprod = (i == 0) ? 1ll : left[i - 1];
        ll rprod = (i == n-1) ? 1ll : right[i + 1];

        ans[i] = lprod * rprod;
    }

    return ans;
}