#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, qt, s, answer, aux, value;
	cin >> n;
	while(n--){
	 	cin >> qt >> s;
	 	answer=1;value=-10000000;
		for(int i=1; i<=qt; i++){cin >> aux;if((aux==s || abs(aux-s)<abs(value-s)) && aux!=value){value=aux; answer=i;}}
		cout << answer << '\n';
	}
	return 0;
}