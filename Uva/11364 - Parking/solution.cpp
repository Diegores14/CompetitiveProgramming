#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux, mmin=99, mmax=0;
	cin >> t;
	while(t--){
		cin >> n;
		mmax=0;
		mmin=99;
		for(int i=0; i<n; i++){
			cin >> aux;
			mmin = min(mmin, aux);
			mmax = max(mmax, aux);
		}
		cout << (mmax-mmin)*2 << '\n';
	}
	return 0;
}