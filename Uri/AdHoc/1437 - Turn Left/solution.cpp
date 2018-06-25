#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int N,i;
	char v[4] = {'N', 'L', 'S', 'O'};
	char a;
	while(cin >> N, N){
		i=0;
	 	while(N--){
			cin >> a;
			if(a=='D')i++;
			else i--;
			if(i>=4)i=0;
			if(i<0)i=3;
		}
		cout << v[i] << '\n';
	}
	return 0;
}