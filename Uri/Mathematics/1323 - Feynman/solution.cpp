#include <bits/stdc++.h>
using namespace std;

vector<int> v(101,0);

int Feynman(int n){
	if(v[n]!=0)return v[n];
	return v[n]=(n*n)+Feynman(n-1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int x;
	v[1]=1;
	while(cin >> x, x){
	 	cout << Feynman(x) << '\n';
	}
	return 0;
}