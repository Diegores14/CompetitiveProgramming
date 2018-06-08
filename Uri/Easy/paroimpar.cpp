#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, aux;
	cin >> n;
	while(n--){
		cin >> aux;
		if(aux == 0){cout<<"NULL\n"; continue;}
		if(aux%2)cout<<"ODD ";
		else cout << "EVEN ";
		if(aux > 0)cout << "POSITIVE\n";
		else cout << "NEGATIVE\n";
	}
	return 0;
}