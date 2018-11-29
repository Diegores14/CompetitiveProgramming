#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    vector<string> v({"You chickened out.\n", "You win.\n", "You lose.\n"});
    while(cin >> n, n != -1){
        cout << "Round " << n << '\n';
        string s1, s2;
        int ans = 1;
        cin >> s1 >> s2;
        map<char, int> m, aux, strike;
        for(char &i: s1){
            m[i++]++;
        }
        for(char &i: s2){
            if(m.count(i))
                aux[i]++;
            else
                strike[i]++;
            
            if(ans == 1 && strike.size() == 7){
                ans = 3;
                break;
            }
            if(aux.size() == m.size()){
                ans =2;
                break;
            }
        }
        cout << v[ans-1];
    }
    return 0;
}