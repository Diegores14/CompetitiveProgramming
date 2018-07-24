#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int v[7] = {1, 3, 5, 10, 25, 50, 100}, k, left=-1, right=7;
	cin >> k;
	while(right-left!=1){
	 	if(v[(right+left)/2]>=k)right=(right+left)/2;
	 	else left=(right+left)/2;
	}
	cout << "Top " << v[right] << '\n';
 	return 0;
}