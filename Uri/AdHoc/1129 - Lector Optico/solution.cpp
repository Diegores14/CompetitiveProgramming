#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char q;
 	int v[5], x;
	while(cin>>x, x){
		while(x--){
			q = '*';
			for(int i=0; i<5; i++)cin >> v[i];
			for(int i=0; i<5; i++){
				if('A' <= q && q <= 'E' && v[i] <=127){q = '*'; break;}
				if(v[i] <= 127)q = 'A'+i;
			}
			cout << q << '\n';
		}
	}
	return 0;
}