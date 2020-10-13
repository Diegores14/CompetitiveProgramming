#include <bits/stdc++.h>
using namespace std;
const int tam = 1000001;
long long divs[tam];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fill( divs, divs+tam, 2);
    divs[1] = 1;
    for( int i = 2; i*i < tam; i++ ) {
        for( int j = i*i; j < tam; j += i ) {
            divs[j]++;
            if( j != i*i) divs[j]++;
        }
    }
    int n; 
    cin >> n;
    while( n-- ) {
        int x;
        cin >> x;
        cout << divs[x] << '\n';
    }
    return 0;
}
