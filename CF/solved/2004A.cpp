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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if(n != 2) {
        cout << "NO\n";
    }
    else {
        if(abs(a[1]-a[0]) > 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}