#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int n;
	cin >> s;
	n = 0;
	for(int i: s){
	 	if(i!='.')
			n = n*10 + i-'0';
	}
	long long i=1;
	while((i*36000)%n){
	 	i++;
	}
	cout << (i*36000)/n << '\n';
	return 0;
}