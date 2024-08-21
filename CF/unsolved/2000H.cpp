// I was so delulu and I thought I could solve this :')
// (i stil think I can, ill figure it out surely)
// fun tuple practice ig

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <tuple>

typedef long long ll;

using namespace std;

int minLoad(vector<tuple<int, int, int>> e, int k) {
	int a, b, c;

	int initialAns;
	if(get<0>(e[0])-1 >= k) {
		return 1;
	}
	
	for(int i = 0; i < e.size(); i++) {
		tie(a, b, c) = e[i];

		if(c >= k) {
			return a+1;
		}
	}

	return get<1>(e[e.size()-1]) + 1;
}

vector<tuple<int, int, int>> addEdge(vector<tuple<int, int, int>> e, int n) {

	int a, b, c;

	for(int i = 0; i < e.size(); i++) {
		tie(a, b, c) = e[i];

		if(n < a) {
			if(i != 0) {
				get<1>(e[i-1]) = n;
				get<2>(e[i-1]) = n - get<0>(e[i-1]) - 1;
				e.insert(e.begin() + i, make_tuple(n, b, b-n-1));
			}
			else {
				e.insert(e.begin() + i, make_tuple(n, a, a-n-1));
			}
			
			return e;
		}
		else if(n > b && i == e.size()-1) {
			e.push_back(make_tuple(b, n, n-b-1));

			return e;
		}
		
		
	}

	
}

vector<tuple<int, int, int>> removeEdge(vector<tuple<int, int, int>> e, int n) {

	int a, b, c;

	for(int i = 0; i < e.size(); i++) {
		tie(a, b, c) = e[i];

		if(n == a) {
			if(i != 0) {
				get<1>(e[i-1]) = b;
				get<2>(e[i-1]) = b - get<0>(e[i-1]) - 1;
			}

			e.erase(e.begin() + i);
			return e;
		}
		if(n == b && i == e.size()-1) {
			if(i != e.size()-1) {
				get<1>(e[i-1]) = a;
				get<2>(e[i-1]) = a - get<0>(e[i-1]) - 1;
			}

			e.erase(e.begin() + i + 1);
			return e;
		}
	}
}

void printEdges(vector<tuple<int, int, int>> e) {
	for(auto a : e) {
		int x, y, z;
		tie(x, y, z) = a;

		cout << "<" << x << ", " << y << "> -- " << z << "\n";
	}
}

void solve() {
	int n; cin >> n;
    
    vector<tuple<int, int, int>> edges;

	vector<int> v(n);
    for(int i=0; i<n; i++) {
		cin >> v[i];
    }

	for(int i=0; i<n-1; i++) {
		edges.push_back(make_tuple(v[i], v[i+1], v[i+1]-v[i]-1));
	}

	int m; cin >> m;
	for(int i=0; i<m; i++) {
		char symbol;
		int num;
		
		cin >> symbol >> num;

		if(symbol == '+') {
			edges = addEdge(edges, num);
		} else if (symbol == '-') {
			edges = removeEdge(edges, num);
		} else {
			cout << minLoad(edges, num) << " ";
		}

		// printEdges(edges);
		// cout << "\n";
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