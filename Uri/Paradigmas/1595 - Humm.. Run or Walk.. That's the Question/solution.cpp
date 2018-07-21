#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, s, c, r;
	double answer;
	cin >> t;
	cout << fixed << setprecision(2);
	while(t--){
		answer=0;
		cin >> s >> c >> r;
		vector<int> v(s);
		for(int i=0; i<s; i++)cin >> v[i];
		sort(v.begin(),v.end());
		for(int j=0; j<c; j++)v[j]+=r;
		for(int i=0; i<s; i++)answer+= 1.0/v[i];
		cout << answer << '\n';
	}
	return 0;
}