// Source: https://usaco.guide/general/io
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int distance(int x, int y, int x2, int y2) {
	return sqrt(pow((x2-x), 2) + pow((y2-y), 2));
}

int main() {
	int n; cin >> n;
	int x, y; cin >> x >> y;

	int minVal = 1e16;
	int minIndex = 1;
	vector<pair<int, int>> v;
	for(int i=0; i<n; i++) {
		int a, b; cin >> a >> b;
		v.push_back(make_pair(a, b));

		if(distance(x, y, a, b) < minVal) {
			minIndex = i;
			minVal = distance(x, y, a, b);
		}
	}

	cout << v[minIndex].first << " " << v[minIndex].second;
}
