#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	for(int i=0; i<10; i++){
	 	cin >> x;
		cout << "X[" << i << "] = " << ((x<=0)? 1 : x) << '\n';
	}
	return 0;
}