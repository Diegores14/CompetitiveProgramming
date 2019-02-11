#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    unsigned long long n, b, ans = 1e18;
    cin >> n >> b;
    vector< pair<long long,int> > v;
    for(unsigned long long i=2; i*i<=b; i++) {
        if(b%i==0) {
            v.emplace_back( make_pair(i,0));
            while(b%i == 0) {
                b /= i;
                v[v.size()-1].second++;
            }
        }
    }
    if(b > 1) {
        v.emplace_back(make_pair(b,1));
    }
    for(auto j: v) {
        unsigned long long temp = 0;
        for(unsigned long long i = j.first; i <= n; i *= j.first) {
            temp += n/i;
            if(1 > (n/i)/j.first) {
                break;
            }
        }
        ans = min(ans, temp/j.second);
    }
    cout << ans << '\n';
    return 0; 
}