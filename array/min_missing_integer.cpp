#include <vector>

#include <algorithm>
using namespace std;
int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int number_to_match = 1;
    auto it = lower_bound(A.begin(), A.end(), 1);
    while (it != A.end())
    {
        if (*it != number_to_match)
            return number_to_match;
        it++, number_to_match++;
    }
    return number_to_match;
}

int solution(vector<int> &A)
{
    int n = A.size();
    // smallest missing
    // cyclic sort
    //[1,n]

    // for element with value x. put it in A[x - 1]
    // those > than n and those <= 0?

    for (int i = 0; i < n; i++)
    {
        while (A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[i] != A[A[i] - 1])
            swap(A[i], A[A[i] - 1]);
    }

    // check from index
    for (int i = 0; i < n; i++)
        if (A[i] != i + 1)
            return i + 1;
    return n + 1;
}