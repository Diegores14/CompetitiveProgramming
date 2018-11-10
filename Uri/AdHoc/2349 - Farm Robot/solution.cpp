#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, c, s, aux=1, ans = 0;
	cin >> n >> c >> s;
	vector<int> v(c);
	for(int &i: v)
		cin >> i;
	if(aux==s)
		ans++;
	for(int i: v){
	 	aux += i;
		if(aux>n)aux=1;
		if(aux<1)aux=n;
		if(aux==s)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}