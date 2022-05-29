//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
struct Interval{
    int left_end{INT_MAX}, right_end{INT_MIN};
};

class Solution {
    public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> num_to_indices;
        for(int i = 0; i < n; i++)
        num_to_indices[arr[i]].push_back(i);
        sort(arr.begin(), arr.end());
        
        using root = int; unordered_map<root, Interval> intervals_set;
        auto &res0 = (intervals_set[0] = {0,0});
        for(const int old_ind: num_to_indices[arr[0]])
        {
            res0.left_end  = min(res0.left_end, old_ind);
            res0.right_end = max(res0.right_end, old_ind);
        }
        int cur_root = 0;
        for(int i = 1; i < n; i++){
            
            cur_root = (arr[i] == arr[i-1]) ? cur_root : i;
            auto &res = intervals_set[cur_root];
            res.left_end = min(res.left_end, i);
            res.right_end = max(res.right_end, i);
            if(arr[i] != arr[i - 1])
                for(const int old_ind: num_to_indices[arr[i]])
                {
                    res.left_end = min(res.left_end, old_ind);
                    res.right_end = max(res.right_end, old_ind);
                }            
        }
        vector<Interval> intervals; intervals.reserve(intervals_set.size());
        //merge intersecting intervals
        for(auto &[ro, tmp]:intervals_set)
            intervals.push_back(tmp);
        //sort intervals by start
        sort(intervals.begin(), intervals.end(), [](auto &i1, auto &i2){
                return i1.left_end < i2.left_end;
            });
        return merge_intervals(intervals);
    }
    
    //assumption: intervals are sorted
    //return # of non-intersecting intervals
    int merge_intervals(vector<Interval>& intervals){
        int ans{};
        int pre_end{-1};
        for(auto &tmp: intervals){
            if(tmp.left_end > pre_end) //beginning of a new set
                ans++, pre_end = tmp.right_end;
            else //interesecting
                pre_end = max(pre_end, tmp.right_end);
        }
        return ans;
    }
    
};