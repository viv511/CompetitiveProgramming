#include <vector>
using namespace std;

int multiply(int a, int b) {
    int isNeg = (a < 0) ^ (b < 0);
    unsigned int x = (a < 0) ? -a : a;
    unsigned int y = (b < 0) ? -b : b;

    int res = 0;

    if (x > y) swap(x, y);
    while (x > 0) {
        if (x & 1) res += y;

        x >>= 1;
        y <<= 1; 
    }

    return isNeg ? -res : res;
}

int divide(int a, int b) {
    // assert(b != 0);
    int isNeg = (a < 0) ^ (b < 0);
    unsigned int x = (a < 0) ? -a : a;
    unsigned int y = (b < 0) ? -b : b;

    int res = 0;

    // https://stackoverflow.com/questions/5284898/implement-division-with-bit-wise-operator
    for(int i = 31; i >= 0; i--) {
        res <<= 1;
        
        int t = (x >> i) - y;
        if (t >= 0) {
            res |= 1;
            x -= (y << i);
        }
    }

    return isNeg ? -res : res;
}

vector<int> productExceptSelf(vector<int>& nums) {
    size_t n = nums.size();

    size_t zeroCount = 0;

    vector<int> ans(n);

    int product = 1;

    for(size_t i = 0; i < n; i++) {
        if(nums[i] == 0) {
            ans[i] = 0;
            zeroCount++;
            continue;
        } //use default -1's to signal to flip this to full product

        product = multiply(product, nums[i]);
    }

    if(zeroCount >= 2) {
        for(int i=0; i<n; i++) {
            ans[i] = 0;
        }
    }
    else if(zeroCount == 1) {
        for(int i=0; i<n; i++) {
            ans[i] = (ans[i] == 0) ? product : 0;
        }
    }
    else {
        // have to do division on each nonzero
        for(int i=0; i<n; i++) {
            ans[i] = divide(product, nums[i]);
        }
    }

    return ans;
}