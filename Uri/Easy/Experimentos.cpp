#include <bits/stdc++.h>
using namespace std;


int main(){
	int N, aux,total=0, v[3] = {0,0,0};
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	cin >> N;
	while(N--){
	 	cin >> aux  >> c;
		if(c == 'C')v[0]+=aux;	
		if(c == 'R')v[1]+=aux;
		if(c == 'S')v[2]+=aux;
		total += aux;
	}
	cout << "Total: " << total << " cobaias\n";
	cout << "Total de coelhos: " << v[0] << '\n';
	cout << "Total de ratos: " << v[1] << '\n';
	cout << "Total de sapos: " << v[2] << '\n';
	cout << setprecision(2) << fixed << "Percentual de coelhos: " << (double(v[0])/total)*100 << " %\n";
	cout << "Percentual de ratos: " << (double(v[1])/total)*100 << " %\n";
	cout << "Percentual de sapos: " << (double(v[2])/total)*100 << " %\n";
	return 0;
}                