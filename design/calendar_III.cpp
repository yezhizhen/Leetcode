class MyCalendarThree
{
    map<int, int> occ;

public:
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        occ[start]++;
        occ[end]--;
        // compute result
        int cur = 0, res = 0;
        for (const auto &[t, cnt] : occ)
        {
            cur += cnt;
            res = max(res, cur);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */