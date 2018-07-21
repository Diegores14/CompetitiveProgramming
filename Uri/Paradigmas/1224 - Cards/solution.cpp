#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<vector<long long>> m(2, vector<long long> (10002));

long long answer(vector<int> & v){
 	for(int i=1; i<(int)v.size(); i++){
 		for(int j=0; j+i<(int)v.size(); j++){
 		 	if(i%2)m[1][j]=max(v[j]+m[0][j+1],v[j+i]+m[0][j]);
 		 	else m[0][j]=min(m[1][j],m[1][j+1]);
 		}
       	}
       	return m[1][0];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	while(cin >> n){
		vector<int> v(n);
	        for(int k=0; k<n; k++)cin >> v[k];
	        if(n==2) cout << max(v[0],v[1]) << '\n';
	        else{
	        	for(int i=0; i<n; i++) m[0][i]=0;
	        	cout << answer(v) << '\n';
	        }	
	}	
	return 0;
}