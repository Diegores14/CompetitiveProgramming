#include <bits/stdc++.h>
using namespace std;
int pos[100005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long a, b, m, r;
    cin >> a >> b >> m >> r;
    memset(pos, -1, sizeof pos);
    int i = 0;
    while(pos[r] == -1) {
        pos[r] = i++;
        r = (a*r + b) % m;
    }
    //cout << i << ' ' <<  pos[r] << '\n';
    cout << i - pos[r] << '\n';
    return 0;
}