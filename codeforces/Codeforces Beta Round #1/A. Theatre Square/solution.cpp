#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m, a;
	cin >> n >> m >> a;
	cout << (long long)ceil(n/double(a))*(long long)ceil(m/double(a)) << '\n';
	return 0;
}