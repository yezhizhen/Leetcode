//https://leetcode.com/problems/furthest-building-you-can-reach/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //first fill the ladder.
        //when we need go up again, remove the weakest ladder being used, and use bricks instead
        priority_queue<int,vector<int>,greater<int>> q;
        int d;
        int b_used = 0;
        for(int i = 1; i < heights.size(); i++){
            d = heights[i] - heights[i-1];
            if(d > 0){
                q.push(d);
                if(q.size() > ladders){
                    int b = q.top(); q.pop();
                    if((b_used += b) > bricks)
                        return i - 1;
                }
            }
        
        }
        return heights.size() - 1;
        
    }
};