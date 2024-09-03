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
#define print(answer) cout << answer << "\n"

using namespace std;

void solve() {
    int n; cin >> n;
	if(n % 2 == 1) {
        print(-1);
    }
    else {
        for(int i=1; i<=n; i++) {
            if(i % 2 == 1) {
                cout << i+1 << " ";
            }
            else {
                cout << i-1 << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}