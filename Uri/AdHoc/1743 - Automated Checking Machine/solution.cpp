#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int v1[5], v2[5];
	bool r=true;
	for(int i=0; i<5; i++)cin >> v1[i];
	for(int i=0; i<5; i++)cin >> v2[i];
	for(int i=0; i<5; i++)if(!(v1[i]^v2[i])){r=false; break;}
	cout << ((r)?  "Y\n" : "N\n");
	return 0;
}