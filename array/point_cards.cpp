class Solution {
public:
    //O(k) time
    //O(1) space
    //https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/2199222/C%2B%2B-oror-O(k)-time-oror-O(1)-space-oror-Commented
    int maxScore(vector<int>& cardPoints, int k) {
        int total_sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int ans = total_sum;
        int n = cardPoints.size();
        //replace nums[k - 1 - offset] with *(nums.rbegin() + offset)    
        for(int offset = 0; offset < k; offset++)
        {
            total_sum += cardPoints[n - 1 - offset] - cardPoints[k - 1 - offset];
            ans = max(ans, total_sum);
        }
        return ans;
    }
};