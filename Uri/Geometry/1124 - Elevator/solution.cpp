#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long l, c, r1, r2;
	while(cin >> l >> c >> r1 >> r2, l || c || r1 || r2){
		if(2*max(r1, r2) <= min(l, c)){
			if(r1<r2) swap(r1, r2);
			int aux = min(l, c);
			if(2*r1+2*r2 <= aux){cout << "S\n"; continue;}
			if(r1+sqrt((r1+r2)*(r1+r2)-(aux-r1-r2)*(aux-r1-r2))+r2 <= max(l,c)) cout << "S\n";
			else cout << "N\n";
		}else cout << "N\n";
	}	
 	return 0;
}