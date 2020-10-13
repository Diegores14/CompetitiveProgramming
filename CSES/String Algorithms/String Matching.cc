#include <bits/stdc++.h>
using namespace std;
long long dp[6000];
long long mod = 1e9+7;

long long sub( long long a, long long b, long long mod ) {
    long long ans = a-b;
    if(ans < 0) return ans+mod;
    return ans;
}

long long sum( long long a, long long b, long long mod ) {
    long long ans = a+b;
    if(ans >= mod) return ans-mod;
    return ans;
}

struct rollingHash {
    int p, mod;
    vector< int > h, po, invPo;
    rollingHash( int p, int mod, const string &s ): p(p), mod(mod), h(s.size()+1) {
        long long po = 1;
        for( int i = 0; i < s.size(); i++ ) {
            h[i+1] = sum( h[i], (1LL*po*(s[i]-'a'+1))%mod, mod );
            po = (1LL*po*p)%mod;
        }
    }
    int getSubHash( int l, int r ) {
        return sub(h[r+1], h[l], mod);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s, k;
    cin >> s >> k;
    rollingHash h1(31, mod, s);
    rollingHash h2(41, mod+2, s);
    rollingHash h3(31, mod, k);
    rollingHash h4(41, mod+2, k);
    int ans = 0;
    long long po1 = 1, po2 = 1;
    for( int i = 0; i+k.size() <= s.size(); i++ ) {
        if( h1.getSubHash(i,i+k.size()-1) == (h3.h[k.size()]*po1)%mod && 
            h2.getSubHash(i,i+k.size()-1) == (h4.h[k.size()]*po2)%(mod+2) ) {
                ans++;
            }
        po1 = (po1*31)%mod;
        po2 = (po2*41)%(mod+2);
    }
    cout << ans << '\n';
    return 0;
}