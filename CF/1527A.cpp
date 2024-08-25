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
	int k = n;
	while(n != 0) {
		k--;
		n = n & n-1;
	}
	cout << k << "\n";
}

int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
