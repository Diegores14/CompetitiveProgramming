#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	bool ans;
	cin >> n;
	string s;
	cin >> s;
	for(int i=2; i<=n; i++){
		for(int k=0; k+i<=n; k++){
			map<char, int> m;
			for(int j=0; j<i; j++){
				m[s[k+j]]++;
			}
			ans = true;
			for(auto to: m){
			 	if(to.second > (i>>1)){
					ans = false;
					break;
				}
			}
			if(ans){
			 	cout << "YES\n";
				for(int j=0; j<i; j++)
					cout << s[j+k];
				cout << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}