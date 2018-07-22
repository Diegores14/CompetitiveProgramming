#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int b, n, a, d, va;
	bool answer;
	while(cin >> b >> n, n || b){
	 	vector<int> v(b);
	 	answer=true;
	 	for(int i=0; i<b; i++)cin >> v[i];
		for(int i=0; i<n; i++){cin >> a >> d >> va;v[a-1]-=va; v[d-1]+=va;}
		for(int i=0; i<b; i++)if(v[i]<0)answer=false;
		cout << ((answer)? "S\n": "N\n");
	}
 	return 0;
}