#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n, k;
	string s1,s2;
	cin >> n;
	while(n--){
		cin >> k;
		cin >> s1;
		bool res=true;
		while(--k){
		 	cin >> s2;
			if(s2!=s1)res=false;
		}
		cout << ((res)? s1 : "ingles") << '\n';
	}
	return 0;
}