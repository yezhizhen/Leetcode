// https://leetcode.com/problems/remove-stones-to-minimize-the-total/
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        // O(n) time to heapify
        int sum = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> heap(less<int>(), move(piles));

        for (int i = 0; i < k; i++)
        {
            int to_remove = heap.top() / 2;
            int remain = heap.top() - to_remove;
            sum -= to_remove;
            heap.pop();
            heap.push(remain);
        }
        return sum;
    }
};