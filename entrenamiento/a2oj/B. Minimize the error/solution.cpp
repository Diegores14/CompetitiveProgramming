#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl

int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    vector<long long> f(n), s(n);
    for (auto &it : f) cin >> it;
    for (auto &it : s) cin >> it;
    for (int i = 0; i < a; i++) {
      int maxd = -1, pos = -1;
      for (int j = 0; j < n; j++) {
        int dist = abs(f[j] - s[j]);
        if (dist > maxd) {
          maxd = dist; pos = j;
        }
      }
      f[pos] += (f[pos] > s[pos]) ? -1 : 1;
    }
    for (int i = 0; i < b; i++) {
      int maxd = -1, pos = -1;
      for (int j = 0; j < n; j++) {
        int dist = abs(f[j] - s[j]);
        if (dist > maxd) {
          maxd = dist; pos = j;
        }
      }
      s[pos] += (s[pos] > f[pos]) ? -1 : 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (f[i] - s[i]) * (f[i] - s[i]);
    }
    cout << ans << endl;
  }
  return 0;
}