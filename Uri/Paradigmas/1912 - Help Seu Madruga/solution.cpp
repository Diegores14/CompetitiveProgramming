#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, sum, mx;
	while(cin >> a >> b, a || b){
	 	vector<int> v(a);
		mx=0; sum=0;
		for(int i=0; i<a; i++){cin >> v[i]; sum+=v[i]; mx= max(mx,v[i]);}
		if(b==sum){cout << ":D\n"; continue;}
		if(b>sum){cout << "-.-\n"; continue;}
		
	}
 	return 0;
}