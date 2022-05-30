//https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool negative_result = (dividend >= 0) xor (divisor >= 0);
        if(dividend == -2147483648  and divisor == -1) return 2147483647; //check boundary case
        dividend = abs(dividend), divisor = abs(divisor);   //make everything positive
        return negative_result ? - div(dividend, divisor) : div(dividend, divisor);
    }
    
    long div(long a, long b){
        if(a < b)   return 0;
        int res = 0;
        //whether the i-th bit of the final result is 1
        for(int i = 31; i >= 0; i--)
        {
            if((b << i) <= a){
                res |= (1 << i);
                a -= (b << i);
            }
        }
        return res;
    }
};