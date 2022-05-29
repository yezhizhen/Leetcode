class Solution {
    using OutEdges = vector<pair<int, int>>; //dest, cost
    using Cost_Index = pair<int,int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //do dikstra shortest path algorithm.
        OutEdges graph[n];
        for(auto &e: times)
            graph[e[0] - 1].emplace_back(e[1] - 1,e[2]);
        int cost[n]; 
        for(int i = 0; i < n; i++)
            cost[i] = INT_MAX;
        cost[k - 1] = 0;
        auto cmp = [&](const Cost_Index &i1, const Cost_Index &i2){return i1.first > i2.first;};
        priority_queue<Cost_Index, vector<Cost_Index>, decltype(cmp)> q(cmp);
        q.emplace(0, k - 1);
        while(not q.empty()){
            auto [cur_cost,cur_reached] = q.top(); q.pop();
            if(cur_cost > cost[cur_reached]) continue;
            //for all outgoing edges of cur_reached
            for(const auto &[dest, c]:graph[cur_reached]){
                if(cur_cost + c < cost[dest])
                {
                    cost[dest] = cur_cost + c;
                    q.emplace(cost[dest],dest);
                }
            }
        }
        int ans = *max_element(cost, cost + n);
        return ans == INT_MAX ? -1 : ans;
    }
};