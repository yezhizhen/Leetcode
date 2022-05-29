//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
struct UF{
    int parts;
    vector<int> p; //parent
    UF(int n): p(n), parts{n}{
        for(int i = 0; i < n; i++)
            p[i] = i;
    }
    
    int find(int x){
        if(p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }
    
    void unite(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        parts--;
        p[rx] = ry;
    }
}

struct Interval{
    int left_end{INT_MAX}, right_end{INT_MIN};
}

class Solution {
    
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        UF uf(n);
        unordered_map<int, vector<int>> num_to_indices;
        for(int i = 0; i < n; i++)
            num_to_indices[arr[i]].push_back(i);
        sort(arr.begin(), arr.end());
        for(const int old_ind: num_to_indices[arr[0]])
            uf.unite(0, old_ind);
        for(int i = 1; i < n; i++)
            if(arr[i] == arr[i - 1])
                uf.unite(i - 1, i);
            else
                for(const int old_ind: num_to_indices[arr[i]])
                    uf.unite(i, old_ind);
        using root = int;
        unordered_map<root, Interval> intervals_set;
        //build up intervals_set
        for(int i = 0; i < n; i++){
            int i_root = uf.find(i);
            auto &res =  intervals_set[i_root]; 
            res.left_end = min(res.left_end, i);
            res.right_end = max(res.right_end, i);
        }
        //merge intersecting intervals
        
        
    }
    
    
    
    //solve for [left, right]
    int solve(vector<int>& arr, int left, int right){
        if(left == right) return 1;
        int r = -1, max_val{INT_MIN};
        //scan from left to right
        for(int i = left; i <= right; i++){
            if(arr[i] < max_val)
                r = i;
            else
                max_val = arr[i];
        }
        if(r == -1)
            return right - left + 1;
        int l, min_val{INT_MAX};
        for(int i = right; i >= left; i--){
            if(arr[i] > min_val)
                l = i;
            else
                min_val = arr[i];
        }
        //whole array needs to be sorted. find out what remains there
        if(right == r and l == left)
        {
            
        }
        return right - left - r  + l +  solve(arr, l, r);
    }
    
};