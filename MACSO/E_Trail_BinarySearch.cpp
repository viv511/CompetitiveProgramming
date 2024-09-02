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
#define MOD 1000000007

using namespace std;

//Solving for longest increasing subsequence !! basically?
//choice counter is just find # routes
//DP too slow, use binary search

vi LIS;

void solve() {
    ll n; cin >> n;
    int choice; cin >> choice;

    if(n == 1) {
        int a; cin >> a;
        print(a);
        if(choice == 1) {
            print(1);
        }
        return;
    }

    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    vector<ll> temp;
    temp.pb(v[0]);
    int ans = 1;

    for(int i=1; i<n; i++) {
        if(v[i] > temp.back()) {
            temp.pb(v[i]);
            ans++;
        }
        else {
            int idx = lower_bound(all(temp), v[i]) - temp.begin();
            temp[idx] = v[i];
        }
    }

    print(ans);

    if(choice == 1) {
        LIS.resize(n, 1);

        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(v[i] < v[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        long long count = LIS[1] % MOD;
        print(count);
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