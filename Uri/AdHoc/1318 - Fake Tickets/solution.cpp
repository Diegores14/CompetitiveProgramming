#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, m,aux,answer;
	while(cin >> n >> m, n || m){
		answer = 0;
		set<int> s1;
		set<int> s;
		for(int i=0; i<m; i++){cin >> aux; if(s.count(aux) && s1.count(aux)==0){answer++;s1.insert(aux);} else s.insert(aux);}
		cout << answer << '\n';
	}
 	return 0;
}