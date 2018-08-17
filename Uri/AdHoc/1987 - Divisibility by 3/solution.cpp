#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	while(cin >> n >> s){
		int sum=0;
	 	for(int i=0; i<n; i++)sum+=s[i]-'0';
	 	cout << sum << ((sum%3==0)? " sim\n" : " nao\n");
	}
 	return 0;
}