#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int s;
    cin >> s;
    if ( s <= 90 ) {
        cout << "0 No punishment\n";
    } else {
        if( 90 < s && s <= 110 ) {
            cout << ( s - 90 ) * 300 << ' ' << "Warning\n";
        } else {
            cout << ( s - 90 ) * 500 << ' ' << "License removed\n";
        }
    }
    return 0;
}