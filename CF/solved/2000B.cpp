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
    vector<bool> v(n, false);

	for(int i=0; i<n; i++) {
		int a; cin >> a;
		a--;

		if(i == 0) {
			v[a] = true;
		}
		else {
			//get before if it exists
			bool occupiedStart = false;
			bool occupiedEnd = false;

			if(a != 0) {
				occupiedStart = v[a-1];
			}

			if(a != n-1) {
				occupiedEnd = v[a+1];
			}

			if(occupiedEnd || occupiedStart) {
                v[a] = true;
			}
			else {
				cout << "NO\n";
				for(int j = i + 1; j < n; j++) {
					int b; cin >> b;
				}
				return;
			}

		}
	}

	cout << "YES\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}