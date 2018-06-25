#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n, cont;
	while(cin >> n){
		cont=0;
		vector<string> phones(n);
	 	for(int i =0; i<n; i++){
		 	cin >> phones[i];
		}
		sort(phones.begin(), phones.end());
		for(int i=1; i<n; i++){
		 	for(int j=0; j<(int)phones[i].size(); j++){
		 	 	if(phones[i][j]==phones[i-1][j])cont++;
				else break;
			}
		}
		cout << cont <<'\n';
	}
	return 0;
}