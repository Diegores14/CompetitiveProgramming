#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;       
	double res=0,a;
	int cont = 0;
	while(getline(cin,s)){cin >> a;cin.ignore(); res+=a; cont++;}
	cout << setprecision(1) << fixed << res/cont << '\n'; 
	return 0;
}
