class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0;
        int min_sal = 1e7, max_sal = 0; 
        for(int sal: salary)
            min_sal = min(min_sal, sal), max_sal = max(max_sal, sal), sum += sal;
        sum -= (min_sal + max_sal);
        return double(sum) / (salary.size() - 2);
    }
};