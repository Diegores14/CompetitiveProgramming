#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, aux, mmax=0;
	map<int,int> m;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		cin >> aux;
		m[aux]++;
		mmax = max(mmax, m[aux]/k + (m[aux]%k? 1 : 0));
	}
	cout << mmax*m.size()*k - n << '\n';
	return 0;
}