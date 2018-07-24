#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n){
		cout << ((n%6==0)? "Y\n" : "N\n");
	}	
 	return 0;
}