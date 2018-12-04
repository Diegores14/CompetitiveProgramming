#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long  n, temp;
    while(cin >> n, n){
        priority_queue<int, vector<int>, greater<int>> q;
        long long ans = 0;
        for(int i=0; i<n; i++){
            cin >> temp;
            q.push(temp);
        }
        while(q.size() > 1){
            temp = q.top();
            q.pop();
            temp += q.top();
            q.pop();
            ans += temp;
            q.push(temp);
        }
        cout << ans << '\n';
    }
    return 0;
}