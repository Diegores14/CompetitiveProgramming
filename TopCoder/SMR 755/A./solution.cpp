#include <bits/stdc++.h>
using namespace std;

class OneHandScheduling {
    public:
    string checkSchedule(vector<int> tstart, vector<int> tend) {
        vector<pair<int, int> > v(tstart.size());
        for(int i=0; i<v.size(); i++) {
            v[i] = {tstart[i], tend[i]};
        }
        sort(v.begin(), v.end());
        int x =-1, y = -1;
        for(auto i : v) {
            if(i.first <= y) {
                return "impossible";
            }
            x = i.first, y = i.second;
        }
        return "possible";
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    OneHandScheduling it;
//    it.checkSchedule();
    return 0;
}