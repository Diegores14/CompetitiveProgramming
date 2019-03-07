#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    return b? GCD(b, a%b) : a;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) {
        cin >> i;
    }
    for(int &i: b) {
        cin >> i;
    }
    long long ans = 0, aux = 0;
    map<pair<int,int>, long long> m;
    for(int i=0; i<n; i++) {
        if(a[i] == 0 && b[i] == 0) {
            aux++;
            continue;
        }
        if(a[i] == 0 && b[i]) {
            continue;
        }
        if(b[i] == 0) {
            auto temp = make_pair(0,0);
            m[temp]++;
            ans = max(m[temp], ans);
            continue;
        }
        int sig = 1; 
        if((a[i]<0) ^ (b[i] < 0)) {
            sig = -1;
        }
        int G = GCD(abs(a[i]), abs(b[i]));
        auto temp = make_pair(sig * abs(b[i]/G), abs(a[i]/G));
        m[temp]++;
        ans = max(m[temp], ans);
    }
    cout << ans+aux << '\n';
    return 0;
}