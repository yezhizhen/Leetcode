//https://leetcode.com/problems/my-calendar-ii/
class MyCalendarTwo {
    map<int, int> flow; //sorted by t.
public:
    MyCalendarTwo() {
        //pre-padding an end point
        
    }
    
    bool book(int start, int end) {
        flow[start]++, flow[end]--;
        int cur = 0;
        for(auto &time_stamp:flow)
        {
            cur += time_stamp.second;
            if(cur >= 3)
            {
                flow[start]--, flow[end]++;
                return false;
            }
        }
        
        return true;
    }
};