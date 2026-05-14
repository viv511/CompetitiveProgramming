#include <iostream>

using namespace std;

#define yap(answer) cout << answer << "\n"

void solve() {
	int l, r, d, u;
    cin >> l >> r >> d >> u;

    if(l == r && d == u && l == d && r == u) {
        if(l == 0) {
            yap("NO");
        }
        else {
            yap("YES");
        }
    }
    else {
        yap("NO");
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