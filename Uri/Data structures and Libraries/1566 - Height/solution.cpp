#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, p;
	cin >> n;
	while(n--){
	 	cin >> p;
		vector<int> h(p);
		for(int i=0; i<p; i++){
		 	cin >> h[i];
		}
		sort(h.begin(),h.end());
		for(int i=0; i<p-1; i++)cout << h[i] << ' ';
		cout << h[p-1] <<'\n';
	}
}	