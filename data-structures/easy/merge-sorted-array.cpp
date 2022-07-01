#include <vector>
using std::vector;

// O(m+n) using O(1) memory
class Solution
{

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int mIndex = m - 1;
        int nIndex = n - 1;
        for (int curr = nums1.size() - 1; curr >= 0; curr--)
        {
            if (mIndex < 0)
            {
                nums1[curr] = nums2[nIndex--];
            }
            else if (nIndex < 0)
            {
                nums1[curr] = nums1[mIndex--];
            }
            else
            {
                if (nums1[mIndex] > nums2[nIndex])
                {
                    nums1[curr] = nums1[mIndex--];
                }
                else
                {
                    nums1[curr] = nums2[nIndex--];
                }
            }
        }
    }
};

// O(m+n) using O(m) memory
class SolutionUsingMoreMemoryButReadable
{
private:
    void shiftTo(vector<int> &nums, int shiftStart, int elements)
    {
        int length = nums.size();
        int *playground = new int[elements];
        if (length == 1 || shiftStart == 0)
        {
            return;
        }
        for (int i = 0; i < elements; i++)
        {
            playground[i] = nums[i];
        }
        for (int i = 0; i < elements; i++)
        {
            nums[shiftStart++] = playground[i];
        }
        delete[] playground;
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        shiftTo(nums1, n, m);
        int mIndex = nums1.size() - m;
        int nIndex = 0;
        for (int curr = 0; curr < nums1.size(); curr++)
        {
            if (mIndex >= nums1.size())
            {
                nums1[curr] = nums2[nIndex++];
            }
            else if (nIndex >= nums2.size())
            {
                nums1[curr] = nums1[mIndex++];
            }
            else
            {
                if (nums1[mIndex] < nums2[nIndex])
                {
                    nums1[curr] = nums1[mIndex++];
                }
                else
                {
                    nums1[curr] = nums2[nIndex++];
                }
            }
        }
    }
};