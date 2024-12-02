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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 1000;
	vector<int> a(n);
	vector<int> b(n);

    long long ans = 0;
	for(int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
	}

    sort(all(a));
    sort(all(b));

    for(int i=0; i<n; i++) {
		ans += abs(b[i]-a[i]);
	}

    yap(ans);
}