#include <bits/stdc++.h>
using namespace std;

long long cantPairs(long long n) {
    return (n*(n-1))/2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    long long a = n/m;
    long long b = n%m;
    cout << cantPairs(a+1)*(b) + cantPairs(a)*(m-b) << ' ' << cantPairs(n-m+1) << '\n'; 
    return 0;
}