/*
6
3 3 2
5 1 10000
7 3 4
3 2 7
8 9 6
2 5 4

------

4
5
12
6
36
8
*/

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
	int n, m, k; cin >> n >> m >> k;
    cout << min(n, k) * min(m, k) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}