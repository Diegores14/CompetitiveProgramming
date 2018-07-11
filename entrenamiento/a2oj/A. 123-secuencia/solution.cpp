#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, aux,mx=0;
	cin >> n;
	vector<int> v(3,0);
	for(int i=0; i<n; i++){cin >> aux; v[aux-1]++;}
	mx=max(v[0],v[1]);
	mx=max(mx,v[2]);
	cout << n-mx <<'\n';
	return 0;
}