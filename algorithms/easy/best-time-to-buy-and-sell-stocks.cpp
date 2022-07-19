#include <vector>
using std::max;
using std::min;
using std::vector;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// O(n) with O(1) memory
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int currentMin = INT32_MAX;
        for (int price : prices)
        {
            currentMin = min(currentMin, price);
            maxProfit = max(maxProfit, price - currentMin);
        }
        return maxProfit;
    }
};