#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	long long sum=0;
	if(x>y)swap(x,y);
	for(int i=x; i<=y;i++) if(i%13)sum+=i;
	cout << sum << '\n';
	return 0;
}