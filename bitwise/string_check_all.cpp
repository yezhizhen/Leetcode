class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> seen;
        int current_int= stoi(s.substr(0,k), nullptr, 2); seen.insert(current_int);
        const int max_size = pow(2, k);
        for(int i = k; i< s.size() and seen.size() < max_size; i++)
        {
            current_int = ((current_int << 1) &  ~(1 << k) ) + ( s[i] - '0');
            seen.insert(current_int);
        }
        return seen.size() == max_size;
    }    
};
