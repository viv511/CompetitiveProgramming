int hammingWeight(int n) {
    return __builtin_popcount(n);
}

// or alternatively, do a while loop til n != 0 and each n &= (n - 1) drops lsb