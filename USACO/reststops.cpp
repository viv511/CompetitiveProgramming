#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
#define all(v) v.begin(), v.end()

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);

    int L, N, rF, rB;
    cin >> L >> N >> rF >> rB; 

    ll diff = rF - rB;

    vector<pii> stops((size_t)N);

    for(size_t i=0; i<(size_t)N; i++) {
        // given x, c but want it as c, -x
        cin >> stops[i].second >> stops[i].first;
        stops[i].second *= -1;
    }

    // noteworthy trick! 
    // we use -x so that when we sort by greatest c value
    // any stops with the same value will be numbered such that
    // "-3" comes before "-5" which makes sense in our line start -> 3 -> 5 -> end

    sort(all(stops), greater<pii>());
    
    // our stops are no longer sorted by positions but rather the c values
    // so its important that we maintain our own version of an index
    // we then start from the highest tasty value and continue to sum
    // until we "finished" the stops

    // in technical terms: once we reach a global max of ci, all indexes < xi are automatically
    // merged into a big chunk (and summed). we then look at the next global max remaining until there are none left

    ll res = 0;
    size_t index = 0;

    for(pii s : stops) {
        size_t xi = (size_t)-(s.second);
        int ci = s.first;

        if(xi < index) continue;

        res += (ll(xi - index) * ll(diff) * ll(ci));

        // update index
        index = xi;
    }

    cout << res << "\n";

    return 0;
}

// old idea: combine such that the c's in the resulting chunks are monotonically increasing
// note this doesnt mean the whole sequence has to be increasing
// however, this left->right approach was incorrect.
// we must rather search and order based on the c's first, not the x's
// pretty close first instinct tho.. good job :)