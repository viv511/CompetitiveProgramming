#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


void solve() {
    int a, b; cin >> a >> b;

    // 8 possible knight moves
    set<pair<int, int>> moves = {
        {a, b},
        {a, -b},
        {-a, b},
        {-a, -b},
        {b, a},
        {b, -a},
        {-b, a},
        {-b, -a}
    };

    int xk, yk, xq, yq; cin >> xk >> yk >> xq >> yq;

    set<pair<int, int>> s;

    int res = 0;
    for (auto move : moves) {
        int x = xk + move.first;
        int y = yk + move.second;

        s.insert({x, y});
    }

    for (auto move : moves) {
        if (s.count({xq + move.first, yq + move.second})) {
            res++;
        }
    }

    cout << res << "\n";
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}