#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N;
 	string s1,s2,aux;
	cin >> N;
	while(N--){
		cin >> s1 >> s2;
		aux = " ";
		int n = min(s1.size(),s2.size());
		for(int i=0; i<n;i++) cout << s1[i] << s2[i];
		if(s1.size()<s2.size())aux = s2;
		if(s1.size()>s2.size())aux = s1;
		for(int i=n; i<(int)aux.size(); i++)cout << aux[i];
		cout << '\n';
	}
	return 0;
}