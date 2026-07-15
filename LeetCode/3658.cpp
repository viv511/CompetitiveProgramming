// sum of n positive odds:
// = (1 + 1 + 1 + ... + 1) + (0 + 2 + 4 + ...)
// = n + (2 + 4 + 6 + ...)
// = n + 2(1 + 2 + 3 + ... + n-1)
// = n + 2 * (n-1)*n/2 = n + n(n-1)
// = n^2

// sum of n positive evens:
// = 2 + 4 + 6 + ... 
// = 2(n(n+1)/2)
// = n(n+1)

// thus the gcd of them must always be n...
int gcdOfOddEvenSums(int n) {
    return n;
}