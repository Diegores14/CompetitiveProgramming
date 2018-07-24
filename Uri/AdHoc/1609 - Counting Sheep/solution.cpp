#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, t, aux;
	cin >> t;
	while(t--){
	 	cin >> n;
	 	set<int> s;
	 	for(int i=0; i<n; i++){cin >> aux; s.insert(aux);}
	 	cout << s.size() << '\n';
	}
 	return 0;
}