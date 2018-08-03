#include <bits/stdc++.h>
using namespace std;

map<int,int> m;

void factor(int n){
 	for(int i=2; i*i<=n; i++){
 	 	if(n%i==0){
 	 	 	while(n%i==0){n/=i; m[i]++;}
 	 	}
 	}
 	if(n>1) m[n]++;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux;
	long long answer;
	cin >> t;
	while(t--){
	 	cin >> n;
	 	answer=1;
	 	m.erase(m.begin(), m.end());
	 	for(int i=0; i<n; i++){cin >> aux; factor(aux);}
	 	for(map<int,int>::iterator it = m.begin(); it!=m.end(); ++it){
	 	 	answer*=(it->second+1);
	 	}
	 	cout << answer << '\n';
	}
	return 0;
}