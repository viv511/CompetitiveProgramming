#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0;

    int l = 0;
    int r = height.size() - 1;

    while(l != r) {
        int area = min(height[l], height[r]) * (r - l);
        maxArea = max(maxArea, area);

        if(height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }

    return maxArea;
}