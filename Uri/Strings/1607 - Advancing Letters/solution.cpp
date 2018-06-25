#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, res;
	string s1, s2;
	cin >> n;
	while(n--){
		res=0;
		cin >> s1 >> s2;
		for(int i=0; i<(int)s1.size(); i++){
	         	if('A'<=s2[i] && s2[i]<='Z')s2[i]+=32;
			if('A'<=s1[i] && s1[i]<='Z')s1[i]+=32;
			if(s2[i]-s1[i]<0){res+= 26-(s1[i]-s2[i]);}
			else res+=s2[i]-s1[i];
		}
		cout << res << '\n';
	}
	return 0;
}