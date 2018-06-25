#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	cout << setprecision(1) << fixed << n/log(n) << ' ' << 1.25506*(n/log(n)) << '\n';
 	return 0;
}