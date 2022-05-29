//https://leetcode.com/problems/critical-connections-in-a-network/
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto &e: connections)
            if(e[0] > e[1])
                swap(e[0],e[1]);
        
    }
};