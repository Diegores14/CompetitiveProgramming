#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int sum = 0;
    int i=1;
    vector<int> v;
    while(sum+i <= n) {
        sum += i;
        v.emplace_back(i);
        i++;
    }
    if(sum != n) {
        v[v.size()-1] += n-sum;
    }
    cout << v.size() << '\n';
    for(int i: v) {
        cout << i << ' ';
    }
    return 0;
}