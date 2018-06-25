#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	unsigned long long a,b;
	while(cin >> a >> b){
	 	cout << ((b*(b+1))-(a*(a+1)))/2+a << '\n';
	}
	return 0;
}