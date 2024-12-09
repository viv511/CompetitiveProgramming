#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())

using namespace std;

void solve() {
	int n; cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));

    int index = n / 2;

    cout << a[index] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}