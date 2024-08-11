#include <iostream>
#include <string>
using namespace std;

int check(int a, int b) {
    if(a == b) return 0;
    if(a > b) return 1;    
    return -1;
}

void solve() {
    int ans = 0;

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    if(check(a1, b1) + check(a2, b2) > 0) {
        ans++;
    }
    if(check(a1, b2) + check(a2, b1) > 0) {
        ans++;
    }
    if(check(a2, b1) + check(a1, b2) > 0) {
        ans++;
    }
    if(check(a2, b2) + check(a1, b1) > 0) {
        ans++;
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