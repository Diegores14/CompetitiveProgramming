#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, ans1=0, ans2=0;
	char c;
	cin >> n;
	vector<string> v(n);
	for(int i=0; i<n; i++){
	 	cin >> c >> v[i];
		if(c=='+')ans1++;
		else ans2++;
	}
	sort(v.begin(), v.end());
	for(int i=0; i<n; i++){
	 	cout << v[i] << '\n';
	}
	cout << "Se comportaram: " << ans1 << " | Nao se comportaram: " << ans2 << '\n';
	return 0;
}