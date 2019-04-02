#include <bits/stdc++.h>
using namespace std;

long long combinatoria(int n) {
    if(n<=1) {
        return 0;
    }
    return (1LL*(n-1)*n)/2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int temp = n%m;
    cout << combinatoria((n/m)+1)*temp + combinatoria((n/m))*(m-temp) <<
            " " << combinatoria(n-m+1) << '\n';
    return 0;
}