//https://leetcode.com/problems/gcd-sort-of-an-array/

struct UF{    
    UF(int n_): p(n_), rank(n_){
        for(int i = 0; i < p.size(); i++)
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
        if(rank[rx] > rank[ry])
            p[ry] = rx;
        else if(rank[rx] < rank[ry])
            p[rx] = ry;
        else{
            p[rx] = ry, rank[ry]++;
        }
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
private:
    vector<int> rank, p;
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        UF uf(max_val + 1);
        
        for(int num: nums){
            //unite with prime factor
            int old_num = num;
            for(int factor = 2; factor * factor <= num; factor++){
                bool is_factor{false};
                while(num % factor == 0)
                {
                    is_factor = true; num/= factor;
                }
                if(is_factor){
                    uf.unite(old_num, factor);
                }
                if(num > 1)
                    uf.unite(old_num, num);
            }    
        }
        //create a sorted copy of num.
        //check if the original element at that index is in the same 
        //group
        auto nums_copy = nums;
        sort(nums_copy.begin(), nums_copy.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != nums_copy[i])
            {
                if(not uf.connected(nums[i], nums_copy[i]))
                    return false;
            }
        }
        
        return true;
    }
};