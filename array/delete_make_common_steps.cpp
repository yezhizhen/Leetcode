//https://leetcode.com/problems/delete-operation-for-two-strings/
class Solution {
public:
    int minDistance(string word1, string word2) {
        //longest common subsequence
        int n1 = word1.size(), n2 = word2.size();
        vector<int> pre(n2 + 1, 0), cur(n2 + 1, 0);
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(word1[i] == word2[j])
                    cur[j+1] = pre[j] + 1;
                else
                    cur[j+1] = max(pre[j + 1], cur[j]);
            }
            swap(pre, cur);
        }
        return n1 + n2 - 2 * pre[n2];
    }
};