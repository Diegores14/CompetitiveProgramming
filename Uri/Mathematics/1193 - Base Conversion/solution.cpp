#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	string s, s1;
	for(int i=1; i<=n; i++){
	 	cout << dec << "Case " << i << ":\n";
		cin >> s >> s1;
		if(s1=="bin"){
		 	cout << dec << (int)stoul(s, nullptr, 2) << " dec\n";
			cout << hex << (int)stoul(s, nullptr, 2) << " hex\n";
		}                   
		if(s1=="dec"){
			unsigned long a = stoul(s, nullptr, 10);
		 	cout << hex << a << " hex\n";
			string aux;
			while(a){aux.push_back((char)((a&1)+'0')); a=(a>>1);}
			for(int i=aux.size()-1; i>=0;i--)cout << aux[i];
			cout << " bin\n";
		}
		if(s1=="hex"){
			unsigned long a = stoul(s, nullptr, 16);
		 	cout << dec << a << " dec\n";
			string aux;
			while(a){aux.push_back((a&1)+48); a=(a>>1);}
			for(int i=aux.size()-1; i>=0;i--)cout << aux[i];
			cout << " bin\n";
		}
		cout << '\n';
	}
	return 0;
}