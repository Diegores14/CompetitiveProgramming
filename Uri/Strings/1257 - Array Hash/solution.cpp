#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, l, res=0;
	string s;
	cin >> n;
	while(n--){
	 	cin >> l;
		res=0;
		for(int i=0; i<l; i++){
			cin >> s;	
		 	for(int j=0; j<(int)s.size(); j++){
		 	 	res+=(s[j]-'A')+i+j;
			}
		}
		cout << res << '\n';
	}
	return 0;
}	