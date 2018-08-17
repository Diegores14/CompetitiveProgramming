#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int l, d, c1, c2;
	cin >> l >> d >> c1 >> c2;
	cout << l*c1 + c2*(l/d) << '\n';
	return 0;
}