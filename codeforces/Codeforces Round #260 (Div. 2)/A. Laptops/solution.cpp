#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, b;
    node() {}
    bool operator <(node other) const
    {
        return a < other.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<node> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i].a >> v[i].b;
    }
    sort(v.begin(), v.end());
    for( int i=1; i<n; i++) {
        if(v[i-1].b > v[i].b) {
            cout << "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
    return 0;
}