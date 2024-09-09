//https://leetcode.com/problems/happy-number/description/

#include <iostream>
using namespace std;

int sumSquareDigits(int n) {
	long long ans = 0;

	while(n != 0) {
		ans += pow((n%10), 2);
		n /= 10;
	}

	return ans;
}

int main() {
	int n; cin >> n;

	while(n != 1) {
		n = sumSquareDigits(n);
		if(n == 4) {
			return false;
		}
	}
	return true;
}
