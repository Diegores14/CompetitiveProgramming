#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	int sum=0;
	int cont=0;
	cin >> s;
	for(int i=0; i<(int)s.size(); i++){
		if(i<(int)s.size()-1 && s[i]=='1' && s[i+1]=='0'){
		 	sum+=10;
		 	i++;		 	
		}else sum+=s[i]-'0';
		cont++;
	}
	cout << fixed << setprecision(2) << (double)sum/cont <<'\n';
	return 0;
}