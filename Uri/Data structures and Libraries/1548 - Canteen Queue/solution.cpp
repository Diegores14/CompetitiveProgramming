#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, n1, cont;
	cin >> n;
	while(n--){
		cont = 0;
		cin >> n1;
		vector<int> v(n1), v1;
		for(int i=0; i<n1; i++)cin >> v[i];
		v1=v;
		sort(v1.begin(), v1.end(), greater<int>());
		for(int i=0; i<n1; i++)if(v[i] == v1[i])cont++;
		cout << cont << '\n';
	}
	return 0;
}