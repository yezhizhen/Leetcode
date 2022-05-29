class RLEIterator {
    int cur_i, cur_enc_ind;
    vector<int> enc;
public:
    //assume cur_cnt is > 0
    RLEIterator(vector<int>& encoding): enc(move(encoding)) {
        cur_i = 0, cur_enc_ind = 1;
    }
    
    int next(int n) {
        //exhaust n elements
    
        if(cur_enc_ind >= enc.size()) return -1;
        
        cur_i+= n;
        
        while(cur_enc_ind < enc.size() and cur_i > enc[cur_enc_ind - 1]){ //go to next non zero
            cur_i -= enc[cur_enc_ind-1];
            cur_enc_ind += 2;
        }
        if(cur_enc_ind >= enc.size())
            return -1;
        //now cur_i <= enc[cur_enc_ind - 1]
        return enc[cur_enc_ind];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */