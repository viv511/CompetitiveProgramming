#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n; int k; cin >> n >> k;

    // construct a inf-sequence of 0,1,0,1... etc
    // idea: expand the 0 to a chunk of size c, 1 to a chunk of size c, and repeat until all k are done

    // chunks
    int c = n - k;

    if (c == 1) {
        cout << "-1" << "\n";
        return;
    }
    
    // equal pairs + diff pairs = n - 1
    // diff pairs = c - 1
    // ==> equal pairs = n - c = n - (n - k) = k, as desired

    // each index stores the amt of times the character is repeated
    vector<int> ans(c, 1);

    if (k % 2 == 0) {
        // e.x. k = 4 -> ... 111 000
        ans[c - 1] = k / 2 + 1;
        ans[c - 2] = k / 2 + 1;
    }
    else {
        if (c % 2 == 0) {
            // e.x. k = 3 -> ... 11 000
            ans[c - 1] = (k + 1) / 2 + 1;
            ans[c - 2] = k / 2 + 1;
        }
        else {
            // edge case, add to minority side
            ans[c - 2] = (k + 1) / 2 + 1;
            ans[c - 1] = k / 2 + 1;
        }
    }

    // print the answer
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < ans[i]; j++) {
            if (i % 2 == 0) {
                cout << "0";
            }
            else {
                cout << "1";
            }
        }
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}