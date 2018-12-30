#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> v1(n), v2(n);
    for(auto &i: v1){
        cin >> i.first >> i.second;
    }
    for(auto &i: v2){
        cin >> i.first >> i.second;
    }
    map<pair<long long, long long>, long long> m;
    for(auto i: v1){
        for(auto j: v2){
            m[make_pair(i.first+j.first, i.second + j.second)]++;
        }
    }
    for(auto i: m){
        if(i.second == n){
            cout << i.first.first << ' ' <<  i.first.second << '\n';
            break;
        }
    }
    return 0;
}