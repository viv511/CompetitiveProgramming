#include <iostream>
using namespace std;

void solve() {
	int a, b; cin >> a >> b;
	cout << min(a, b) << " " << max(a, b) << "\n";
}

int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}	
}
