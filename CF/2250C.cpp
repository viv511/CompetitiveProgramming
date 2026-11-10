#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 5000;

int n;

// rank restrictions, left \notin [l, r], right \notin [u, v]
vi l(N + 10), r(N + 10), u(N + 10), v(N + 10);

// intution here: constucting the subsequence depends on ranks, which depends on m, which depends on the subsequence length
// we circumvent this by instead iteratively checking fixed values of m starting from n to 1
// this is guaranteed to get every single possible valid m, and because we are checking from large -> small, 
// we can stop at the first valid n, which is the correct answer :)

bool validate(int m) {
    // if we move left to right and pick valid options, 
    // we wont "lose" other solutions since the m is fixed + what happens before doesnt matter
    
    int j = 1;

    for (int i = 1; i <= n && j <= m; i++) {
        bool okLeft = !(l[i] <= j && j <= r[i]);

        int right = m - j + 1;
        bool okRight = !(u[i] <= right && right <= v[i]);

        if (okLeft && okRight) {
            j++;
        }
    }

    // invariant: 1 <= j <= m + 1
    // however, if j == m + 1, then we have gotten exactly m elements
    return (j == m + 1) ? true : false;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int li, ri, ui, vi; cin >> li >> ri >> ui >> vi;
        l[i] = li;
        r[i] = ri;
        u[i] = ui;
        v[i] = vi;
    }

    for (int m = n; m >= 1; m--) {
        if (!validate(m)) continue;

        // want biggest, so greedily take largest m that works
        cout << m << "\n";
        return;
    }
      
    cout << 0 << "\n";
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}