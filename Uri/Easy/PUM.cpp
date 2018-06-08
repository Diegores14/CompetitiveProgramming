#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=1; j<=3; j++)cout << i*4+j << ' ';
		cout << "PUM\n";	
	}
	return 0;
}