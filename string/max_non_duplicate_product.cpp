class Solution {
    //there can be at most 26 words that do not share common letters.
    //most of them do share a common letter
public:
    int maxProduct(vector<string>& words) {
        //preprocess O(N * S), N is size of words, S is size of largest word
        int n = words.size();
        int mask[n]; //the occurence is masked with bit, with 26 bits
        
        for(int i = 0; i < n; i++)
            for(char c: words[i])
                mask[i] |= (1 << (c - 'a'));
        
        //O(N * N) time for comparing pairs
        int ans = 0;
        for(int i = 0 ; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(!(mask[i] & mask[j]))//has no duplicates
                    ans = max<int>(ans, words[i].size() * words[j].size());
        return ans;
    }
};