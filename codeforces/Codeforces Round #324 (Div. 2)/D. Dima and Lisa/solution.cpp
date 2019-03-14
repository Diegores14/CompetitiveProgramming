#include <bits/stdc++.h>
using namespace std;

bool isprime( int n ) {
    if(n < 2)
        return false;
    for(long long i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; 
    cin >> n;
    int aux = n;
    while(!isprime(n) || aux - n == 1) {
        n--;
    }
    vector<int> ans;
    ans.push_back(n);
    if( n == aux) {
        cout << 1 << '\n' << n << '\n';
        return 0;
    }
    if( isprime(aux - n) ) {
        cout << 2 << '\n' << n << ' ' << aux - n << '\n';
        return 0;
    }
    cout << 3 << '\n' << n << ' ';
    for(int i = 2; i < aux - n; i++) {
        if(isprime(i) && isprime(aux-n-i)) {
            cout << i << ' ' << aux-n-i << '\n';
            return 0;
        }
    }
    return 0;
}