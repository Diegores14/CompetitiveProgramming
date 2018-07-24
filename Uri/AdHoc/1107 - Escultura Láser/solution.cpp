#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, ant, aux, answer;
	while(cin >> a >> b, a || b){
		vector<int> v(b);
		ant = answer = 0;
		for(int i=0; i<b; i++){cin >> aux; if(ant<a-aux)answer += a-aux-ant; ant = a-aux;}
		cout << answer << '\n';
	}
	return 0;
}