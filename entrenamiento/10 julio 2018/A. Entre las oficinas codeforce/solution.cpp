#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	int cont=0;
	string s;
	cin >> n;
	cin >> s;
	for(int i=0; i<n-1;i++)if(s[i]!=s[i+1])cont += (s[i+1]=='F')? 1 : -1;
	cout << ((cont==1)? "YES\n" : "NO\n");
 	return 0;
}