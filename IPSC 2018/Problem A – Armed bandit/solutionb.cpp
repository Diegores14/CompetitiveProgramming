#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n; 
	cin >> t;
	while(t--){
	 	cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++){
		 	cin >> v[i];
		}
		if(v[0]<10){
		 	cout << "1";
		}else{
		 	if(v[0]<100)
				cout << "10";
			else{
			 	cout << "100";
			}
		}
		for(int i=1; i<n; i++){
			if(i==n-1){
				cout << " 1";
			}else{
			 	if(v[i]<10){
				 	cout << " 1";
				}else{
		 			if(v[i]<100)
						cout << " 10";
					else{
					 	cout << " 100";
					}
				}
			}
		}
		cout << '\n';
	}
	return 0;
}