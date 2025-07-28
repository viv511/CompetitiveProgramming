#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define ins insert
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    int pos = 0;
    int neg = 0;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '+') {
            pos++;
        }
        else {
            neg++;
        }
    }


    ll p; cin >> p;

    while(p--) {
        ll a, b;
        cin >> a >> b;

        bool possible = false;

        if ((a * pos - b * neg) == 0) {
            possible = true;
        }
        else if((a * neg - b * pos) == 0) {
            possible = true;
        }
        else {
            for (int i = 0; i <= pos; i++) {
                for(int j = 0; j <= neg; j++) {
                    if((i * a + (pos - i) * b - j * a - (neg - j) * b) == 0) {
                        possible = true;
                        break;
                    }
                }
                if(possible) break;
            }
        }
        
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}