#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	unsigned long long n, m, k, l;
	cin >> n >> m >> k >> l;
	n = n-k;
	if(n<m)
		cout << "-1\n";
	else{
	 	if(n-ceil(double(l)/m)<0)
			cout << "-1\n";
		else{
		 	cout << ceil(double(l)/m) << '\n';
		}
	}
	return 0;
}