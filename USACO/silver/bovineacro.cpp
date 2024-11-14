#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    ll n, m, k; cin >> n >> m >> k;

    deque< pair<ll, ll> > cows;
    deque<ll> stacks;

    for(int i=0; i<m; i++) {
        stacks.push_back(1e12);
    }

    for(int i=0; i<n; i++) {
        ll w, a;
        cin >> w >> a;

        cows.push_back(make_pair(w, a));
    }

    sort(cows.rbegin(), cows.rend());

    ll ans = 0;

    for(auto cow : cows) {
        ll curHeaviest = cow.first;
        ll curAmt = cow.second;

        while((stacks.back() - curHeaviest >= k) && (curAmt > 0)) {
            stacks.pop_back();
            stacks.push_front(curHeaviest);
            curAmt--;
            ans++;
        }
    }
    
    cout << ans;
}