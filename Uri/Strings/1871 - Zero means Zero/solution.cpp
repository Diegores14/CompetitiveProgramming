#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long a, b,aux;
	while(cin >> a >> b, a || b){
	 	aux = a+b;
		string s = to_string(aux);
		for(int i=0; i<s.size(); i++)if(s[i]!='0')cout << s[i];
		cout << '\n';
	}
	return 0;
}