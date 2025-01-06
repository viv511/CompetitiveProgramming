#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

struct Rect {
    int x1, y1, x2, y2;
};

int minSquareArea(Rect p, Rect q) {
    int bottomLeftX = min(p.x1, q.x1);
    int bottomLeftY = min(p.y1, q.y1);
    int topRightX = max(p.x2, q.x2);
    int topRightY = max(p.y2, q.y2);

    return pow(max(topRightX - bottomLeftX, topRightY - bottomLeftY), 2);
}

void solve() {
	Rect a, b;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

    yap(minSquareArea(a, b));
}

int main() {
    freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}