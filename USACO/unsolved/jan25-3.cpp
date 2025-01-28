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
typedef vector<int> vi;

#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"
#define F0R(i, a) FOR(i, 0, a)

int countMatches(vi first, vi second) {
    //Assume same size
    int count = 0;
    for(int i=0; i<sz(first); i++) {
        if(first[i] == second[i]) {
            count++;
        }
    }

    return count;
}

void solve() {
	int n; cin >> n;

    vi a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    vi b(n);
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    map<int, int> possibilities;

    for(int l=0; l<n; l++) {
        for(int r=l; r<n; r++) {
            reverse(a.begin()+l, a.begin()+r+1);

            int count = countMatches(a, b);
            possibilities[count]++;

            reverse(a.begin()+l, a.begin()+r+1);
        }
    }

    //Iterate and print out each key value from 0 to N
    for(int i=0; i<=n; i++) {
        if(possibilities.find(i) == possibilities.end()) {
            yap(0);
        }
        else {
            yap(possibilities[i]);
        }
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
}