bool isPalindrome(int x) {
    if(x < 0) return false;

    long long ans = 0; long long y = x;
    while(y != 0) {
        ans *= 10;
        ans += y % 10;
        y /= 10;
    }
    
    return (ans == x);
}