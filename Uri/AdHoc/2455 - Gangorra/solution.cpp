#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p1, c1, p2, c2;
	cin >> p1 >> c1 >> p2 >> c2;
	if(p1*c1==p2*c2) cout << "0\n";
	if(p1*c1<p2*c2) cout << "1\n";
	if(p1*c1>p2*c2) cout << "-1\n";
	return 0;
}