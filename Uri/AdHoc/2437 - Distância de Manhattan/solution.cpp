#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << abs(a-c)+abs(b-d) << '\n';
	return 0;
}