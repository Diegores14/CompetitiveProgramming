#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b;
	double aux, answer;
	string s;
	cin >> n;
	cout << setprecision(2) << fixed;
	while(n--){
		map<string, double> m;
		answer = 0;
		cin >> a;
		while(a--){
			cin >> s >> aux;
			m[s]=aux;
		}
		cin >> a;
		while(a--){
		 	cin >> s >> b;
			answer += m[s]*b;
		}
		cout << "R$ " << answer << '\n';
	}
 	return 0;
}