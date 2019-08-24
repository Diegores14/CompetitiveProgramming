#include <bits/stdc++.h>
using namespace std;
const int tam = 1e5;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << tam << '\n';
    for( int i = 0; i < tam; i++ ) {
        cout << 1 << ( i+1 == tam? '\n' : ' ') ;
    }
    return 0;
}