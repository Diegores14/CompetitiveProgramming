#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	string s, s1("one");
	cin >> n;
	while(n--){
		int aux = 0;
		cin >> s;
		if(s.size()==5){cout << "3\n"; continue;}
		for(int i=0; i<3;i++) aux += (s[i]^s1[i])? 1 : 0;
		//cout << aux<<"d\n";
		if(aux==1 || aux == 0)cout << "1\n";
		else cout << "2\n";
	}
	return 0;
}