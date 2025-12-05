int divide(int dividend, int divisor) {
    //Integer overflow case && Hardware edge case
    if((dividend == -2147483648) && (divisor == 1)) return -2147483648;
    if((dividend == -2147483648) && (divisor == -1)) return 2147483647;

    return dividend/divisor;
}