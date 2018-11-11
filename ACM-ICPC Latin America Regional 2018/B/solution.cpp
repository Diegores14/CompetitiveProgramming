#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; 
	cin >> n;
	vector<int> v(n);
	vector<long long> preffix(2*n+1, 0);
	set<long long> s;
	s.insert(0);
	for(int i=0; i<n; i++){
		cin >> v[i];
		preffix[i+1] = v[i] + preffix[i];
		s.insert(preffix[i+1]);
	}
	long long total = preffix[n];
	bool ans = false;
	if((total&1)==0)
		for(int i=0; i < (n-1) && !ans; i++){	
			for(int j=i+1; j <=n && !ans; j++){
				long long aux = preffix[j]-preffix[i];
				long long aux1 = ((total-(aux<<1))>>1) + preffix[j];
				if(aux1>preffix[j] && s.count(aux1)){
					if(s.count(aux1+aux)){
						ans = true;
					}
				}
			}
		}                 
	if(ans)
		cout << "Y\n";
	else
		cout << "N\n";
	return 0;
}