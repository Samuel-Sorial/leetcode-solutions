
#include <vector>
using std::vector;

// https://leetcode.com/problems/maximum-subarray/
// O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // for each number, check previous sum, if higher than previous sum + itself, set it as previous sum + itself, else, set number as current
        int currentSum = nums[0];
        int maximum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currentSum = std::max(currentSum + nums[i], nums[i]);
            maximum = std::max(maximum, currentSum);
        }
        return maximum;
    }
};