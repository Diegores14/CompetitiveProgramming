#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a=500;
	cout << a << '\n';
	for(int i=0; i<10000 && a; i++){
		for(int j=501; j<10000 && a; j++, a--){cout <<  i << ' ' << j << '\n';}
	}
 	return 0;
}