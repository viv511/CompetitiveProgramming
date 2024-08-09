#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;

	if(n <= 2) {
		cout << 0 << "\n";
	}
	else {
		if(n%2 == 0) {
			cout << n/2 - 1 << "\n";
		}
		else {
			cout << (n-1) / 2 << "\n";
		}
	}
}

int main() {
	int T; cin >> T;
	while(T--) {
		solve();
	}
}