#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<bool> v(100, false);
	int aux,ans=0;
	for(int i=0;i<6; i++){ cin >> aux; v[aux]=true;}
	for(int i=0;i<6; i++){ cin >> aux; if(v[aux])ans++;}
	if(ans<3) cout << "azar\n";
	if(ans==3) cout << "terno\n";
	if(ans==4) cout << "quadra\n";
	if(ans==5) cout << "quina\n";
	if(ans==6) cout << "sena\n";
	return 0;
}