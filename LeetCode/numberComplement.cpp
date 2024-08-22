#include <iostream>

using namespace std;


//Bit masks!
class Solution {
public:
    int findComplement(int num) {
        // cout << __builtin_clz(num);
        return ~num;
    }
};