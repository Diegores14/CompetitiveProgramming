#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n;
    cin >> n;
    vector <int> v(n);
    for(int &i: v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        cout << v[i] << ((i==n-1)? '\n' : ' ');
    }
    return 0;
}