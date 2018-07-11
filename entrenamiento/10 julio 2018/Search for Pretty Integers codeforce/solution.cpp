#include <bits/stdc++.h>
using namespace std;

int main(){
        ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, aux;
	cin >> a >> b;
	set<int> s;
	vector<int> v1(a),v2(b);
	for(int i=0; i<a; i++){cin >> aux; v1[i]=aux; s.insert(aux);}
	for(int i=0; i<b; i++)cin >> v2[i];
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int to : v2)
		if(s.count(to)){cout << to << '\n'; return 0;}
	if(v1[0]>v2[0]) swap(v1[0], v2[0]);
 	cout << v1[0] << v2[0] << '\n';
	return 0;
}