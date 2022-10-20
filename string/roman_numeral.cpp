// https://leetcode.com/problems/integer-to-roman/
#include <string>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        if (num == 0)
            return "";
        if (num >= 1000)
            return string(num / 1000, 'M') + intToRoman(num % 1000);
        else if (num >= 900)
            return "CM" + intToRoman(num - 900);
        else if (num >= 500)
            return "D" + intToRoman(num - 500);
        else if (num >= 400)
            return "CD" + intToRoman(num - 400);
        else if (num >= 100)
            return string(num / 100, 'C') + intToRoman(num % 100);
        else if (num >= 90)
            return "XC" + intToRoman(num - 90);
        else if (num >= 50)
            return "L" + intToRoman(num - 50);
        else if (num >= 40)
            return "XL" + intToRoman(num - 40);
        else if (num >= 10)
            return string(num / 10, 'X') + intToRoman(num % 10);
        else if (num == 9)
            return "IX";
        else if (num >= 5)
            return "V" + intToRoman(num - 5);
        else if (num == 4)
            return "IV";
        else
            return string(num, 'I');
    }

    // iterative
    string intToRoman(int num)
    {
        string res;
        while (num > 0)
        {
            if (num >= 1000)
                res += string(num / 1000, 'M'), num %= 1000;
            else if (num >= 900)
                res += "CM", num -= 900;
            else if (num >= 500)
                res += "D", num -= 500;
            else if (num >= 400)
                res += "CD", num -= 400;
            else if (num >= 100)
                res += string(num / 100, 'C'), num %= 100;
            else if (num >= 90)
                res += "XC", num -= 90;
            else if (num >= 50)
                res += "L", num -= 50;
            else if (num >= 40)
                res += "XL", num -= 40;
            else if (num >= 10)
                res += string(num / 10, 'X'), num %= 10;
            else if (num == 9)
                res += "IX", num -= 9;
            else if (num >= 5)
                res += "V", num -= 5;
            else if (num == 4)
                res += "IV", num -= 4;
            else
                res += string(num, 'I'), num = 0;
        }
        return res;
    }
};