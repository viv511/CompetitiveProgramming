#include <cmath>

int arrangeCoins(int n) {
    // want to find largest T_i = i(i+1)/2 s.t. T_i <= n
    // 8T_i + 1 <= 8n + 1 (use perfect square identity w/ triangular #s)
    // 4i*(i+1) + 1 <= 8n + 1
    // 4i^2+4i+1 <= 8n + 1
    // (2i + 1)^2 <= 8n + 1
    // 2i + 1 <= sqrt(8n+1)
    // i <= (sqrt(8n+1) - 1) / 2

    return (sqrt(8LL * n + 1) - 1) / 2;
}