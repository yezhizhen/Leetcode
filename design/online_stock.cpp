// https://leetcode.com/problems/online-stock-span/
#include <vector>
using namespace std;
class StockSpanner
{
    struct Entry
    {
        int value, consecutive_days;
        Entry(int v, int d) : value{v}, consecutive_days{d}
        {
        }
    };
    vector<Entry> stack;

public:
    StockSpanner()
    {
        // padding
        stack.emplace_back(INT_MAX, 0);
    }

    int next(int price)
    {
        int day = 1;
        while (price >= stack.back().value)
        {
            day += stack.back().consecutive_days;
            stack.pop_back();
        }

        stack.emplace_back(price, day);
        return day;
    }
};