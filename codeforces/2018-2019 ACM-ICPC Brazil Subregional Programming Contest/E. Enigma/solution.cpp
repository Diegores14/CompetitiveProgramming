#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s1, s2;
	int ans=0;
	cin >> s1 >> s2;
	bool aux;
	for(int i=0; i+s2.size() <= s1.size(); i++){
		aux=true;
	 	for(int j=0; j<(int)s2.size(); j++)
			if(s1[i+j]==s2[j]){
				aux=false; 
				break;
		}
		if(aux)ans++;
	}
	cout << ans << '\n';
	return 0;
}