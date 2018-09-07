#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s1;
	while(cin >> s1){
		int j=0;
	 	for(int i=1; i<=11; i++)if(i%4==0)cout << '.'; else cout << s1[j++];
	 	cout << '-';
	 	j=0;
	 	for(int i=0; i<9; i++) j+=(s1[i]-'0')*(i+1);
	 	if(j%11==10)cout << "0";
	 	else cout << j%11;
	 	j=0;
	 	for(int i=0; i<9; i++) j+=(s1[i]-'0')*(9-i);
	 	if(j%11==10)cout << "0\n";
	 	else cout << j%11 << '\n';
	}
	return 0;
}