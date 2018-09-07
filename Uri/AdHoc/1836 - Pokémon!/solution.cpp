#include <bits/stdc++.h>
using namespace std;

long long answer(int l, int r){
 	long long a, b, c;
 	cin >> a >> b >> c;
 	return (b + a + sqrt(c)/8 + r)*l/50 + 5;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, l;
	string s;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> s >> l;
		cout << "Caso #" << i << ": " << s << " nivel " << l << '\n';
		cout << "HP: " << answer(l, 50) + 5 << '\n';
		cout << "AT: " << answer(l, 0) << '\n';
		cout << "DF: " << answer(l, 0) << '\n';
		cout << "SP: " << answer(l, 0) << '\n';
	}
	return 0;
}