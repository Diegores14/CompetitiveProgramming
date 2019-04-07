#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    int n, b, f;
    cin >> t;
    while(t--) {
        cin >> n >> b >> f;
        string temp;
        vector< vector<int> > v(n, vector<int> (5));
        vector< vector<int> > ans(n-b, vector<int> (5));
        for(int i=0; i<n; i++) {
            for(int j=0; j<5; j++) {
                v[i][j] = ((i>>j)&1);
            }
        }
        /*
        cout << "debug\n";
        for(int i=0; i<5; i++){
            for(int j=0; j<n; j++) {
                cout << v[j][i] << ' ';
            }
            cout << '\n';
        }
        */
        for(int i=0; i<5; i++) {
            for(int j=0; j<n; j++) {
                cout << v[j][i];
            }
            cout << '\n';
            cout.flush();
            cin >> temp;
            for(int j=0; j<n-b; j++) {
                ans[j][i] = temp[j]-'0';
            }
        }
        int l=0; 
        int tam = b;
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<5; j++) {
                if(n-b <= l  || v[i][j] != ans[l][j]) {
                    tam--;
                    cout << i << ((tam==0)? '\n' : ' ');
                    flag = false;
                    break;
                }
            }
            if(flag) {
                l++;
            }
        }
        /*
        cout << "debug\n";
        for(int i=0; i<5; i++){
            for(int j=0; j<n-tam; j++) {
                cout << ans[j][i] << ' ';
            }
            cout << '\n';
        }
        */
        int isgood = 0;
        cin >> isgood;
        if(isgood == -1) {
            return 0;
        }
    }
    return 0;
}