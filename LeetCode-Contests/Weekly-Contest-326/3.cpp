#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> closestPrimes(int a, int b)
    {
        vector<int> v(2);
        v[0] = -1;
        v[1] = -1;
        vector<int> ve;
        int i, j;
        if (a <= 2)
        {
            a = 2;
            if (b >= 2)
            {
                ve.push_back(a);
                a++;
            }
        }
        if (a % 2 == 0)
            a++;

        for (i = a; i <= b; i = i + 2)
        {

            bool flag = 1;
            for (j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                if (i == 1)
                    continue;
                else
                {
                    ve.push_back(i);
                }
            }
        }

        int m = INT_MAX;
        if (ve.size() > 1)
        {
            for (i = 1; i < ve.size(); i++)
            {
                if (ve[i] - ve[i - 1] < m)
                {
                    v[0] = ve[i - 1];
                    v[1] = ve[i];
                    m = ve[i] - ve[i - 1];
                }
            }
        }
        return v;
    }
};

int main()
{
    Solution ob;
    vector<int> vec;
    vec = ob.closestPrimes(4, 6);
    for (auto i : vec)
    {
        cout << i << endl;
    }
    return 0;
}