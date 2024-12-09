#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

void solve() {
	int n; cin >> n;
    int k; cin >> k;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());

    int indexToChange = v.size()-2;
    while(k != 0 && indexToChange >= 0) {
        int diff = abs(v[indexToChange+1]-v[indexToChange]);
        int val = min(diff, k);

        v[indexToChange] += val;
        k -= val;
        indexToChange-=2;
    }

    
    long long ans = 0;
    int turn = 0;
    for(int i=v.size()-1; i>=0; i--) {
        if(turn == 0) {
            ans += v[i];
            turn = 1;
        }
        else {
            ans -= v[i];
            turn = 0;
        }
    }
    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}