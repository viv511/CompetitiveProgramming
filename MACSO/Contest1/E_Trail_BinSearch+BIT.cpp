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
#define MOD 1000000007

using namespace std;

class B_I_T {
public:
    int n;
    vi count;
    vi value;

public:
    B_I_T(int size) {
        n = size;
        count.resize(n+1, 0);
        value.resize(n+1, 0);
    }

    void printTree() {
        for(int i=1; i<=n; i++) {
            cout << count[i] << " ";
        }
        cout << "\n";
    }

    pi performQuery(int index) {
        int val = 0;
        int c = 0;

        while(index > 0) {
            if(count[index] > val) {
                val = count[index];
                c = value[index];
            } else if(count[index] == val) {
                c += value[index];
            }

            index -= index & -index; //get the last set bit!! funny bit magic using twos complement!!
        }

        return mp(val, c);
    }

    void performUpdate(int index, int val, int c) {
        while(index <= n) {
            if(count[index] < val) {
                count[index] = val;
                value[index] = c;
            } else if(count[index] == val) {
                value[index] += c;
            }

            index += index & -index; //get the last set bit!! funny bit magic using twos complement (pt 2!!)
        }
    }


};

void solve() {
    ll n; cin >> n;
    int choice; cin >> choice;

    if(n == 1) {
        int a; cin >> a;
        print(a);
        if(choice == 1) {
            print(1);
        }
        return;
    }

    vector<ll> v(n);
    vector<ll> uniqueCountV(n);
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        v[i] = a;
        uniqueCountV[i] = a;
    }

    vector<ll> temp;
    temp.pb(v[0]);
    int ans = 1;

    for(int i=1; i<n; i++) {
        if(v[i] > temp.back()) {
            temp.pb(v[i]);
            ans++;
        }
        else {
            int idx = lower_bound(all(temp), v[i]) - temp.begin();
            temp[idx] = v[i];
        }
    }

    print(ans);

    if(choice == 1) {
        sort(all(uniqueCountV));  

        //Remove dups
        uniqueCountV.erase(unique(all(uniqueCountV)), uniqueCountV.end());

        int finalSize = uniqueCountV.size();
        B_I_T fenwick(finalSize);

        for(auto a : v) {
            //same logic-ish? as binary search code

            auto it = lower_bound(all(v), a);
            int indexToLookAt = distance(v.begin(), it) + 1;

            pair<int, int> query = fenwick.performQuery(indexToLookAt-1); //-1 because BIT is 1-indexed
            int largest = max(query.se, 1);

            fenwick.performUpdate(indexToLookAt, query.fi+1, largest);
        }

        print(fenwick.performQuery(finalSize).se);
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

//Solving for length of longest increasing subsequence !! basically?
//choice counter is just find # routes
//DP too slow, use binary search --> n^2 to n log n

//2nd part of problem is to find the number of longest increasing subsequences
//Try to use a fenwick tree? BIT tree?
//nlogn approach rather than n^2 approach
// --> Referenced BIT Template from github.com/doocs