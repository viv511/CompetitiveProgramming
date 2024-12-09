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
	int l, r, L, R;
    cin >> l >> r >> L >> R;

    int expected = (r-l+1) + (R-L+1);
    set<int> s;

    for(int i = l; i <= r; i++) {
        s.insert(i);
    }
    for(int i = L; i <= R; i++) {
        s.insert(i);
    }

    // cout << expected << " " << s.size() << " ";

    int ans = 0;
    if(s.size() == expected) {
        cout << "1\n";
        return;
    }
    // else if(l == L && r == R) {
    //     cout << r-l << "\n";
    //     return;
    // }
    else if(l >= L && r <= R) { //lr inside LR
        ans = r-l+2;
    }
    else if(L >= l && R <= r) { //LR inside lr
        ans = R-L+2;
    }
    else {
        ans = expected - s.size() - 1 + 2;
    }

    if(l == L) {
        ans--;
    }

    if(r == R) {
        ans--;
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