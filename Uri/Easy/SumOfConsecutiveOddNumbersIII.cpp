#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int N, x, y, sum=0, cont;
	cin >> N; 
	while(N--){
	 	cin >> x >> y;
		cont = 0;
		sum = 0;
		while(cont!=y){
		 	if(x%2){sum+=x; cont++;}
			x++;
		}
		cout << sum << '\n';
	}
	return 0;
}