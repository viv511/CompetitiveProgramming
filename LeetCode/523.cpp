#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
   unordered_map<int, int> m;

   long long p = 0;
   m[0] = -1;

   for (int i=0; i<nums.size(); i++) {
      p += nums[i];

      if (k != 0) p %= k;

      if (m.count(p)) {
         if (i - m[p] >= 2) {
            return true;
         }
      }
      else {
         m[p] = i;
      }
   }

   return false;
}