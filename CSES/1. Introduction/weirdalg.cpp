#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <list>
// #include <bits/stdc++.h>
 
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
 
void solve() {
    ll n; cin >> n;
    cout << n << " ";
 
    while(n != 1) {
        if(n%2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n += 1;
        }
 
        cout << n << " ";
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    // ll T; cin >> T;
    int T = 1;
    
    while(T--) {
        solve();
    }
}