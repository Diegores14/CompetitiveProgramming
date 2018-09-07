#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int n, a, b;
	cin >> n;
	while(n--){
	 	cin >> a >> b;
	 	int i = (a-2)/3 + (((a-2)%3)? 1 : 0),
	 	    j = (b-2)/3 + (((b-2)%3)? 1 : 0);
	 	cout << i*j << '\n';
	}
 	return 0;
}