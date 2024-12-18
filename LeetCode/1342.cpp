class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0; //edge case

        return (32-__builtin_clz(num)) + __builtin_popcount(num) - 1;
        //Note that any 1s in the middle require a substraction operation, and each division by 2 is like a bit shift
    }
};