#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, k, aux, answer;
	while(cin >> n >> k, n || k){
	        answer = 0;
		map<int,int> m;
		for(int i=0; i<n; i++){cin >> aux; m[aux]++;}
		for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it)
			if(it->second >= k) answer++;
		cout << answer << '\n';
	}	
	return 0;
}