#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("blist.in","r",stdin);
	freopen("blist.out","w",stdout);
    int n, temp, ans = 0;
    cin >> n;
    vector<pair<int,int>> v(2*n);
    for(int i=0; i<n; i++){
        cin >> v[(i<<1)].first >> v[(i<<1) + 1].first >> temp;
        v[(i<<1)].second = temp;
        v[(i<<1) + 1].second = -temp;
    }
    sort(v.begin(), v.end());
    temp = 0;
    for(pair<int,int> i: v){
        temp += i.second;
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}
