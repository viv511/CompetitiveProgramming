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
    int n; cin >> n;
 
    vector<int> v(n);
 
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        v[a-1] = 1;
    }
 
    for(int i=0; i<n; i++) {
        if(!v[i]) {
            cout << i+1;
            return;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ll T = 1;
    
    while(T--) {
        solve();
    }
}
