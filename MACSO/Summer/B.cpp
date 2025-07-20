#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

#define yap(answer) cout << answer << "\n"


void solve() {
    ll k, x; 
    cin >> k >> x;
    
    ll halfway = (k + 1) * k / 2ll;

    if(x >= (k * k)) {
        yap(2 * k - 1);
    }
    else if(x > halfway) {
        ll ans = k;
        x -= halfway;

        //k-1, k-2, k-3 ... 1
        //add one to ans and subtract k-1, then k-2, etc
        
        // ll i = 1;
        // while(x > 0 && (k-i) > 0) {
        //     ans++;
        //     if(x >= (k - i)) {
        //         x -= (k - i);
        //         i++;
        //     }
        //     else {
        //         break;
        //     }
        // }

        //sum of k-1, k-2, k-3 ... 1
        //s = n(a1 + an)/2

        ll L = 1;
        ll R = k - 1;
        
        //run bin search
        while (L <= R) {
            ll M = (L + R) / 2;
            ll i = M;

            ll S = ((2*k - i - 1) * i)/ 2;

            if (S >= x) {
                R = M - 1;

                ans = k + i;
            } else {
                L = M + 1;
            }
        }

        yap(ans);
    }
    else {
        //expanded version of quadratic formula
        //n(n+1)/2 >= x
        // n^2 + n - 2x >= 0
        // n = (-1 + sqrt(1 + 8x)) / 2
        yap(ceil((-1ll + sqrt(1 + 8ll * x)) / 2ll));
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}