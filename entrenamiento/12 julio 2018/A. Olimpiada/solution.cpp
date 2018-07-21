#include <bits/stdc++.h>
using namespace std;

int main(){
 	int n,aux;
	cin >> n;
	set<int> s;
	while(n--){
		cin >> aux;
		if(aux)s.insert(aux);
	}
	cout << s.size() << '\n';
	return 0;
}