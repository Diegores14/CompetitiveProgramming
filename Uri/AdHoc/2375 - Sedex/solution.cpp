#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if(n<=a && n<=b && n<=c) cout << "S\n";
	else cout << "N\n";
	return 0;
}