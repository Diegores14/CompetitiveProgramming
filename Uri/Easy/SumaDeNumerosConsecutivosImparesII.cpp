#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N, i, j, res=0;
	cin >> N;
	while(N--){
		res = 0;
		cin >> i >> j;
		if(i>j)swap(i,j);
		for ( int k = i+1; k<j; k++)if(k%2)res+=k;
		cout << res << '\n';
	}
	return 0;
}