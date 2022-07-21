#include <vector>
#include <map>
using std::map;
using std::vector;

// https://leetcode.com/problems/maximum-units-on-a-truck
// O(nlog(n))
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        map<int, int> typeToAvailableBoxes = {};
        for (auto boxType : boxTypes)
        {
            if (typeToAvailableBoxes.find(boxType[1]) != typeToAvailableBoxes.end())
            {
                typeToAvailableBoxes[boxType[1]] += boxType[0];
            }
            else
            {
                typeToAvailableBoxes[boxType[1]] = boxType[0];
            }
        }
        int sum = 0;
        int usedBoxes = 0;
        for (auto boxType = typeToAvailableBoxes.rbegin(); boxType != typeToAvailableBoxes.rend(); ++boxType)
        {
            if (usedBoxes == truckSize)
            {
                break;
            }
            int boxesCanBeUsed = std::min(boxType->second, truckSize - usedBoxes);
            sum += boxType->first * boxesCanBeUsed;
            usedBoxes += boxesCanBeUsed;
        }
        return sum;
    }
};