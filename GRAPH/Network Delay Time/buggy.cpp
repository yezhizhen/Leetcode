//the problem is that duplicate value in priority queue result in error. cannot swap correctly.
class Solution {
    using OutEdges = vector<pair<int, int>>; //dest, cost
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //do dikstra shortest path algorithm.
        OutEdges graph[n];
        for(auto &e: times)
            graph[e[0] - 1].emplace_back(e[1] - 1,e[2]);
            
        bool visited[n]; memset(visited, 0, sizeof(visited));
        int cost[n]; 
        for(int i = 0; i < n; i++)
            cost[i] = INT_MAX;
        cost[k - 1] = 0;
        auto cmp = [&](const int &i1, const int &i2){return cost[i1] > cost[i2];};
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        q.push(k - 1);
        int ans = -1;
        while(not q.empty()){
            int cur_reached = q.top(); q.pop();
            if(visited[cur_reached]) continue;
            visited[cur_reached] = true;
            //for all outgoing edges of cur_reached
            for(const auto &[dest, c]:graph[cur_reached]){
                if(not visited[dest] and cost[cur_reached] + c < cost[dest])
                {
                    cost[dest] = cost[cur_reached] + c;
                    q.push(dest);
                }
            }
        }
        for(int i = 0; i < n; i++)
            ans = max(ans, cost[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};