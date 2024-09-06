//https://leetcode.com/problems/number-complement/description/?envType=daily-question&envId=2024-08-22

#include <iostream>

using namespace std;

void printBits(int n) {
	for(int k=31; k>=0; k--) {
		if(n&(1<<k)) {
			cout << "1";
		}
		else {
			cout << "0";
		}
	}

	cout << "\n";
}

//Bit masks!
class Solution {
public:
    int findComplement(int n) {
        //5 == 101 ==> flip is 010 == 2
        // printBits(n);

        int maskLength = 32-__builtin_clz(n);

        for(int i=0; i<maskLength; i++) {
            //1 << i gives us a "1" in the i-th bit
            //XOR each time to get the new number
            n = n ^ (1 << i);
            // printBits(n);
        }

        return n;
    }
};