#include <vector>
using namespace std;

int kadanes(vector<int> v) {
    if (v.size() == 1) {
        return max(v[0], 0);
    }

    int best = v[0];
    int curr = v[0];

    for (int i = 1; i < v.size(); i++) {
        curr = max(v[i], curr + v[i]); //if current sum is neg, restart w/ new element

        // always update best sum
        best = max(best, curr);
    }

    return best;
}

vector<int> flip(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] *= -1;
    }

    return v;
}

int maxAbsoluteSum(vector<int>& nums) {
    // run kadanes on normal array + negated array, find max of those two + 0
    vector<int> other = flip(nums);

    return max(kadanes(nums), kadanes(other));
}