#include <iostream>

using namespace std;

void solve() {
	int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b && c == d && a == c && a != 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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