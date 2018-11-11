#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &i: v)
		cin >> i;
	for(int i = n-2; i>=0; i--){
	 	if(v[i]>=v[i+1])
			n--;
	}
	cout << n << '\n';
	return 0;
}