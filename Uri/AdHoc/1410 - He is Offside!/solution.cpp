#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b;   
	while(cin >> a >> b, a || b){		
	 	vector<int> v1(a), v2(b);
	 	for(int i=0; i<a; i++)cin >> v1[i];
		for(int i=0; i<b; i++)cin >> v2[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		if(v1[0]>=v2[1]) cout << "N\n";
		else cout << "Y\n";
	}
 	return 0;
}