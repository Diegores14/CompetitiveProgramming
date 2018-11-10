#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l=0, aux;
	cin >> n;     
	vector<int> v(n+5, 0);
	for(int i=1; i<=n; i++){
		cin >> aux;
		v[aux] = i;
	}
	for(int i=0; i<n; i++){
	 	cin >> aux;
		int r = v[aux];
		if(r-l>0){
			cout << r-l;
			l = r;
		}
		else
			cout << 0;
		cout << ((i+1==n)? '\n' : ' ');
	}
	return 0;
}