#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    vector<int> v(n+1, 0);
    for (int i = 0; i < n; i++) {
        v[i+1] = digits[i];
    }

    v[n]++;

    size_t i = n;

    while (v[i] == 10) {
        v[i] = 0;
        v[i-1]++;

        i--;
    }
    
    if (v[0] == 0) {
        // remove first element, shift size
        if (!v.empty()) {
            v.erase(v.begin());
        }
    }

    return v;
}