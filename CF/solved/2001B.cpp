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
    if(n%2 == 0) {
        cout << "-1\n";
    }
    else {
        for(int i=n; i>=1; i-=2) {
            cout << i << " ";
        }
        for(int i=2; i<n; i+=2) {
            cout << i << " ";
        }

        cout << "\n";
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