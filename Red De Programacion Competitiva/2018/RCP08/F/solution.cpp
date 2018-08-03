#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	unsigned int w, n, a, b, sum=0;
	cin >> w >> n;
	for(int i=0; i<n; i++){cin >> a >> b;  sum+= (a*b);}
	cout << sum/w << '\n';
	return 0;
}