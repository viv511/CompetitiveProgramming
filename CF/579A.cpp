#include <iostream>
using namespace std;

int main() {
	int x; cin >> x;
	cout << __builtin_popcount(x);
}

//Every time you double a number the 1 will shift one to the left
//therefore # of 1s will be the amount of things that u needed to add
//and we let some a_i days pass by to double the bacteria to each value of x
