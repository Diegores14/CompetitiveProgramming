#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n,q,aux,j=1, a, b, c;
	while(cin >> n >> q, n || q){
	 	vector<int> v(n);
		for(int i=0;i<n;i++)cin >> v[i];
		sort(v.begin(),v.end());
		cout << "CASE# " << j++ << ":\n";
		while(q--){
			cin >> aux;
			a=-1; b=n;
			while(abs(b-a)!=1){
			 	c=(a+b)/2;
				if(v[c]>=aux)
					b=c;
				else
					a=c;
			}
			if(b!=n && v[b]==aux)cout << aux <<  " found at " << b+1 << '\n';
			else cout << aux << " not found\n";
		}
	}
 	return 0;
}