// https://leetcode.com/problems/top-k-frequent-words/
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> occ;
        for (auto const &s : words)
            occ[s]++;

        vector<pair<int, string>> cnt_string;
        cnt_string.reserve(occ.size());
        for (const auto &[s, cnt] : occ)
            cnt_string.emplace_back(move(cnt), move(s));

        sort(cnt_string.begin(), cnt_string.end(), [](auto &p1, auto &p2)
             {
            if(p1.first > p2.first)
                return true;
            else if(p1.first < p2.first)
                return false;
            else //lower lexi come first
                return p1.second < p2.second; });
        vector<string> res;
        res.reserve(k);
        for (int i = 0; i < k; i++)
            res.push_back(move(cnt_string[i].second));
        return res;
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> occ;
        for (auto const &s : words)
            occ[s]++;

        vector<string> res;
        res.reserve(occ.size());
        for (const auto &[s, cnt] : occ)
            res.emplace_back(s);

        sort(res.begin(), res.end(), [&occ](const auto &p1, const auto &p2)
             {
            if(occ[p1] > occ[p2])
                return true;
            else if(occ[p1] < occ[p2])
                return false;
            else //lower lexi come first
                return p1<p2; });
        res.erase(res.begin() + k, res.end());
        return res;
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> occ;
        for (auto const &s : words)
            occ[s]++;

        // min priority queue. keep poping smallest to maintain k largest
        auto cmp = [&occ](const auto &p1, const auto &p2)
        {
            if(occ[p1] > occ[p2])
                return true;
            else if(occ[p1] < occ[p2])
                return false;
            else //lower lexi come first
                return p1<p2; };
        priority_queue<string, vector<string>, decltype(cmp)> q(cmp);

        for (auto const &[s, cnt] : occ)
        {
            if (q.size() < k)
                q.push(s);
            else
            {
                const string &cur_min = q.top();
                if (cmp(s, cur_min))
                {
                    q.pop();
                    q.push(s);
                }
            }
        }
        // now, extract the queue
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--)
        {
            res[i] = move(q.top());
            q.pop();
        }
        return res;
    }
};