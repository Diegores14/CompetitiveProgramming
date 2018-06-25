#include <bits/stdc++.h>
using namespace std;

int main(){       
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 	int N, i;
	char c;
	vector<int> I;
	vector<int> D;
	while(cin >> N){
		I.assign(31,0);
		D.assign(31,0);
	 	while(N--){
	 	 	cin >> i >> c;
			if(c=='D')D[i-30]++;
			else I[i-30]++;
		}
		int aux = 0;
		for(i=0; i<31; i++)aux += min(I[i],D[i]);
		cout << aux << '\n';
	}
	return 0;
}