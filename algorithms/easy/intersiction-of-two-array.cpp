#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

// https://leetcode.com/problems/intersection-of-two-arrays-ii
// O(n) with O(nums1) memory
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> intersction = {};
        unordered_map<int, int> numbers = {};
        for (auto num : nums1)
        {
            if (numbers.find(num) != numbers.end())
            {
                numbers[num] += 1;
            }
            else
            {
                numbers[num] = 1;
            }
        }
        for (auto num : nums2)
        {
            if (numbers.find(num) != numbers.end())
            {
                intersction.push_back(num);
                if (numbers[num] == 1)
                {
                    numbers.erase(num);
                }
                else
                {
                    numbers[num] -= 1;
                }
            }
        }
        return intersction;
    }
};