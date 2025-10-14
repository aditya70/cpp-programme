#include <algorithm>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 501, kM = 1e9 + 7;

string a, b;
Pii f[kMaxN] = {{0, 1}}, ans;
int p[kMaxN], lp, la, lb, t;

void U(Pii &x, Pii _x) {
  if (_x.first < x.first) {
    x = _x;
  } else if (_x.first == x.first) {
    x.second = (x.second + _x.second) % kM;
  }
}

int main() {
  for (cin >> t; t; t--) {
    cin >> a >> b;
    la = a.size(), lb = b.size();
    fill(f + 1, f + la + 1, ans = make_pair(kMaxN, lp = 0));
    for (int i = 1; i <= la; i++) {
      if (p[i] = (i >= lb && a.substr(i - lb, lb) == b)) {
        lp = i;
        for (int j = i - lb, k = 0; j >= k; j--) {
          U(f[i], {f[j].first + 1, f[j].second});
          if (p[j] && !k) {
            k = j - lb + 1;
          }
        }
      }
    }
    if (!lp) {
      ans = {0, 1};
    } else {
      for (int i = lp - lb + 1; i <= lp; i++) {
        U(ans, f[i]);
      }
    }
    cout << ans.first << ' ' << ans.second << '\n';
  }
  return 0;
}