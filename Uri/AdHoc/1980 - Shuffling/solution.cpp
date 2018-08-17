#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	while(cin >> s, s!="0"){
	 	long long ans=1;
	 	for(int i=2; i<=(int)s.size(); i++)ans*=i;
	 	cout << ans << '\n';
	}
	return 0;
}