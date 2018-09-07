#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q, e, aux;
	cin >> q >> e;
	set<int> s;
	for(int i=0; i<e; i++){ cin >> aux; s.insert(aux);}
	for(int i=0; i<q; i++){ cin >> aux;  cout << (s.count(aux)? 0 : 1) << '\n'; s.insert(aux);}	  
	return 0;
}