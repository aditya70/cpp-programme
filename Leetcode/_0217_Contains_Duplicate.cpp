#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ump[nums[i]]++;
            if (ump[nums[i]] > 1)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> v{1, 2, 1, 3};
    Solution ob;
    cout << ob.containsDuplicate(v);
    return 0;
}