#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define mp make_pair
#define fi first
#define se second

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

    stack<pi> s;
    s.push(mp(-1e9, 0)); //give big neg

    for(int i=1; i<=n; i++) {
        int x; cin >> x;

        while(!s.empty() && s.top().fi >= x) {
            s.pop();
        }
        
        cout << s.top().se << " ";
        s.push(mp(x, i));
    }
}