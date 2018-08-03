#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m, a, b;
	set<int> s;
	cin >> n >> m;
	while(n--){
		cin >> a >> b;
		for(int i=a; i<=b; i++)s.insert(i);
				
	}
	int k=0;
	cout << m-s.size() << '\n';
	for(int i=1; i<=m; i++) if(s.count(i)==0){if(k) cout << ' '; else k++; cout << i;}
	cout << '\n';
 	return 0;
}