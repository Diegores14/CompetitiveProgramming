#include <bits/stdc++.h>
using namespace std;

unsigned long long factorial(int n,int  k){
	if(n-k<=0)return n;
	return n*factorial(n-k,k);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	string s;
	string::size_type aux;
	cin >> n;
	while(n--){
		cin >> s;
		int a=stoi(s,&aux,10);
		int b=s.substr(aux).size();
		cout << factorial(a, b) << '\n';
	}
	return 0;
}