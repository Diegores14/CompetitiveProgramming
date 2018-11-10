#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, l;
	string a, b;
	cin >> t;
	for(int k=1; k<=t; k++){
		long long ans=0;
	 	cout << "Case #" << k << ": ";
		cin >> l;
		cin >> a >> b;
		vector<vector<int>> prefix(26, vector<int>(l+1, 0));
		for(int i=1; i<=l; i++){
			for(int j=0; j<26; j++){
				prefix[j][i]=prefix[j][i-1];
			}
		 	prefix[b[i-1]-'A'][i]++;
		}
		for(int i=0; i<l; i++){
			vector<int> aux(26,0);
		 	for(int j=0; j+i<l; j++){
				aux[a[j+i]-'A']++;
				for(int r=1; r+j<=l; r++){
					bool aux1 = true;
					for(int x=0; x<26; x++){
						if(aux[x]>(prefix[x][r+j]-prefix[x][r-1])){
						 	aux1 = false;
							break;
						}
					
					}
					if(aux1){
					 	ans++;
						break;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}