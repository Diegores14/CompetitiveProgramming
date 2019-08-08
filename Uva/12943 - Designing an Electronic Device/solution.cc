#include <bits/stdc++.h>
using namespace std;
const int tam = 1005;
int n, k;
int cant[8];

struct fraction {
    long long a, b;
    fraction(): a(0), b(1) {}
    fraction(long long a, long long b): a(a), b(b) {
        long long d = gcd(abs(a), abs(b));
        a /= d;
        b /= d;
    }
    long long gcd(long long  a, long long b) {
        return b? gcd(b, a%b) : a;
    }
    fraction operator *(fraction other) const {
        long long temp1 = other.a * a;
        long long temp2 = other.b * b;
        long long d = other.gcd(temp1, temp2);
        other.a = temp1/d;
        other.b = temp2/d;
        return other;
    }
    fraction operator -(fraction other) const {
        long long temp1 = a*other.b - other.a*b;
        long long temp2 = other.b*b;
        long long d = other.gcd(temp1, temp2);
        other.a = temp1/d;
        other.b = temp2/d;
        return other;
    }
    bool operator <(fraction other) const {
        return (long double)a / b < (long double) other.a / other.b;
    }
    bool operator !=(fraction other) const {
        return a != other.a || other.b != b;
    }
};

string print(fraction x) {
    return to_string(x.a) + "/" + to_string(x.b);
}

fraction dp[8][tam];
pair<fraction, int> v[8][16];

fraction solve(int idx, int sum) {
    if(sum < 0) return fraction();
    if(idx == n) return fraction(1,1);
    fraction &ans = dp[idx][sum];
    if( ans != fraction(-1,1) ) return ans;
    ans.a = 0;
    for(int i = cant[idx]-1; i >= 0; i--) {
        ans = max(ans, v[idx][i].first * solve( idx+1, sum - v[idx][i].second ) );
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, cost;
    while(cin >> n >> k) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = fraction(-1,1);
            }
        }
        for(int i = 0; i < n; i++) {
            cin >> cant[i];
        }
        for(int i = 0 ; i < n; i++) {
            for(int j = 0; j < cant[i]; j++) {
                cin >> a >> b >> cost;
                v[i][j] = pair<fraction, int>( fraction(1,1) - fraction(a, b), cost );
            }
        }
        cout << print( fraction(1,1) - solve(0, k) ) << '\n';
    }
    return 0;
}