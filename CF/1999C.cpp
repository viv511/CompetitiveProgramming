#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n, s, t;
    cin >> n >> s >> t;

    set<int> times;
    int curEnd = 0;
    for(int i=0; i<n; i++) {
        int start, end; cin >> start >> end;
        times.insert(start-curEnd);
        curEnd = end;
    }
    times.insert(t-curEnd);

 
    if(*times.rbegin() >= s) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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