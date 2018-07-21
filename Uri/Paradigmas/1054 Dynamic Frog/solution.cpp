#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, d, n, m, res, pos;
	char s, aux;
	cin >> t;
	for(int i=1; i<=t; i++){
	 	cin >> n >> d;
		res = 0;
		pos = 0;
		vector<pair<char,int>> v(n);
		for(int j=0; j<n; j++){cin >> s >> aux >> m;v[j]=pair<char,int>(s,m);}
		/*while(n--){
			cin >> s >> aux >> m;
			if(s=='B') posafter=m;
			res=max(res,posafter-posbefore);
			posbefore = posafter;
		}*/
		for(int j=0; j<n-1; j++){
			if(v[j].first=='S')
				res=max(res,v[j+1].second-pos);
			else{
			 	res=max(res,v[j].second-pos);
			}
			pos=v[j].second;
		}
		if(n!=0)res = (v[n-1].first=='S')? max(res, d-pos) : max(res, d-v[n-1].second);
		else res=d;
		cout << "Case " << i << ": " << res << '\n';
	}
        return 0;
}	