#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n; 
	string s;
	cin >> t;
	while(t--){
	 	cin >> n;
		map<string, int> m;
		int ans=0;
		while(n--){
			int aux=2;
			cin >> s;
			if(m.count(s))
				ans+=m[s]/2;
			else{
				bool flag = true;
				if(s[0]=='d' || s[0]=='f')flag=false;
				for(int i=1; i<s.size(); i++){
					if(((s[i]=='d' || s[i]=='f') && flag) || ((s[i]=='j' || s[i]=='k') && !flag)){
					 	aux+=2;
						flag=!flag;
					}else{
						aux+=4;
					}
				}
				m[s]=aux;
				ans+=aux;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}