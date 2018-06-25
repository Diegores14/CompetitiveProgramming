#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie();
	string n;
	while(cin >> n, n!="-1"){   
		if(n.size()>=2 && n[1]=='x'){
			cout << dec << stoi(n,nullptr,16) << '\n';
		}
		else{
			ostringstream a;
			a << hex << stoi(n);
			string aux=a.str();
			for(int i=0; i<(int)aux.size(); i++)if('a'<=aux[i] && aux[i]<='z')aux[i]-=32;
			cout << "0x" << aux << '\n';
		}
	}
	return 0;
}