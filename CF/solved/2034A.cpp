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
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"

int gcd(int a, int b) {
    //Euclidean GCD

    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void solve() {
    int a, b; cin >> a >> b;
    
    //We must find LCM
    //LCM = a * b / gcd(a, b)
    //Compute gcd with Euclidean Algorithm

    ll ans = a * b / gcd(a, b);
    yap(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}