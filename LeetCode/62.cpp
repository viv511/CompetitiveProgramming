long long choose(int a, int b) {
    if (b > a - b) {
        b = a - b;
    }

    long long res = 1;
    for (int i = 1; i <= b; i++) {
        res = res * (a - b + i) / i;
    }

    return res;
}

int uniquePaths(int m, int n) {
    m--;
    n--;

    if(m == 0 || n == 0) return 1;

    //m + n choose m
    return choose(m + n, m);
}