
#include <bits/stdc++.h>
using namespace std;

class ReverseInteger
{
public:
int reverse(int x) {
        int ans = 0;
        while (x) {
            int temp = ans * 10 + x % 10;
            if (temp / 10 != ans)
                return 0;
            ans = temp;
            x /= 10;
        }
        return ans;
}
};

int main() {
    ReverseInteger obj;
    cout<<obj.reverse(2345);
}

