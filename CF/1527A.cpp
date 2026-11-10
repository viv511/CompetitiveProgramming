#include <iostream>
using namespace std;

void solve() {
	int n; cin >> n;
	cout << (long long)(pow(2, (32-__builtin_clz(n))-1)-1) << "\n";
}

int main() {
	int t; cin >> t;
	while(t--) {
		solve();
	}
}
