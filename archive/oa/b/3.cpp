#include <bits/stdc++.h>
using namespace std;


int main(){
	vector<int>  answer;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)if (prime[p]) answer.push_back(p);
    return answer;
	return 0;
}
