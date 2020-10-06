#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin >> n;
    long long sum = 0;
    for( int i = 1, temp; i < n; i++ ) {
        cin >> temp;
        sum += temp;
    }
    cout << n*(n+1)/2 - sum << '\n';
    return 0;
}
