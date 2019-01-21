#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<string> crop({"Grapes", "Carrots", "Kiwis"});
    vector< vector<long long> > v(n+1);
    long long x, y;
    for(long long i=0; i<k; i++) {
        cin >> x >> y; 
        v[x].emplace_back(y);
    }
    vector<long long> prefix(n+1, 0);
    for(long long i=1; i<=n; i++) {
        sort(v[i].begin(), v[i].end());
        prefix[i] += v[i].size() + prefix[i-1];
    }
    for(long long i=0; i<t; i++) {
        cin >> x >> y;
        //cout << x << ' ' << y << ' ';
        long long cant = prefix[x-1];
        long long l = -1, r = v[x].size();
        //cout << cant << ' ';
        while(r-l != 1) {
            long long mid = (l+r)>>1;
            if(v[x][mid] <= y) {
                l = mid;
            } else {
                r = mid;
            }
        }
        //cout << l << ' ' << ((x-1)*m + y - cant - l - 1) << ' ' << '\n';
        if(l == -1 || v[x][l] != y)
            cout << crop[(( (x-1)*m + y - cant - l - 1)%3)] << '\n';
        else 
            cout << "Waste\n";
    }
    return 0;
}