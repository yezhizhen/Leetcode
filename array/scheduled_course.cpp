//https://leetcode.com/problems/course-schedule-iii/
//https://leetcode.com/problems/course-schedule-iii/discuss/2185621/C%2B%2B-oror-Step-by-step-explanation-oror-Priority-Queue
class Solution {
public:
    //greedy. wrong answer
    //[[2, 19], [2, 10], [3, 19], [5, 16], [5, 15], [6, 7], [8, 14], [10, 11]]. Output is 4.
    //Actual answer is 5. You need to take [3,19] at last
    int scheduleCourse(vector<vector<int>>& courses) {
        //always pick the one with smallest duration first and see if it can fill
        //if duration is same, try to take the one with closest lastday first
        sort(courses.begin(), courses.end(), [](const auto &c1, const auto &c2){
            return c1 < c2;
        });
        
        int cur_time = 0, ans = 0;
        
        for(auto &c:courses)
            if(c[0] + cur_time <= c[1]) //can take the course
            {
                cur_time += c[0];
                ans++;
            }
        
        return ans;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        //try to take the one with closest lastday first
        sort(courses.begin(), courses.end(), [](const auto &c1, const auto &c2){
            return c1[1] < c2[1];
        });
        priority_queue<int, vector<int>> q;
        
        
        int cur_time = 0;
        //
        for(auto &c:courses)
            if(c[0] + cur_time <= c[1]) //can take the course
            {
                q.push(c[0]);
                cur_time += c[0];
            }
            else if(not q.empty() and q.top() > c[0])
            {
                cur_time += -q.top() + c[0]; 
                q.pop();
                q.push(c[0]);
            }
        return q.size();
    }
    
};