#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, total = 0, ans = 0;
	cin >> n;
	vector<int> v(n);
	set<int> s;
	s.insert(0);
	for(int i=0; i<n; i++){
	 	cin >> v[i];
	 	total += v[i];
	 	s.insert(total);
	}
	if(total&1)
		cout << "N\n";
	else{
		total >>= 1;
		long long aux = 0; 
		for(int i=0; i<n && aux < total; i++){
			ans += s.count(aux+total);
			aux += v[i];
		}
		if(ans >= 2)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}