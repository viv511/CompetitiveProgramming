#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
   int smallest = INT_MAX;
   int bestProfit = 0;

   for (int i = 0; i < prices.size(); i++) {
      smallest = min(smallest, prices[i]);
      bestProfit = max(bestProfit, prices[i] - smallest);
   }
   
   return bestProfit;
}