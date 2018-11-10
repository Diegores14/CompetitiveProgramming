#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	bool salto=false;
	int mmax=0;
	vector<string> v;
	while(getline(cin,s)){
		v.emplace_back(s);
		mmax = max(mmax, (int)s.size());
	}
	for(int i=0; i<mmax+2; i++){
	 	cout << '*';
	}
	cout << '\n';
	for(int i=0; i<(int)v.size(); i++){
	 	cout << '*';
		if((mmax-v[i].size())&1){
			int top = (mmax-v[i].size())>>1;
			for(int j=0; j<top; j++)cout << ' ';
		 	if(salto)cout << ' ' << v[i];
			else cout << v[i] << ' ';
			for(int j=0; j<top; j++)cout << ' ';
			salto = !salto;
		}else{
			int top = (mmax-v[i].size())>>1;
			for(int j=0; j<top; j++)cout << ' ';
			cout << v[i];
			for(int j=0; j<top; j++)cout << ' ';
		}
		cout << "*\n";
	}
	for(int i=0; i<mmax+2; i++){
	 	cout << '*';
	}
	cout << '\n';
	return 0;
}