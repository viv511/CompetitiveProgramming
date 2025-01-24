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

#define ll long long


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//Precompute powers of 2
    vector<ll> powers(32);
    powers[0] = 1;
    for(int i=1; i<32; i++) {
        powers[i] = powers[i-1] * 2ll;
    }

    int T; cin >> T;
    while(T--) {
        int l, r; cin >> l >> r;

        //Find number of intervals of 2^n that it ranges through
        int lInterval = 0;
        int rInterval = 0;

        for(int i=0; i<powers.size(); i++) {
            if(l < powers[i]) {
                lInterval = i;
                break;
            }
        }

        for(int i=0; i<powers.size(); i++) {
            if(r < powers[i]) {
                rInterval = i;
                break;
            }
        }

		//Key Idea: 2^n, (2^n)-1, and any number in [l, r] will give the answer
		//Proof by bit manipulation and XOR properties
		//Try to maximize the differing bits

        if(rInterval-lInterval >= 1) {
            ll a = pow(2ll, rInterval-1);
            ll b = pow(2ll, rInterval-1)-1;
            cout << a << " " << b << " ";

            for(int i=l; i<=r; i++) {
				if(i != a && i != b) {
					cout << i << "\n";
					break;
				}
			}
        }
        else { //No power's of two in the range
            ll shifter = 0; 

            for (int i = 31; i >= 0; i--) {
                //check if the bits are equal
                if ((r&(1<<i)) == (l&(1<<i))) {
                    if (r & (1<<i)) {
                        shifter += pow(2, i);
                    }
                }
                else {
                    break;
                }
            }

			//Shift down to work with the numbers excluding the same leading bits ==> shift them back to the original range
            l -= shifter;
            r -= shifter;
    
            for(int i=0; i<powers.size(); i++) {
                if(l < powers[i]) {
                    lInterval = i;
                    break;
                }
            }

            for(int i=0; i<powers.size(); i++) {
                if(r < powers[i]) {
                    rInterval = i;
                    break;
                }
            }   

            ll a = shifter + pow(2ll, rInterval-1);
            ll b = shifter + pow(2ll, rInterval-1)-1;
            cout << a << " " << b << " ";

            l += shifter;
            r += shifter;

			for(int i=l; i<=r; i++) {
				if(i != a && i != b) {
					cout << i << "\n";
					break;
				}
			}
        }
    }
}