#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	long long n, q, x, y;
	while(cin >> n, n){
		map<ii, long long> m;
		for(int i=1; i<n; i++){
		 	cin >> x >> y;
			for(int j=0; j<i; j++){   
			 	if(x<=j)m[ii(j,i)]=m[ii(x,j)]+y;
			 	else m[ii(j,i)]=m[ii(j,x)]+y;
			}
		 	m[ii(i,i)]=0;
			m[ii(x,i)]=y;
		}
		cin >> q;
		while(q--){
		 	cin >> x >> y;
		 	if(x>y)swap(x,y);
		 	cout << m[ii(x,y)] << (q? ' ': '\n');
		}
	}
	return 0;
}