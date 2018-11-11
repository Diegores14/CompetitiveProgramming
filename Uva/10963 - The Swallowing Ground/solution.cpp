#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, w, a, b;
	cin >> t;
	for(int i=0; i<t; i++){
	 	if(i)cout << '\n';
		cin >> w;
		cin >> a >> b;
		bool ans = true;
		int aux = a - b;
		while(--w){
			cin >> a >> b;
		 	if(aux != a-b){
		 	 	ans = false;
			}
		}
		if(ans)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}