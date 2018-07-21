#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	int n;
	cin >> n >> s;
	int i;
	for( i=0; i<=n-3; i++){
		while(i<=n-3 && s.substr(i,3)=="ogo"){
			i+=3;cout << "***";
			while(i<=n-2 && s.substr(i,2)=="go")i+=2;   
		}
		if(i<n) cout << s[i];
	}               
	for(;i<n;i++)cout << s[i];
	cout << '\n';
 	return 0;
}