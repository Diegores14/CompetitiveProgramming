#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, e, n;
	cin >> t;
	for(int k=1; k<=t; k++){
		int ans=0;
	 	cin >> e >> n;
		vector<int> s(n);
		for(int i=0; i<n; i++){
		 	cin >> s[i];
		}
		sort(s.begin(), s.end());
		for(int i=0; i<n; i++){
			if(e-s[i]<=0 && ans!=0){
			 	e+=s[n-1];
				n--;
				ans--;
			}
			if(e-s[i]<=0)
				break;
			else{
				ans++;
				e-=s[i];
			}
		}
		cout << "Case #" << k << ": " << ans << '\n';
	}
	return 0;
}