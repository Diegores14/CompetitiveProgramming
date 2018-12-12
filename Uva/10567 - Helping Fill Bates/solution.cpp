#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int q;
    cin >> s;
    vector<vector<int>> v(52);
    for(int i = 0; i < s.size(); i++){
        if('A' <= s[i] && s[i] <= 'Z')
            v[s[i]-'A'].emplace_back(i);
        else{
            v[s[i]-'a' +  26].emplace_back(i);
        }
    }
    cin >> q;
    while(q--){
        cin >> s;
        int mmin = 10000000, mmax = -1;
        bool ans = true;
        for(char i : s){
            int pos = i - (i>='a'? ('a'-26) : 'A');
            int a = -1, b = v[pos].size();
            while(b-a != 1){
                int mid = (a+b)>>1;
                if(mmax < v[pos][mid])
                    b = mid;
                else
                    a = mid;
            }
            if(b == v[pos].size()){
                ans = false;
                break;
            }
            mmax = max(mmax, v[pos][b]);
            mmin = min(mmin, v[pos][b]);
        }
        if(ans)
            cout << "Matched " << mmin << ' ' << mmax << '\n';
        else
            cout << "Not matched\n";
    }
    return 0;
}