#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, temp;
    cin >> n;
    int cont1 = 0, cont2 = 0;
    for (int i=0; i<n; i++) {
        cin >> temp;
        if (temp == 5)
            cont1++;
        else
            cont2++;
    }
    if(cont2 == 0)
        cout << "-1\n";
    else {
        int ans = 0;
        temp = 0;
        for (int i=1; i<=cont1; i++){
            temp = temp * 10 + 5;
            temp %= 9;
            if(temp == 0){
                ans = i;
            }
        }
        if ( ans == 0 ) {
            cout << "0\n";
        } else {
            for(int i=0; i<ans; i++) {
                cout << "5";
            }
            for(int i=0; i<cont2; i++){
                cout << "0";
            }
            cout << '\n';
        }
    }
    return 0;
}