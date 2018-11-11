#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, b, h, w;
	while(cin >> n >> b >> h >> w){
	 	long long mmin = 1000000000000;
		int p, aux;
		while(h--){
		        cin >> p;
			for(int i=0; i<w; i++){
			 	cin >> aux;
				if(aux>=n && n*p <= b){
				 	mmin = min(n*p, mmin);
				}
			}
		}	 
		if(mmin == 1000000000000)
			cout << "stay home\n";
		else
			cout << mmin << '\n';
	}
	return 0;
}