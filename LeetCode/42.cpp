#include <vector>
using namespace std;

int trap(vector<int>& height) {
   int n = height.size();
   int ans = 0;

   if (n == 0) return 0;

   int l = 0;
   int r = n - 1;
   int maxLeft = -1;
   int maxRight = -1;

   while (l < r) {
      maxLeft = max(maxLeft, height[l]);
      maxRight = max(maxRight, height[r]);

      if (maxLeft < maxRight) {
         ans += (maxLeft - height[l]);
         l++;
      }
      else {
         ans += (maxRight - height[r]);
         r--;
      }
   }

   return ans;
}