#include <bits/stdc++.h>
using namespace std;

int days[7] = {0, 1, 2, 0, 2, 1, 0};
int days1[7]={0, 1, 2, 0, 2, 1, 0};

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int v[3];
    cin >> v[0] >> v[1] >> v[2];
    int ans = 0;
    int mmin = (v[0])/3;
    mmin = min(mmin, v[1]/2);
    mmin = min(mmin, v[2]/2);
    ans += mmin*7;
    v[1] -= mmin*2;
    v[0] -= mmin*3;
    v[2] -= mmin*2;
    int mmax = 0;
    for(int i=0; i<7; i++) {
        int aux[3] = {v[0], v[1], v[2]};
        int sum = 0;
        for(int j=i; aux[days[j%7]] != 0; j++) {
            sum++;
            aux[days[j%7]]--;
        }
        mmax = max(sum, mmax);
    }
    cout << ans+mmax << '\n';
    return 0;
}