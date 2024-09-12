#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int smallDiff = 1e9;

    for(int i=0; i<n-1; i++) {
        smallDiff = min(smallDiff, v[i+1]-v[i]);
    }
    cout << smallDiff << "\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }   
}
