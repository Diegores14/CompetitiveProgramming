#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b;   
	while(cin >> a >> b, a || b){
	 	vector<int> v(b);
	 	set<int> s;
	 	for(int i=0; i<b; i++)cin >> v[i];
	 	for(int i=0; i<b; i++){
	 	 	for(int j=0; j<b; j++)s.insert(abs(v[i]-v[j]));
	 	 	if((int)s.size()== a+1);
	 	}
	 	cout << (((int)s.size()== a+1)? "Y\n" : "N\n");
	}
 	return 0;
}