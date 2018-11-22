#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	long long ans = 0, total = 0;
	cin >> n >> m;
	vector<int> v(n);
	for(int &i: v){
		cin >> i;
		total += i;
	}	
	sort(v.begin(), v.end(), greater<int>());
	int altura = v[0];
	for(int i=1; i<n; i++){
		if(altura <= 0){
			ans++;
			altura--;
			continue;
		}
	 	if(altura <=  v[i]){
	 		ans++;
	 		altura--;
		}else{
			ans += altura - v[i];
			altura = v[i];
		}
	}
	if(altura > 0){
		ans += altura;
	}else
		ans++;
	cout << total - ans << '\n';
	return 0;
}