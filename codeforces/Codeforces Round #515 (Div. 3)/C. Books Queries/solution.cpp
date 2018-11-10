#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, l=0, r=0;
	char c;
	int aux;
	cin >> t;
	vector<int> v(200005, 0);
	cin >> c >> aux;
	while(--t){
	 	cin >> c >> aux;
		if(c=='L'){
			l--;
			v[aux]=l;
		}
		if(c=='R'){
		 	r++;
			v[aux]=r;
		}
		if(c=='?'){
			cout << min(v[aux]-l, r-v[aux]) << '\n';
		}
	}
	return 0;
}