// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int write_next = 1;
        for (int read = 1; read < nums.size(); read++)
        {
            if (nums[read] != nums[read - 1])
                nums[write_next++] = nums[read];
        }
        return write_next;
    }
};