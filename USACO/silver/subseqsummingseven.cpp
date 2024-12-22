#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    // freopen("div7.in", "r", stdin);
    // freopen("div7.out", "w", stdout);

    long long n; cin >> n;
    vector<long long> v(n+1);

    for(int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        v[i] %= 7;
    }

    int maxLength = 0;
    
    vector<int> left(7, 1e7);
    vector<int> right(7, -1);

    for(int i=0; i<v.size(); i++) {
        left[v[i]] = min(left[v[i]], i);
        right[v[i]] = i;
    }

    for(int i=0; i<7; i++) {
        maxLength = max(maxLength, right[i]-left[i]);
    }

    cout << maxLength;
}