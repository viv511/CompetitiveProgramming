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

bool equals(Rect p, Rect q) {
    return p.x1 == q.x1 && p.y1 == q.y1 && p.x2 == q.x2 && p.y2 == q.y2;
}

bool inside(Rect outer, Rect inner) {
    if(outer.x1 <= inner.x1 && inner.x2 <= outer.x2) {
        if(inner.y1 >= outer.y1 || inner.y2 <= outer.y2) {
            return true;
        }
    }

    if(outer.y1 <= inner.y1 && inner.y2 <= outer.y2) {
        if(inner.x1 >= outer.x1 || inner.x2 <= outer.x2) {
            return true;
        }
    }

    return false;
}


void solve() {
	Rect a, b;

    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    
    if(intersect(a, b) == 0) {
        yap(area(a)); // a and b are completely separate
        return;
    }
    else if(equals(a, b)){
        yap(0); // a and b are the same
        return;
    }
    else if(area(a) == intersect(a, b)){
        yap(0); // a is completely covered by b
        return;
    }

    //if a is partially covered by b and the excess area is a rectangle, the answer is just area of a - intersect(a, b)
    //otherwise it is just the area of a
    //the tarp is always a rectangle

    if(inside(b, a)) {
        yap(area(a) - intersect(a, b));
    }
    else {
        yap(area(a));
    }
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