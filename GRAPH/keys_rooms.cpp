// https://leetcode.com/problems/keys-and-rooms/

#include <vector>
using namespace std;

class Solution
{
public:
    bool visited[1000]{};

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        dfs(rooms, 0);

        for (int i = 0; i < rooms.size(); i++)
            if (!visited[i])
                return false;
        return true;
    }

    void dfs(vector<vector<int>> &neighbors, int r)
    {
        if (visited[r])
            return;
        visited[r] = true;
        for (auto &nei : neighbors[r])
            dfs(neighbors, nei);
    }
};