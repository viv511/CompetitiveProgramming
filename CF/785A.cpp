#include <iostream>
#include <string>
#include <map>

using namespace std;

void solve() {
	std::map<string, int> polygons;
    
    polygons["Tetrahedron"] = 4;
    polygons["Cube"] = 6;
    polygons["Octahedron"] = 8;
    polygons["Dodecahedron"] = 12;
    polygons["Icosahedron"] = 20;

    int n; cin >> n;
    long long ans = 0;
    while(n--) {
        string s; cin >> s;
        ans += polygons[s];
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}