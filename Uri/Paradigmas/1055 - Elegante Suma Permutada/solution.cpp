#include <bits/stdc++.h>
	using namespace std;


	int main(){
		ios_base::sync_with_stdio(false);cin.tie(NULL);
		int t, n, aux1, aux2, res, b;
		cin >> t;
		for(int k=1; k<=t; k++){
			cin >> n;
			vector<int> v(n);
			list<int> l;
			for(int i=0; i<n; i++) cin >> v[i];
			sort(v.begin(),v.end());
			l.push_back(v[n-1]);
			int i=0, j=n-2;
			while(i<=j){
				aux1=max(abs(l.back()-v[i]),abs(l.front()-v[i]));
				aux2=max(abs(l.back()-v[j]),abs(l.front()-v[j]));
				if(aux1>aux2){
					if(aux1 > abs(l.back()-v[i])){ l.push_front(v[i]);}
					else{ l.push_back(v[i]);}
					i++;
				}else{
					if(aux2 > abs(l.back()-v[j])){ l.push_front(v[j]);}
					else{ l.push_back(v[j]);}
					j--;
				}
			}
			res=0;
			b=l.front();
			for(int to : l){res+=abs(b-to); b=to;}
			cout << "Case " << k << ": " << res <<'\n';	
		}
		return 0;
	}