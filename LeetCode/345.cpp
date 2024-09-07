//https://leetcode.com/problems/reverse-vowels-of-a-string/description

#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
	string vowels = "aeiouAEIOU";
	string vowelList = "";

	for(int i=0; i<s.length(); i++) {
		if(vowels.find(s[i]) != string::npos) {
			vowelList = s[i] + vowelList; 
		}
	}
	
	int index = 0;
	string ans = "";
	for(int i=0; i<s.length(); i++) {
		if(vowels.find(s[i]) != string::npos) {
			ans += vowelList[index];
			index++;
		}
		else {
			ans += s[i];
		}
	}
	cout << ans;
}