#include <bits/stdc++.h>
using namespace std;

class OneHandSort {
    public:
    vector<int> sortShelf(vector<int> target) {
        int n = target.size();
        int v[n], ans[n+1];
        vector<int> answer;
        ans[n] = -1;
        int vacio = n;
        for(int i=0; i<n; i++) {
            v[target[i]] = i;
            ans[i] = target[i];
        }
        for(int i=0; i<n; i++) {
            if(i == vacio) {
                answer.push_back(v[i]);
                swap(ans[i], ans[v[i]]);
                vacio = v[i];
                v[i] = i;
            }
            if(v[i] != i) {
                v[ans[i]] = vacio;
                answer.push_back(i);
                swap(ans[vacio], ans[i]);
                vacio = i;
                answer.push_back(v[i]);
                swap(ans[vacio], ans[v[i]]);
                vacio = v[i];
                v[i] = i;
            }
        }
        return answer;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    OneHandSort i;
    auto ans = i.sortShelf({1, 2, 3, 0});
    for(int i: ans) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}