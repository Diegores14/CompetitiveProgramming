#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	int t,a,b;
	char c;
	cin >> t;
	while(t--){
	 	cin >> a >> c >> b;
		if(a==b){cout << a*b << '\n'; continue;}
		if('A'<=c && c<='Z'){cout << b-a << '\n'; continue;}
		if('a'<=c && c<='z'){cout << b+a << '\n';}
	} 	
	return 0;
}