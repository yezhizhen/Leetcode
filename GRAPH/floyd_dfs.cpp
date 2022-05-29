//https://leetcode.com/problems/course-schedule-iv/
//I solved it using adapted DFS.
class Solution {
    int n;
    bool edges[100][100]{};//edges[i][j]: whether i has a path to j
    bool visited[100];
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        n = numCourses;
        //build edges
        for(auto &e: prerequisites)
            edges[e[0]][e[1]] = true;
        
        //start searching from i
        for(int i = 0; i < n; i++)
        {
            memset(visited, 0, sizeof(visited));
            dfs(i, i); // all edges[0..i - 1][...] already well computed to show connectivity
        }
        vector<bool> ans; ans.reserve(queries.size());
        
        for(auto &q: queries)
            ans.push_back(edges[q[0]][q[1]]);
        return ans;
        
    }
    
    
    void dfs(int i, int source){
        if(visited[i])  return;
        visited[i] = true;
        //check all neighbors of already computed. no need DFS
        for(int j = 0; j < source; j++)
            if(edges[i][j]){
                edges[source][j] = true;
                for(int k = 0; k < n; k++)
                    if(edges[j][k])
                        edges[source][k] = true;
            }
        
        for(int j = source + 1; j < n; j++){
            if(edges[i][j]){
                edges[source][j] = true;
                dfs(j, source);
            }
        }
    }
    
};