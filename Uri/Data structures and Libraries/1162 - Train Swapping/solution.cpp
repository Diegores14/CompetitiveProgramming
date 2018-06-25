#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, l, cont;
	cin >> n;
	while(n--){
	 	cin >> l;
		cont = 0;
		vector<int> v(l);
		for(int i=0; i<l; i++)cin >> v[i];
		bool IsEnd = false;
		while(!IsEnd){
		 	IsEnd = true;
			for(int i=1; i<l; i++){
			 	if(v[i]<v[i-1]){swap(v[i],v[i-1]);cont++; IsEnd=false;}
			}
		} 
		cout << "Optimal train swapping takes " << cont << " swaps.\n";
	}
 	return 0;
}