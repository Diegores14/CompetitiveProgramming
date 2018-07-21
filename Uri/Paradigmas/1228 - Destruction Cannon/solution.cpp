#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, int> m;

int knapsack(vector<int> & d,vector<int> & w, int k, int n){
 	if(n==0 || k==0)return 0;

 	if(m.count(pair<int,int>(k,n-1)))return m[pair<int,int>(k,n-1)];
	if(k>=w[n-1])m[pair<int,int>(k,n-1)] = max(d[n-1] + knapsack(d, w, k-w[n-1], n-1), knapsack(d, w, k, n-1));
	else m[pair<int,int>(k,n-1)] = knapsack(d, w, k, n-1);
	return m[pair<int,int>(k,n-1)];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n, k, r;
	cin >> t;
	while(t--){
	 	cin >> n;
	 	m.erase(m.begin(),m.end());
	 	vector<int> destructive_power(n);
		vector<int> weight(n);
	 	for(int i=0; i<n; i++)cin >> destructive_power[i] >> weight[i];
	 	cin >> k >> r;
	 	if(r <= knapsack(destructive_power, weight, k, n))cout << "Missao completada com sucesso\n";
	 	else cout << "Falha na missao\n";
	}
 	return 0;
}