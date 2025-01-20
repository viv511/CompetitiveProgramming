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
typedef long double ld;
typedef unsigned long long ull;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define ins insert
#define endl '\n'
#define YN(x) cout << (x? "YES":"NO") << endl

const int maxn = 2e5+5;
const int inf = 1e9+5;
const int mod = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    bool ans = true;

    if(s[0] == 'M') {
        F0R(i, n) {
            if(s[i] == 'M') {
                if(i+1 < n && s[i+1] != 'M') {
                    continue;
                } else {
                    ans = false;
                    break;
                }
            } else if(s[i] == 'I') {
                if(i+1 < n && s[i+1] == 'T') {
                    i++;
                    continue;
                } else {
                    ans = false;
                    break;
                }
            } else {
                ans = false;
                break;
            }
        }
    } else {
        ans = false;
    }

    YN(ans);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("fname.in", "r", stdin);
    // freopen("fname.out", "w", stdout);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

    // solve();

    return 0;
}