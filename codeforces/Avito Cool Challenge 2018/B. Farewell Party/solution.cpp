#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long  n;
    map<long long, int> m;
    cin >> n;
    vector<long long> temp(n);
    for(int i=0; i<n; i++){
        cin >> temp[i];
        m[temp[i]]++;
    }
    for(auto i: m){
        if(n - i.second != i.first){
            cout << "Impossible\n";
            return 0;
        }
    }
    int k=0;
    map<long long, int> m1;
    cout << "Possible\n";
    for(int i = 0; i<n; i++){
        if(m1.count(temp[i]) == 0){
            m1[temp[i]] = m1.size()+1;
        }
        cout << m1[temp[i]] << ((i==n-1)? '\n': ' '); 
    }
    return 0;
}