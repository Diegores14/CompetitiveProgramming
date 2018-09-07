#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<string> v(3);
	v[0] = "Otavio\n";
	v[1] = "Bruno\n";
	v[2] = "Ian\n";
	vector<pair<double, int>> v1(3);
	for(int i=0; i<3; i++) v1[i].second = i;
	cin >> v1[0].first >> v1[1].first >> v1[2].first;
	sort(v1.begin(), v1.end());
	if(v1[0].first == v1[1].first) cout << "Empate\n";
	else cout << v[v1[0].second];
 	return 0;
}