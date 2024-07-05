// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void solve();
bool substringExist(string seq, string sub);
string a, b;

int main() {
	int T; cin >> T;

	while(T--) {
		solve();
	}
}

void solve() {
	cin >> a >> b;

	//A is the subtring, B is the subsequence
	//ans = sub + seq - matches

	int matches = 0;
	for(int size=b.length(); size>1; size--) {
		for(int i=0; i<b.length() - size + 1; i++) {
			string smallerString = b.substr(i, size);

			cout << smallerString << "\n";

			if(substringExist(smallerString, a)) {
				matches = max(matches, size);
			}
		}
	}

	cout << a.length() + b.length() - matches << "\n";
}

bool substringExist(string seq, string sub) {
	int seqIndex = 0;

	for(int i=0; i<sub.length(); i++) {
		if(seq[seqIndex] == sub[i]) {
			seqIndex++; //See if all chars exist within sub
		}
	}

	if(seqIndex == seq.length()) {
		return true;
	}
	else {
		return false;
	}
}