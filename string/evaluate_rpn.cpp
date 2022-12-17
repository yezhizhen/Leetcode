// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <vector>
#include <string>
#include <ctype.h>
#include <unordered_set>
using namespace std;

// wrong interpretation
class Solution
{
    unordered_set<string> operators{"+", "-", "*", "/"};

public:
    int evalRPN(vector<string> &tokens)
    {
        return eval(tokens, 0, tokens.size() - 1);
    }

    // get the value of the expression from start_index to end_index
    int eval(vector<string> &tokens, int start_index, int end_index)
    {
        if (end_index == start_index)
            return stoi(tokens[start_index]);

        // branch on tokens[end_index] operator
        if (!operators.count(tokens[end_index - 1]))
        {
            if (tokens[end_index] == "+")
                return eval(tokens, start_index, end_index - 2) + stoi(tokens[end_index - 1]);
            else if (tokens[end_index] == "-")
                return eval(tokens, start_index, end_index - 2) - stoi(tokens[end_index - 1]);
            else if (tokens[end_index] == "*")
                return eval(tokens, start_index, end_index - 2) * stoi(tokens[end_index - 1]);
            else if (tokens[end_index] == "/")
                return eval(tokens, start_index, end_index - 2) / stoi(tokens[end_index - 1]);
        }
        else
        {
            if (tokens[end_index] == "+")
                return stoi(tokens[start_index]) + eval(tokens, start_index + 1, end_index - 1);
            else if (tokens[end_index] == "-")
                return stoi(tokens[start_index]) - eval(tokens, start_index + 1, end_index - 1);
            else if (tokens[end_index] == "*")
                return stoi(tokens[start_index]) * eval(tokens, start_index + 1, end_index - 1);
            else if (tokens[end_index] == "/")
                return stoi(tokens[start_index]) / eval(tokens, start_index + 1, end_index - 1);
        }
        return 0;
    }
};

// correct one after reading the definition
class Solution
{
    unordered_set<string> operators{"+", "-", "*", "/"};
    vector<long> stack;

public:
    int evalRPN(vector<string> &tokens)
    {
        for (int i = 0; i < tokens.size(); i++)
            if (operators.count(tokens[i]))
            {
                long op2 = stack.back();
                stack.pop_back();
                long op1 = stack.back();
                stack.pop_back();
                if (tokens[i] == "+")
                    stack.push_back(op1 + op2);
                else if (tokens[i] == "-")
                    stack.push_back(op1 - op2);
                else if (tokens[i] == "*")
                    stack.push_back(op1 * op2);
                else if (tokens[i] == "/")
                    stack.push_back(op1 / op2);
            }
            else
                stack.push_back(stoi(tokens[i]));
        return stack.back();
    }
};