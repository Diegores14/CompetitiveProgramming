#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while(t--){
	 	cin >> n;
		string s;
		cin >> s;
		int ans=0, l=0, aux=0;
		bool flag = true;
		for(int i=0; i<n; i++){
		 	if(flag ){
				if(s[i]=='.'){
			 	 	flag=false;
					l=i;
				}
			}else{
			 	if(s[i]=='#'){
			 	 	aux++;
					ans += i+aux-1-l;
					//cout << l << ' ' << i << ' ' << aux << '\n';
					l++;
				}else{
				 	aux = max(aux-1, 0);
				}
			}
		}
		if(aux>0){
			cout << "-1\n";
		}else{
		 	cout << ans << '\n';
		}
	}
	return 0;
}