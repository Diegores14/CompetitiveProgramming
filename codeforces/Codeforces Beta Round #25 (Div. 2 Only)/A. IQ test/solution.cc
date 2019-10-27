#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp; 
    cin >> n;
    int countEven = 0, countOdd = 0, lastEven = 0, lastOdd = 0;
    for( int i = 0; i < n; i++ ) {
        cin >> temp;
        if( temp&1 ) {
            countOdd++;
            lastOdd = i;
        } else { 
            countEven++;
            lastEven = i;
        }
    }
    if( countEven == 1 ) {
        cout << lastEven+1 << '\n';
    } else {
        cout << lastOdd+1 << '\n';
    }
    return 0;
}