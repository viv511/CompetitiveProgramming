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

vi LIS;
//Solving for longest increasing subsequence !! basically?
//choice counter is just find the # of dp routes

void solve() {
    ll n; cin >> n;
   
    int choice; cin >> choice;

    vector<ll> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    if(n == 1) {
        print(1);
        if(choice) {
            cout << v[0];
        }
        return;
    }


    LIS.resize(n, 1);

    for(int i = n-1; i >= 0; i--) {
        for(int j = i+1; j < n; j++) {
            if(v[i] < v[j]) {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }

    // for(auto a : LIS) {
    //     print(a);
    // }

    if(choice == 1) {
        print(LIS[0]);
        print(LIS[1]);
    } else {
        print(LIS[0]);
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