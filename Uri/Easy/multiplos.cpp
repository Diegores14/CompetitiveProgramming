#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	cout<<((b<a)? ((a%b==0)? "Sao Multiplos\n" : "Nao sao Multiplos\n"): ((b%a==0)? "Sao Multiplos\n" : "Nao sao Multiplos\n"));
	return 0;
}