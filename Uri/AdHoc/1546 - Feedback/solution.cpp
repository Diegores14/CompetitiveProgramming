#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	vector<string> v(4);
	v[0]="Rolien"; v[1]="Naej"; v[2]="Elehcim"; v[3]="Odranoel";
	int N, k, i;
	cin >> N;
	while(N--){
	 	cin >> k;
		while(k--){
			cin >> i; 
			cout << v[--i] << '\n';
		}
		
	}
	return 0;
}