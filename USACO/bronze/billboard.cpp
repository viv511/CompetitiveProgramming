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

int area(Rect r) {
    return (r.x2 - r.x1) * (r.y2 - r.y1);
}

int intersect(Rect p, Rect q) {
    int leftBound = max(p.x1, q.x1);
    int rightBound = min(p.x2, q.x2);

    if(leftBound >= rightBound) {
        return 0;
    }

    int topBound = min(p.y2, q.y2);
    int bottomBound = max(p.y1, q.y1);

    if(bottomBound >= topBound) {
        return 0;
    }

    return (rightBound - leftBound) * (topBound - bottomBound);
}


void solve() {
	Rect a, b, truck;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;

    yap(area(a) + area(b) - intersect(a, truck) - intersect(b, truck));
}

int main() {
    freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}