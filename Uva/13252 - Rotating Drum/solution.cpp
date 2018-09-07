#include <bits/stdc++.h>
using namespace std;

int  potencia(int a, int b){
        if(b==1) return a;
        else{
 	 	int aux=potencia(a, b>>1);
 	 	return aux*aux*((b&1)? a : 1);
 	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;             
	while(cin >> a >> b){            
	 	if(a==1){for(int i=0; i<b; i++)cout << "A"; cout << '\n';}
		else{
			unordered_set<string> us;
			string s, s1;
			for(int i=0; i<b; i++){s.push_back((char)('A'+a-1));s1.push_back('A');}
			string s2 = s+s1, ans;
			for(int i=1; i<(int)s2.size()-(b); i++){us.insert(s2.substr(i, b));}
			//for(auto to : us) cout << to << ' ';
			ans = s1;
			us.insert(s1);
			int m = potencia(a,b);
			for(int i = 1; (int)us.size()<m; i++){
				ans.push_back('A');
				for(int j=0; j<26; j++){
					ans[ans.size()-1]=('A'+j);
				 	if(us.count(ans.substr(i,b))==0){us.insert(ans.substr(i,b));break;}
				}
			}
			cout << ans << '\n';

		}				
	}
 	return 0;
}