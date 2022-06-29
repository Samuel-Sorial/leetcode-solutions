#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;

// https:// leetcode.com/problems/contains-duplicate

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> elements;
        for (int number : nums)
        {
            if (elements.find(number) == elements.end())
            {
                elements.insert(number);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};