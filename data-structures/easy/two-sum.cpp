#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/two-sum
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> indicies = {};
        unordered_map<int, int> numToIndex = {};
        for (int i = 0; i < nums.size(); i++)
        {
            int current = nums[i];
            int remainder = target - current;
            if (numToIndex.find(remainder) != numToIndex.end())
            {
                return {i, numToIndex[remainder]};
            }
            else
            {
                numToIndex[current] = i;
            }
        }
        return indicies;
    }
};