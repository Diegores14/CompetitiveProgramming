#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int temp = 0;
    int x, y;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=5; j++) {
            cin >> temp;
            if(temp){
                y = i;
                x = j;
            }
        }
    }
    cout << abs(x-3) + abs(y-3) << '\n';
    return 0;
}