#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, k=0;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);        
	cout << setprecision(4) << fixed;
	while(n--){
		if(k++)cout << '\n';
		map<string,int> m;
		int cont=0;
		while(getline(cin,s) && s!=""){
			cont++;
			if(m.find(s)==m.end())m[s]=1;
			else m[s]++;
		}
		for(map<string,int>::iterator it=m.begin(); it!=m.end(); ++it)
			cout << it->first << ' ' << ((double)(it->second)/cont)*100 << '\n';
	}
 	return 0;
}