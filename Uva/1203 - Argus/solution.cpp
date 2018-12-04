#include <bits/stdc++.h>
using namespace std;

struct node{
    int Q_num, period;
    node(){}
    node(int _num, int _period){
        Q_num = _num;
        period = _period;
    }
    bool operator <( const node &other)const{
        if(period == other.period)
            return Q_num > other.Q_num;
        return period > other.period;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    vector<node> v;
    int num, period, k;
    while(cin >> s, s != "#"){
        cin >> num >> period;
        v.emplace_back(node(num, period));
    }
    cin >> k;
    priority_queue<node> ans;
    for(int i = 0; i<v.size(); i++){
        for(int j = 1; j <= k; j++){
            ans.push(node(v[i].Q_num, v[i].period * j));
        }
    }
    for(int i = 0; i < k; i++){
        cout << ans.top().Q_num << '\n';
        ans.pop();
    }
    return 0;
}