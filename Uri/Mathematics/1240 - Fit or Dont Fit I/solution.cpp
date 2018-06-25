#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	string s1, s2;
	bool res;
	cin >> n;
	while(n--){
		res=true;
		cin >> s1 >> s2;
		if(s1.size()>=s2.size()){
		 	for(int i=1; i<=(int)s2.size(); i++)
				if(s1[s1.size()-i]!=s2[s2.size()-i])res=false;
		}else res=false;
		cout << ((res)? "encaixa\n" : "nao encaixa\n");
	}
 	return 0;
}