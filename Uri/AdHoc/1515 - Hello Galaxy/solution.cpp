#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){		
		string s, ans;
		int a, b, mi=10000000, aux=0;
	 	for(int i=0; i<n; i++){cin >> s >> a >> b; if(mi>a-b || (mi==a-b && a>aux)){mi=a-b; ans=s; aux=b;}}
	 	cout << ans << '\n';
	}
 	return 0;
}