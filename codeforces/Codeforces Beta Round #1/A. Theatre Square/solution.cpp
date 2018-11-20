#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long n, m, a;
	cin >> n >> m >> a;
	cout << (n/a + ((n%a)? 1: 0)) * (m/a + ((m%a)? 1: 0)) << '\n';
	return 0;
}