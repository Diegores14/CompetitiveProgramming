#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, q, aux;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	cin >> q;
	while(q--){
	 	cin >> aux;
	 	int i=-1, j=n;
	 	while(abs(j-i)!=1){
	 		int mid=abs(j+i)/2;
	 	 	if(aux>v[mid])i=mid;
	 	 	else j=mid;
	 	}
	 	if(i==-1) cout << "X ";
	 	else cout << v[i] << ' ';
	 	i=-1; j=n;
	 	while(abs(j-i)!=1){
	 		int mid=abs(j+i)/2;
	 	 	if(aux<v[mid])j=mid;
	 	 	else i=mid;
	 	}
	 	if(j==n) cout << "X\n";
	 	else cout << v[j] << '\n';
        }         
 	return 0;
}